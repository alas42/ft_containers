#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <utility>
# include <functional>

# include "../tree/RedBlackTree.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/bidirectionalIterator.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

namespace ft
{

	template < typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{

		public :
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef std::pair<const Key, T>														value_type;
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
			map(void): _ptr(0){}

			map(map const & other)
			{
				*this = other;
			}

			explicit map(const Compare & comp, const Allocator & alloc = Allocator()): _compare(comp), _alloc(alloc), _ptr(0);
			{}
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _compare(comp), _alloc(alloc), _ptr(0)
			{

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

			}
			const T& at( const Key& key ) const
			{

			}
			T& operator[]( const Key& key )
			{

			}
			/*
			** End of Element access
			*/

			/*
			** Iterators
			*/
			iterator begin()
			{

			}
			const_iterator begin() const
			{

			}
			iterator end()
			{

			}
			const_iterator end() const
			{

			}
			reverse_iterator rbegin(){}
			const_reverse_iterator rbegin() const{}
			reverse_iterator rend(){}
			const_reverse_iterator rend() const{}
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

			}
			std::pair<iterator, bool> insert( const value_type& value ) //if the container doesn't already contain an element with an equivalent key.
			{

			}
			iterator insert( iterator hint, const value_type& value ) //if the container doesn't already contain an element with an equivalent key.
			{

			}
			template< class InputIt >
			void insert( InputIt first, InputIt last ) //if the container doesn't already contain an element with an equivalent key.
			{

			}
			void erase( iterator pos )
			{
				if (pos == end())
					return;
			}
			void erase( iterator first, iterator last ) //Removes the elements in the range [first; last), which must be a valid range in *this.
			{

			}
			size_type erase( const Key& key )
			{

			}
			void swap( map& other )
			{

			}
			/*
			** End of Modifiers
			*/

			/*
			** Lookup
			*/
			size_type count( const Key& key ) const
			{

			}
			iterator find( const Key& key )
			{

			}
			const_iterator find( const Key& key ) const
			{

			}
			std::pair<iterator,iterator> equal_range( const Key& key )
			{

			}
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{

			}
			iterator lower_bound( const Key& key )
			{

			}
			const_iterator lower_bound( const Key& key ) const
			{

			}
			iterator upper_bound( const Key& key )
			{

			}
			const_iterator upper_bound( const Key& key ) const
			{

			}
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

			}
			/*
			** End of Observers
			*/

		protected :
			Compare		_compare;
			Allocator	_alloc;
			pointer		_ptr;
	};

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
}

#endif
