#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <utility>
# include <functional>

# include "../pairs/pair.hpp"
# include "../comparisons/binary_function.hpp"
# include "../tree/RedBlackTree.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/bidirectionalIterator.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

namespace ft
{

	template < typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key, T>														value_type;
			typedef std::size_t																	size_type;
			typedef std::ptrdiff_t																difference_type;
			typedef Compare																		key_compare;
			typedef Allocator																	allocator_type;
			typedef T &																			reference;
			typedef T const &																	const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef ft::bidirectionalIterator<value_type>										iterator;
			typedef ft::bidirectionalIterator<const value_type> 								const_iterator;
			typedef ft::reverse_iterator<iterator> 												reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{
				public:
					bool operator()(const value_type& left, const value_type& right) const
					{
						return (comp(left.first, right.first));
					}
					value_compare(Compare c) : comp(c){}
				protected:
					Compare comp;
			};
			/*
			** Constructors
			*/
			map(void): _compare(), _alloc(), _rbtree()
			{
				std::cout << RED << _rbtree.getRoot() << RESET << std::endl;
				value_type x5(21, 90);
				value_type x0(10, 20);
				value_type x1(20, 10);
				value_type x2(5, 60);
				value_type x3(2, 55);
				value_type x4(1, 30);

				this->insert(x5);
				this->insert(x0);
				this->insert(x1);
				this->insert(x2);
				this->insert(x3);
				this->insert(x4);
				iterator it = this->begin();
				while (it != this->end()) // end() stops before, didn't do dummy node yet (change of code)
				{
					std::cout << (*it).first << std::endl;
					it++;
				}
				iterator lb = this->lower_bound(5);
				iterator ub = this->upper_bound(5);
				std::cout << (*lb).second << "}{" << (*ub).second << std::endl;
			//	std::cout << "Is there a key 3 ? " << this->count(3) << std::endl;
				std::cout << "Is there a key 20 ? " << this->count(20) << std::endl;

				clear();
				it = this->begin();
				while (it != this->end()) // end() stops before, didn't do dummy node yet (change of code)
				{
					std::cout << (*it).first << std::endl;
					it++;
				}
			}

			map(map const & other)
			{
				*this = other;
			}

			explicit map(const Compare & comp, const Allocator & alloc = Allocator()): _compare(comp), _alloc(alloc), _rbtree()
			{}
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _compare(comp), _alloc(alloc), _rbtree()
			{
				this->insert(first, last);
			}
			/*
			** End of Constructors
			*/

			/*
			** Destructor and = operator
			*/
			~map(void)
			{
				this->clear();
			}
			map & operator = (map const & other)
			{
				if (this != &other)
				{
					this->_compare = other.key_comp();
					this->_alloc = other.get_allocator();
				}
				return (*this);
			}
			/*
			** End of destructor and = operator
			*/

			/*
			** Getter
			*/
			Allocator get_allocator() const
			{
				return this->_alloc;
			}
			/*
			** End of Getter
			*/

			/*
			** Element access
			*/
			T& at( const Key& key )
			{
				iterator	it = find(key);
				if (it != end())
					return (*it)->second;
				throw std::out_of_range("key not found");
			}
			const T& at( const Key& key ) const
			{
				const_iterator	it = find(key);
				if (it != end())
					return (*it)->second;
				throw std::out_of_range("key not found");
			}
			T& operator[]( const Key& key )
			{
				iterator	it = find(key);
				if (it != end())
					return (*it)->second;
				else
				{
					T new_second = T();
					insert(value_type(key, new_second));
					return new_second;
				}
			}
			/*
			** End of Element access
			*/

