#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include "Node.hpp"
# include <iostream>
# include <string>

namespace ft
{
	template <typename T, typename Compare, typename Allocator>
	class RedBlackTree
	{
		public:
			typedef T value_type;
			typedef Compare key_compare;
			typedef Node<value_type> rb_node;
			typedef typename Allocator:: template rebind<rb_node>::other	alloc_node;

		protected:
			Compare		_compare;
			rb_node *	_root;
			rb_node *	_after_end;
			alloc_node	_alloc;

		public:
			RedBlackTree(void): _compare(), _alloc()
			{
				/*
				_after_end = _alloc.allocate(1, 0);
				_alloc.construct(_after_end, rb_node());
				*/
				_after_end = new rb_node();
				_root = _after_end;
			}
			RedBlackTree(RedBlackTree const & other) { *this = other; }
			~RedBlackTree(void)
			{
				_root = _after_end;
				if (_after_end)
				{
					delete _after_end;
					/*
					_alloc.destroy(_after_end);
					_alloc.deallocate(_after_end, 1);
					*/
				}
			}
			RedBlackTree operator=(RedBlackTree const & other)
			{
				if (this == &other)
				{
					this->_compare = other._compare;
					this->_alloc = other._alloc;
				}
				return *this;
			}
			rb_node * getRoot(void) const{ return _root; }
			rb_node * search(value_type const & val)
			{
				rb_node * temp = _root;
				while (temp != 0 && temp != _after_end)
				{
					if (_compare(val.first, temp->_value.first))
					{
						if (temp->_left == 0)
							break;
						else
							temp = temp->_left;
					}
					else if ((!_compare(val.first, temp->_value.first) && !_compare(temp->_value.first, val.first)))
						break ;
					else
					{
						if (temp->_right == 0 || temp->_right == _after_end)
							break ;
						temp = temp->_right;
					}
				}
				return temp;
			}
			ft::pair<rb_node *, bool>	insert(const value_type & val)
			{
				rb_node * new_node = new rb_node(val);
				rb_node * before_end = 0;
				if (_root == _after_end)
				{
					new_node->_c = BLACK;
					_root = new_node;
					_root->_right = _after_end;
					_after_end->_parent = _root;
				}
				else
				{
					rb_node * temp = search(val);
					if ((!_compare(val.first, temp->_value.first) && !_compare(temp->_value.first, val.first)))
					{
						delete new_node;
						return ft::pair<rb_node *, bool>(temp, false);
					}
					before_end = _after_end->_parent;
					before_end->_right = 0;
					_after_end->_parent = 0;
					new_node->_parent = temp;
					if (_compare(val.first, temp->_value.first))
						temp->_left = new_node;
					else
						temp->_right = new_node;
					fixRedNode(new_node);
					before_end = max(_root);
					before_end->_right = _after_end;
					_after_end->_parent = before_end;
				}
				return ft::pair<rb_node *, bool>(new_node, true);
			}
			void	deleteByValue(value_type const & val)
			{
				rb_node * before_end = 0;
				if (_root == _after_end)
					return ;
				rb_node * nodel = search(val);
				if (nodel->_value != val)
					return ;
				std::cout << "root before deletion :" << _root << ", value : " << _root->_value.first << "\n" << std::endl;
				
				before_end = _after_end->_parent;
				before_end->_right = 0;
				_after_end->_parent = 0;
				deleteNode(nodel);
				
				if (_root != 0 && _root != _after_end)
				{
					before_end = max(_root);
					before_end->_right = _after_end;
					_after_end->_parent = before_end;
				}
				
				std::cout << "root after deletion :" << _root << ", value : " << _root->_value.first << "\n" << std::endl;
			}

			void deleteNode(rb_node * x)
			{
				rb_node * replacing_node = findReplacement(x);
				std::cout << "node x to delete : " << x << ", value : " << x->_value.first << std::endl;
				if (replacing_node)
					std::cout << "replacing_node = " << replacing_node << ", value : " << replacing_node->_value.first << std::endl;
				else
					std::cout << "replacing_node = " << replacing_node << std::endl;
				bool both_black = ((replacing_node == 0 || replacing_node->_c == BLACK) && (x->_c == BLACK));
				rb_node * parent = x->_parent;
				if (replacing_node == 0)
				{
					if (x == _root)
						_root = _after_end;
					else
					{
						if (both_black)
							fixDoubleBlack(x);
						else
						{
							if (sibling(x) != 0)
								sibling(x)->_c = CRED;
						}
						if (x->isOnLeft())
							parent->_left = 0;
						else
							parent->_right = 0;
					}

					std::cout << "delete " << x << ", value : " << x->_value.first << std::endl; 
					delete x;
					return ;
				}
				if (x->_left == 0 || x->_right == 0)
				{
					if (x == _root)
					{
						this->_root = replacing_node;
						this->_root->_right = this->_root->_left = 0;
						std::cout << "delete " << x << ", value : " << x->_value.first << std::endl; 
						delete x;
					}
					else
					{
						if (x->isOnLeft())
							parent->_left = replacing_node;
						else
							parent->_right = replacing_node;
						delete x;
						
						replacing_node->_parent = parent;
						if (both_black)
							fixDoubleBlack(replacing_node);
						else
							replacing_node->_c = BLACK;
					}
					return ;
				}
				swapNodes(&replacing_node, &x);
				std::cout << "x->_left = " << x->_left << ", x->_right = " << x->_right << ", x->_parent = " << x->_parent << std::endl;
				deleteNode(x);
			}

