#ifndef map_HPP
# define map_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

/*
** It has a member class, whatever that means (maybe like an exception ?)
*/

namespace ft
{

	template < typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public :
			Key						key_type;
			T						mapped_type;
			std::pair<const key, T>	value_type;
			std::size_t				size_type;
			std::ptrdiff_t			difference_type;
			Compare					key_compare;
			Allocator				allocator_type;
			T &						reference;
			T const &				const_reference;
			typename Allocator::pointer	pointer;
			typename Allocator::const_pointer	const_pointer;
			//iterator
			//const_iterator
			//std::reverse_iterator<iterator> 		reverse_iterator;
			//std::const_reverse_iterator<const_iterator>	const_reverse_iterator;


			/*
			** Constructors
			*/
			map(void);
			map(map const & other);
			explicit map(const Compare & comp, const Allocator & alloc = Allocator());
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			/*
			** End of Constructors
			*/

			/*
			** Destructor and = operator
			*/
			~map(void);
			map & operator = (map const & other);
			/*
			** End of destructor and = operator
			*/

			/*
			** Getter
			*/
			Allocator get_allocator() const;
			/*
			** End of Getter
			*/

			/*
			** Element access
			*/
			T& at( const Key& key );
			const T& at( const Key& key ) const;
			T& operator[]( const Key& key );
			/*
			** End of Element access
			*/

			/*
			** Iterators
			*/
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
			/*
			** End of Iterators
			*/

			/*
			** Capacity
			*/
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			/*
			** End of capacity
			*/

			/*
			** Modifiers
			*/
			void clear();
			std::pair<iterator, bool> insert( const value_type& value );
			iterator insert( iterator hint, const value_type& value );
			template< class InputIt >
			void insert( InputIt first, InputIt last );
			void erase( iterator pos );
			void erase( iterator first, iterator last );
			size_type erase( const Key& key );
			void swap( map& other );
			/*
			** End of Modifiers
			*/

			/*
			** Lookup
			*/
			size_type count( const Key& key ) const;
			iterator find( const Key& key );
			const_iterator find( const Key& key ) const;
			std::pair<iterator,iterator> equal_range( const Key& key );
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			iterator lower_bound( const Key& key );
			const_iterator lower_bound( const Key& key ) const;
			iterator upper_bound( const Key& key );
			const_iterator upper_bound( const Key& key ) const;
			/*
			** End of Lookup
			*/

			/*
			** Oberservers
			*/
			key_compare key_comp() const;
			map::value_compare value_comp() const;
			/*
			** End of Observers
			*/
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs );
}
#endif