			/*
			** Iterators
			*/
			iterator begin()
			{
				ft::Node<value_type> * ptr = _rbtree.getRoot();
				return iterator(ptr->min());
			}
			const_iterator begin() const
			{
				ft::Node<const value_type> * ptr = _rbtree.getRoot();
				return const_iterator(ptr->min());
			}
			iterator end()
			{
				ft::Node<value_type> * ptr = _rbtree.getRoot();
				return iterator(ptr->max());
			}
			const_iterator end() const
			{
				ft::Node<const value_type> * ptr = _rbtree.getRoot();
				return const_iterator(ptr->max());
			}
			reverse_iterator rbegin(){ return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }
			reverse_iterator rend(){ return reverse_iterator(begin()); }
			const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }
			/*
			** End of Iterators
			*/

			/*
			** Capacity
			*/
			bool empty() const
			{
				return (begin() == end());
			}
			size_type size() const
			{
				return (std::distance(begin(), end()));
			}
			size_type max_size() const
			{
				return this->_alloc.max_size();
			}
			/*
			** End of capacity
			*/ 
			/*
			** Modifiers
			*/
			void clear()
			{
				while (begin() != end())
					this->erase(begin());
			}
			
			ft::pair<iterator, bool> insert( const value_type& value )
			{
				ft::pair<ft::Node<value_type> *, bool> inserted = this->_rbtree.insert(value);
				return (ft::pair<iterator, bool>(iterator(inserted.first), inserted.second));
			}
			iterator insert( iterator hint, const value_type& value )
			{
				(void)hint;
				return (this->insert(value).first);
			}
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}
			void erase( iterator pos )
			{
				this->_rbtree.deleteByValue(*pos);
			}
			void erase( iterator first, iterator last )
			{
				while (first != last)
				{
					erase(*first);
					first++;
				}
			}
			size_type erase( const Key& key )
			{
				iterator it = find(key);
				if (it != end())
				{
					erase(it);
					return (1);
				}
				return (0);
			}
			void swap( map& other )
			{
				map temp = other;
				other = *this;
				*this = temp;
			}
			/*
			** End of Modifiers
			*/

			/*
			** Lookup
			*/
			size_type count( const Key& key ) const
			{
				const_iterator it = lower_bound(key);
				const_iterator itend = end();
				if (it == itend)
					return 0;
				if (!this->_compare((*it).first, key) && !this->_compare(key, (*it).first))
					return (1);
				return (0);
			}
			iterator find( const Key& key )
			{
				iterator	it = begin();
				iterator	ite = end();

				while (it != ite)
				{
					if ((*it).first == key)
						return (it);
					it++;
				}
				return (ite);
			}
			const_iterator find( const Key& key ) const
			{
				const_iterator	it = begin();
				const_iterator	ite = end();

				while (it != ite)
				{
					if ((*it).first == key)
						return (it);
					it++;
				}
				return (ite);
			}
			
			std::pair<iterator,iterator> equal_range( const Key& key )
			{
				return (std::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
			}
			/*std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				return (std::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
			}*/
			iterator lower_bound( const Key& key )
			{
				Node<value_type> * node = this->_rbtree.getRoot();
				iterator it = end();
				while (node && (node->_left || node->_right))
				{
					if (this->_compare(node->_value.first, key))
						node = node->_right;
					else
					{
						it = iterator(node);
						node = node->_left;
					}
				}
				return it;
			}
			const_iterator lower_bound( const Key& key ) const
			{
				Node<const value_type> * node = this->_rbtree.getRoot();
				const_iterator it = end();
				while (node && (node->_left || node->_right))
				{
					if (this->_compare(node->_value.first, key))
						node = node->_right;
					else
					{
						it = const_iterator(node);
						node = node->_left;
					}
				}
				return it;
			}
			iterator upper_bound( const Key& key )
			{
				Node<value_type> * node = this->_rbtree.getRoot();
				iterator it = end();
				while (node && (node->_left || node->_right))
				{
					if (this->_compare(node->_value.first, key))
						node = node->_right;
					else if (this->_compare(key, node->_value.first))
					{
						it = iterator(node);
						node = node->_left;
					}
					else
					{
						node = node->_right;
					}
				}
				return it;
			}
			/*const_iterator upper_bound( const Key& key ) const
			{
				Node<value_type> * node = this->_rbtree.getRoot();
				const_iterator it = end();
				while (node && (node->_left || node->_right))
				{
					if (this->_compare(node->_value.first, key))
						node = node->_right;
					else if (this->_compare(key, node->_value.first))
					{
						it = const_iterator(node);
						node = node->_left;
					}
					else
					{
						node = node->_right;
					}
				}
				return it;
			}*/
			/*
			** End of Lookup
			*/
			/*
			** Oberservers
			*/
			key_compare key_comp() const
			{
				return this->_compare;
			}
			map::value_compare value_comp() const
			{
				return this->value_comp();
			}
			/*
			** End of Observers
			*/

		protected :
			Compare		_compare;
			Allocator	_alloc;
			ft::RedBlackTree<value_type> _rbtree;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		ft::bidirectionalIterator<ft::pair<const Key, T> > rtb = rhs.begin();
		for (ft::bidirectionalIterator<ft::pair<const Key, T> > ltb = lhs.begin(); ltb != lhs.end(); ltb++)
		{
			if (*ltb != *rtb)
				return (false);
			rtb++;
		}
		return (true);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		ft::bidirectionalIterator<ft::pair<const Key, T> > ltb = lhs.begin();
		ft::bidirectionalIterator<ft::pair<const Key, T> > rtb = rhs.begin();
		ft::bidirectionalIterator<ft::pair<const Key, T> > lte = lhs.end();
		ft::bidirectionalIterator<ft::pair<const Key, T> > rte = rhs.end();
		return (ft::lexicographical_compare(ltb, lte, rtb, rte, lhs.key_comp()));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs < rhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs <= rhs));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
	
}

#endif