			/*
			** SWAPINGS
			*/
			void	swapNodes(rb_node **x1, rb_node **x2)
			{
				rb_node *tmp = *x2;
				*x2 = *x1;
				*x1 = tmp;
			}
			void	swapColors(rb_node *x1, rb_node *x2)
			{
				ft::COLOR temp = x1->_c;
				x1->_c = x2->_c;
				x2->_c = temp;
			}

			/*
			** Lookup
			*/
			rb_node *uncle(rb_node *x)
			{
				if (x->_parent == 0 || x->_parent->_parent == 0)
					return 0;
				if (x->_parent->isOnLeft())
					return x->_parent->_parent->_right;
				return x->_parent->_parent->_left;
			}
			rb_node *sibling(rb_node *x)
			{
				if (x == 0 || x->_parent == 0)
					return 0;
				if(x->isOnLeft())
					return x->_parent->_right;
				return x->_parent->_left;
			}

			/*
			** Modifiers 
			*/
			void	moveDown(rb_node *x, rb_node *n_parent)
			{
				if (x->_parent != 0)
				{
					if (x->isOnLeft())
						x->_parent->_left = n_parent;
					else
						x->_parent->_right = n_parent;
				}
				n_parent->_parent = x->_parent;
				x->_parent = n_parent; 
			}
			void	leftRotate(rb_node *x)
			{
				rb_node * n_parent = x->_right;
				if (x == _root)
					_root = n_parent;
				moveDown(x, n_parent);
				x->_right = n_parent->_left;
				if (n_parent->_left != 0)
					n_parent->_left->_parent = x;
				n_parent->_left = x;
			}
			void	rightRotate(rb_node *x)
			{
				rb_node * n_parent = x->_left;
				if (x == _root)
					_root = n_parent;
				moveDown(x, n_parent);
				x->_left = n_parent->_right;
				if (n_parent->_right != 0)
					n_parent->_right->_parent = x;
				n_parent->_right = x;
			}

			void	fixDoubleBlack(rb_node * x)
			{
				if (x == _root)
					return ;
				rb_node * sibling = this->sibling(x), * parent = x->_parent;
				if (sibling == 0)
					fixDoubleBlack(parent);
				else
				{
					if (sibling->_c == CRED)
					{
						parent->_c = CRED;
						sibling->_c = BLACK;
						if (sibling->isOnLeft())
							rightRotate(parent);
						else
							leftRotate(parent);
						fixDoubleBlack(x);
					}
					else
					{
						if (sibling->hasRedChild())
						{
							if (sibling->_left != 0 && sibling->_left->_c == CRED)
							{
								if (sibling->isOnLeft())
								{
									sibling->_left->_c = sibling->_c;
									sibling->_c = parent->_c;
									rightRotate(parent);
								}
								else
								{
									sibling->_left->_c = parent->_c;
									rightRotate(sibling);
									leftRotate(parent);
								}
							}
							else
							{
								if (sibling->isOnLeft())
								{
									sibling->_right->_c = parent->_c;
									leftRotate(sibling);
									rightRotate(parent);
								}
								else
								{
									sibling->_right->_c = sibling->_c;
									sibling->_c = parent->_c;
									leftRotate(parent);
								}
							}
							parent->_c = BLACK;
						}
						else
						{
							sibling->_c = CRED;
							if (parent->_c == BLACK)
								fixDoubleBlack(parent);
							else
								parent->_c = BLACK;
						}
					}
				}
			}
			void	fixRedNode(rb_node *x)
			{
				if (x == _root)
				{
					x->_c = BLACK;
					return ;
				}
				rb_node * parent = x->_parent, * grandparent = parent->_parent, * uncle = this->uncle(x);
				if (parent->_c != BLACK)
				{
					if (uncle != 0 && uncle->_c == CRED)
					{
						uncle->_c = parent->_c = BLACK;
						grandparent->_c = CRED;
						fixRedNode(grandparent);
					}
					else
					{
						if (parent->isOnLeft())
						{
							if (x->isOnLeft())
								swapColors(parent, grandparent);
							else
							{
								leftRotate(parent);
								swapColors(x, grandparent);
							}
							rightRotate(grandparent);
						}
						else
						{
							if (x->isOnLeft())
							{
								rightRotate(parent);
								swapColors(x, grandparent);
							}
							else
								swapColors(parent, grandparent);
							leftRotate(grandparent);
						}
					}
				}
			}
			rb_node * successor_for_deletion(rb_node * x)
			{
				rb_node * temp = x;
				while (temp->_left != 0)
					temp = temp->_left;
				return temp;
			}
			rb_node * findReplacement(rb_node * x)
			{
				if (x->_left == 0 && x->_right == 0)
					return 0;
				if (x->_left != 0 && x->_right != 0)
					return successor_for_deletion(x->_right);
				if (x->_left != 0)
					return x->_left;
				return x->_right;
			}
	};
}

#endif
