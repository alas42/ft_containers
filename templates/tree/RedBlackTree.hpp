#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include "Node.hpp"

namespace ft
{
	template <typename PAIR> // std::pair<const Key, value>
	class RedBlackTree
	{
		public:
			typedef PAIR value_type;
			typedef Node<value_type> rb_node;

		private:
			rb_node * root;

		public:
			RedBlackTree(void): root(0){}
			rb_node * getRoot(void)
			{
				return root;
			}
			
			/*
			** SEARCH / INSERT / DELETE BY VAL
			*/
			rb_node * search(value_type & val)
			{
				rb_node * temp = root;

				while (temp != 0)
				{
					if (val < temp->_value)
					{
						if (temp->_left == 0)
							break;
						else
							temp = temp->_left;
					}
					else if (val == temp->_value)
						break ;
					else
					{
						if (temp->_right == 0)
							break ;
						temp = temp->_right;
					}
				}
				return temp;
			}
			void	insert(value_type & val)
			{
				rb_node * new_node = new rb_node(val);
				if (root == 0)
				{
					new_node->_c = BLACK;
					root = new_node;
				}
				else
				{
					rb_node * temp = search(val);
					if (temp->_value == val)
						return ;
					new_node->_parent = temp;
					if (val < temp->_value)
						temp->_left = new_node;
					else
						temp->_right = new_node;
					fixRedNode(new_node);
				}
			}
			void	deleteByValue(value_type & val)
			{
				if (root == 0)
					return ;
				rb_node * nodel = search(val);
				if (nodel->_value != val)
					return ;
				deleteNode(nodel);
			}
			/*
			** Operations on Nodes
			*/
			void	leftRotate(rb_node *x)
			{
				rb_node *n_parent = x->_right;
				if (x == root)
					root = n_parent;
				x->moveDown(n_parent);
				x->_right = n_parent->_left;
				if (n_parent->_left != 0)
					n_parent->_left->_parent = x;
				n_parent->_left = x;
			}
			void	rightRotate(rb_node *x)
			{
				rb_node *n_parent = x->_left;
				if (x == root)
					root = n_parent;
				x->moveDown(n_parent);
				x->_left = n_parent->_right;
				if (n_parent->_right != 0)
					n_parent->_right->_parent = x;
				n_parent->_right = x;
			}
			void	swapColors(rb_node *x1, rb_node *x2)
			{
				ft::COLOR temp = x1->_c;
				x1->_c = x2->_c;
				x2->_c = temp;
			}
			void	swapValues(rb_node *x1, rb_node *x2)
			{
				value_type temp = x1->_value;
				x1->_value = x2->_value;
				x2->_value = x1->_value;
			}
			void	fixRedNode(rb_node *x)
			{
				if (x == root)
				{
					x->_c = BLACK;
					return ;
				}
				rb_node * parent = x->_parent, * grandparent = parent->_parent, * uncle = x->uncle();
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
			rb_node * successor(rb_node * x)
			{
				rb_node * temp = x;
				while (temp->_left != 0)
					temp = temp->_left;
				return temp;
			}
			rb_node * BRTreplace(rb_node * x)
			{
				if (x->_left == 0 && x->_right == 0)
					return 0;
				if (x->_left != 0 && x->_right != 0)
					return successor(x->_right);
				if (x->_left != 0)
					return x->_left;
				return x->_right;
			}
			void deleteNode(rb_node * x)
			{
				rb_node * replacing_node = BRTreplace(x);
				bool both_black = ((replacing_node == 0 || replacing_node == BLACK) && (x->_c == BLACK));
				rb_node * parent = x->_parent;
				if (replacing_node == 0)
				{
					if (x == root)
						root = 0;
					else
					{
						if (both_black)
							fixDoubleBlack(x);
						else
						{
							if (x->sibling() != 0)
								x->sibling()->_c = CRED;
						}
						if (x->isOnLeft())
							parent->_left = 0;
						else
							parent->_right = 0;
					}
					delete x;
					return ;
				}
				if (x->_left == 0 || x->_right == 0)
				{
					if (x == root)
					{
						x->_value = replacing_node->_value;
						x->_left = replacing_node->_right = 0;
						delete replacing_node;
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
				swapValues(replacing_node, x);
				deleteNode(replacing_node);
			}
			void	fixDoubleBlack(rb_node * x)
			{
				if (x == root)
					return ;
				rb_node * sibling = x->sibling(), * parent = x->_parent;
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
	};
}

#endif
