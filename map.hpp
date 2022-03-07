#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include <utility>
# include <functional>

# include "pair.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "binary_function.hpp"
# include "RedBlackTree.hpp"
# include "reverse_iterator.hpp"
# include "bidirectionalIterator.hpp"
# include "lexicographical_compare.hpp"

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
			typedef ft::bidirectionalIterator<ft::Node<value_type>, value_type >				iterator;
			typedef ft::bidirectionalIterator<ft::Node<value_type>, value_type > 				const_iterator;
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

			map(void): _compare(), _alloc(), _rbtree(){}
			map(map const & other) { *this = other;	}
			explicit map(const Compare & comp, const Allocator & alloc = Allocator()): _compare(comp), _alloc(alloc), _rbtree(){}
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _compare(comp), _alloc(alloc), _rbtree()
			{
				this->insert(first, last);
			}

			~map(void)
			{
				this->clear();
			}

			map & operator = (map const & other)
			{
				if (this != &other)
				{
					this->clear();
					this->_compare = other.key_comp();
					this->_alloc = other.get_allocator();
					this->insert(other.begin(), other.end());
				}
				return (*this);
			}

			Allocator get_allocator() const { return this->_alloc; }


			/*
			** Element access
			*/
			T& at( const Key& key )
			{
				iterator	it = this->find(key);

				if (it != this->end())
					return (*it).second;
				throw std::out_of_range("key not found");
			}
			const T& at( const Key& key ) const
			{
				const_iterator	it = this->find(key);

				if (it != this->end())
					return (*it).second;
				throw std::out_of_range("key not found");
			}
			T& operator[]( const Key& key ){ return (insert(ft::make_pair(key, T())).first->second); }

			/*
			** Iterators
			*/
			iterator begin() { return iterator(min(this->_rbtree.getRoot())); }
			iterator end() { return iterator(max(this->_rbtree.getRoot()));	}
			const_iterator begin() const { return const_iterator(min(this->_rbtree.getRoot()));}
			const_iterator end() const { return const_iterator(max(this->_rbtree.getRoot())); }
			reverse_iterator rbegin(){ return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const{ return const_reverse_iterator(end()); }
			reverse_iterator rend(){ return reverse_iterator(begin()); }
			const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }

			/*
			** Capacity
			*/
			bool empty() const { return (this->begin() == this->end()); }
			size_type size() const { return (std::distance(this->begin(), this->end()));}
			size_type max_size() const { return this->_alloc.max_size(); }

			/*
			** Modifiers
			*/
			void clear()
			{
				while (this->begin() != this->end())
				{
					this->erase(this->begin());
				}
			}
			
			ft::pair<iterator, bool> insert( const value_type& value )
			{
				ft::pair<ft::Node<value_type> *, bool> inserted = this->_rbtree.insert(value);
				return (ft::make_pair(iterator(inserted.first), inserted.second));
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
					this->insert(*first++);
			}

			void erase( iterator pos ) { this->_rbtree.deleteByValue(*pos); }
			void erase( iterator first, iterator last )
			{
				while (first != last)
					this->erase(first++);
			}
			size_type erase( const Key& key )
			{
				iterator it = this->find(key);

				if (it != this->end())
				{
					this->erase(it);
					return (1);
				}
				return (0);
			}

			void swap( map& other )
			{
				ft::RedBlackTree<value_type, key_compare, Allocator> tree_tmp = other._rbtree;
				other._rbtree = this->_rbtree;
				this->_rbtree = tree_tmp;
			}
			/*
			** End of Modifiers
			*/

			/*
			** Lookup
			*/
			size_type count( const Key& key ) const
			{
				const_iterator it = this->lower_bound(key);
				const_iterator itend = this->end();

				if (it == itend)
					return (0);
				if (!this->_compare((*it).first, key) && !this->_compare(key, (*it).first))
					return (1);
				return (0);
			}
			iterator find( const Key& key )
			{
				iterator	it = this->begin();
				iterator	ite = this->end();

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
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite)
				{
					if ((*it).first == key)
						return (it);
					it++;
				}
				return (ite);
			}
			
			ft::pair<iterator,iterator> equal_range( const Key& key ) { return (ft::pair<iterator, iterator>(this->lower_bound(key), this->upper_bound(key))); }
			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const { return (ft::pair<const_iterator, const_iterator>(this->lower_bound(key), this->upper_bound(key))); }
			iterator lower_bound(const Key & key)
			{
				iterator	it = this->begin();
				iterator	ite = this->end();

				while (it != ite)
				{
					if (!this->_compare((*it).first, key) && !this->_compare(key, (*it).first))
						return (it);
					else if (this->_compare(key, (*it).first))
						return (it);
					it++;
				}
				return (ite);
			}
			const_iterator lower_bound( const Key& key ) const
			{
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite)
				{
					if (!this->_compare((*it).first, key) && !this->_compare(key, (*it).first))
						return (it);
					else if (this->_compare(key, (*it).first))
						return (it);
					it++;
				}
				return (ite);
			}
			iterator upper_bound( const Key& key )
			{
				iterator	it = this->begin();
				iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_compare(key, (*it).first))
						return (it);
					it++;
				}
				return (ite);
			}
			const_iterator upper_bound( const Key& key ) const
			{
				const_iterator	it = this->begin();
				const_iterator	ite = this->end();

				while (it != ite)
				{
					if (this->_compare(key, (*it).first))
						return (it);
					it++;
				}
				return (ite);
			}

			/*
			** Oberservers
			*/
			key_compare key_comp() const { return this->_compare; }
			map::value_compare value_comp() const {	return this->value_comp(); }

		protected :
			Compare		_compare;
			Allocator	_alloc;
			ft::RedBlackTree<value_type, key_compare, Allocator> _rbtree;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){ return (rhs < lhs); }
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs < rhs)); }

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ) { lhs.swap(rhs); }
}

#endif
