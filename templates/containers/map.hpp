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
			map(void): _compare(), _alloc(), _rbtree(), _size(0)
			{
				std::cout << RED << _rbtree.getRoot() << RESET << std::endl;
				value_type x5(21, 90);
				value_type x0(10, 20); // it stops here because first inserted equals to root node
				value_type x1(20, 10);
				value_type x2(5, 90);
				value_type x3(2, 90);
				value_type x4(1, 90);

				_rbtree.insert(x5);
				_rbtree.insert(x0);
				_rbtree.insert(x1);
				_rbtree.insert(x2);
				_rbtree.insert(x3);
				_rbtree.insert(x4);
				_size += 6;
				iterator it = this->begin();
				while (it != this->end())
				{
					std::cout << (*it).first << std::endl;
					it++;
				}
			}

			map(map const & other)
			{
				*this = other;
			}

			explicit map(const Compare & comp, const Allocator & alloc = Allocator()): _compare(comp), _alloc(alloc)
			{}
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _compare(comp), _alloc(alloc)
			{
				(void)first;
				(void)last;
			}
			/*
			** End of Constructors
			*/

			/*
			** Destructor and = operator
			*/
			~map(void)
			{

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
					//insert(new_second);
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
				ft::Node<value_type> * ptr = _rbtree.getRoot();
				return const_iterator(ptr->min());
			}
			iterator end()
			{
				ft::Node<value_type> * ptr = _rbtree.getRoot();
				return iterator(ptr->max());
			}
			const_iterator end() const
			{
				ft::Node<value_type> * ptr = _rbtree.getRoot();
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
												**      F5CK, I need to use compare and stuff and not parcouring it like a vector
												**		I need to start at the root and from there compare and choose a branch
												**		AAAH, I'm dumb
												*/ 
			/*
			** Modifiers
			*/
			void clear()
			{

			}
			/*
			std::pair<iterator, bool> insert( const value_type& value )
			{
				
			}
			iterator insert( iterator hint, const value_type& value )
			{

			}*/
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				(void)first;
				(void)last;
			}
			void erase( iterator pos )
			{
				if (pos == end())
					return;
			}
			void erase( iterator first, iterator last )
			{
				(void)first;
				(void)last;
			}
			size_type erase( const Key& key )
			{
				(void)key;
			}
			void swap( map& other )
			{
				(void)other;
			}
			/*
			** End of Modifiers
			*/

			/*
			** Lookup
			*/
			size_type count( const Key& key ) const
			{
				iterator	it = begin();
				iterator	ite = end();
				size_type	i = 0;

				while (it != ite)
				{
					if ((*it).first == key)
						i++;
					it++;
				}
				return i;
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
			/*
			std::pair<iterator,iterator> equal_range( const Key& key )
			{
				(void)key;
			}
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				(void)key;
			}
			iterator lower_bound( const Key& key )
			{
				(void)key;
			}
			const_iterator lower_bound( const Key& key ) const
			{
				(void)key;
			}
			iterator upper_bound( const Key& key )
			{
				(void)key;
			}
			const_iterator upper_bound( const Key& key ) const
			{
				(void)key;
			}
			
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

			}
			/*
			** End of Observers
			*/

		protected :
			Compare		_compare;
			Allocator	_alloc;
			ft::RedBlackTree<value_type> _rbtree;
			size_type	_size;
	};
	/*
	** This comparison will either compare two redblacktrees that has to implement these methods
	** OR just do it here thank the iterators. If so..
	*/
/*
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{

	}

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs )
	{

	}
	*/
}

#endif
