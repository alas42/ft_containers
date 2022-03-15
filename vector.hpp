#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include "lexicographical_compare.hpp"
# include "iterator_traits.hpp"
# include "randomAccessIterator.hpp"
# include "reverse_iterator.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{

		public :
			typedef T 																			value_type;
			typedef Allocator																	allocator_type;
			typedef size_t																		size_type;
			typedef std::ptrdiff_t																difference_type;
			typedef T &																			reference;
			typedef T const &																	const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef ft::random_access_iterator<T>												iterator;
			typedef ft::random_access_iterator<const T> 										const_iterator;
			typedef ft::reverse_iterator<iterator> 												reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

			vector(void): m_data(0), m_size(0), m_capacity(0), m_allocator(){}
			
			explicit vector(Allocator const & alloc): m_data(0), m_size(0), m_capacity(0), m_allocator(alloc){}

			explicit vector(size_type count, T const & value = T(), Allocator const & alloc = Allocator())
				:  m_data(0), m_size(0), m_capacity(0), m_allocator(alloc)
			{
				this->assign(count, value);
			}

			template <class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::value_type first, InputIterator last, Allocator const & alloc = Allocator())
				: m_data(0), m_size(0), m_capacity(0), m_allocator(alloc)
			{
				this->assign(first, last);
			}

			vector(vector const & other): m_data(0), m_size(0), m_capacity(0), m_allocator() { *this = other; }
			~vector(void)
			{
				this->clear();
				if (this->m_capacity > 0)
					this->m_allocator.deallocate(this->m_data, this->m_capacity);
			}

			vector & operator = (vector const & other)
			{
				if (this != &other)
					this->assign(other.begin(), other.end());
				return *this;
			}

			void assign(size_type count, value_type const & value)
			{
				try
				{
					this->clear();
					for(size_type i = 0; i < count; i++)
						this->push_back(value);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::value_type first, InputIterator last)
			{
				try
				{
					this->clear();
					while (first != last)
						this->push_back(*first++);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}

			Allocator	get_allocator() const {	return this->m_allocator; }

			/*
			** Element access
			*/
			T & at( size_type pos )
			{
				if (pos < 0 || pos >= this->m_size)
					throw std::out_of_range("No");
				return m_data[pos];
			}
			T const & at( size_type pos ) const
			{
				if (pos < 0 || pos >= this->m_size)
					throw std::out_of_range("No");
				return m_data[pos];
			}

			T & operator[]( size_type pos ) { return m_data[pos]; }
			T const & operator[]( size_type pos ) const { return m_data[pos]; }

			T & front() { return m_data[0]; }
			T const & front() const { return m_data[0]; }

			T & back() { return m_data[m_size - 1];	}
			T const & back() const { return m_data[m_size - 1]; }

			T * data() { return m_data; }
			const T * data() const { return m_data;	}

			/*
			** Iterators
			*/
			iterator begin() { return iterator(&m_data[0]);	}
			const_iterator begin() const { return const_iterator(&m_data[0]); }
			iterator end() { return iterator(&m_data[m_size]); }
			const_iterator end() const { return const_iterator(&m_data[m_size]); }
			reverse_iterator rbegin() {	return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const {	return const_reverse_iterator(end()); }
			reverse_iterator rend()	{ return reverse_iterator(begin());	}
			const_reverse_iterator rend() const	{ return const_reverse_iterator(begin()); }

			/*
			** Capacity
			*/
			bool empty() const{ return (begin() == end()); }
			size_type size() const { return this->m_size; }
			size_type max_size() const { return this->m_allocator.max_size(); }

			void reserve( size_type new_cap )
			{
				size_type power_of_two = 1;
				if (new_cap <= this->m_capacity)
					return ;
				else if (new_cap > this->max_size())
					throw std::length_error("length-error in reserve");
				try
				{
					while (power_of_two < new_cap)
						power_of_two *= 2;
					if (power_of_two > this->max_size())
						power_of_two = new_cap;
					value_type * new_data = this->m_allocator.allocate(power_of_two, 0);
					for (size_type i = 0; i < this->m_size; i++)
					{
						this->m_allocator.construct(&new_data[i], this->m_data[i]);
						this->m_allocator.destroy(&this->m_data[i]);
					}
					if (this->m_data != 0 && this->m_capacity > 0)
						this->m_allocator.deallocate(m_data, this->m_capacity);
					this->m_data = new_data;
					this->m_capacity = power_of_two;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			size_type capacity() const { return this->m_capacity; }

			/*
			** Modifiers
			*/
			void clear()
			{
				for (size_type i = 0; i < this->m_size; i++)
					this->m_allocator.destroy(&m_data[i]);
				this->m_size = 0;
			}

			iterator insert( iterator pos, T const & value )
			{
				insert(pos, (size_type)1, value);
				return pos;
			}

			void insert( iterator pos, size_type count, T const & value )
			{
				size_type offset = pos - this->begin();
				this->reserve(this->m_size + count);
				for (size_type i = this->m_size - 1; i >= offset; i--)
				{
					if (i > this->m_size)
						break;
					this->m_allocator.construct(&this->m_data[i + count], this->m_data[i]);
					this->m_allocator.destroy(&m_data[i]);
				}
				for(size_type i = offset; i < offset + count; i++)
					this->m_allocator.construct(&this->m_data[i], value);
				this->m_size += count;
			}

			template <class InputIterator>
			void		insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::value_type first, InputIterator last)
			{
				size_type offset = position - this->begin();
				size_type count = last - first;
				this->reserve(this->m_size + count);
				for (size_type i = this->m_size - 1; i >= offset; i--)
				{
					if (i > this->m_size)
						break;
					this->m_allocator.construct(&this->m_data[i + count], this->m_data[i]);
					this->m_allocator.destroy(&m_data[i]);
				}
				for(size_type i = offset; i < offset + count; i++)
					this->m_allocator.construct(&this->m_data[i], *first++);
				this->m_size += count;
			}

			iterator erase( iterator pos )
			{
				try
				{
					return (erase(pos, pos + 1));
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			iterator erase( iterator first, iterator last )
			{
				iterator i = end();
				size_type deleted = last - first;
				size_type offset = first - this->begin();
				size_type n = 0;
				try
				{
					if (last != end())
						i = last + 1;
					while (last + n != end())
					{
						this->m_allocator.destroy(&this->m_data[offset + n]);
						this->m_allocator.construct(&this->m_data[offset + n], *(last + n));
						n++;
					}
					for (size_type c = 1; c <= deleted; c++)
						this->m_allocator.destroy(&this->m_data[this->m_size - c]);
					this->m_size -= deleted;
					return (i);
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			void push_back( T const & value )
			{
				try
				{
					
					if (this->m_size == this->m_capacity)
						this->reserve(!this->m_capacity ? 1 : this->m_capacity * 2);
					this->m_allocator.construct(&this->m_data[this->m_size], value);
					this->m_size++;
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}				
			}

			void pop_back()
			{
				try
				{
					this->m_allocator.destroy(&(m_data[this->m_size - 1]));
					this->m_size--;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			void resize( size_type count, T value = T() )
			{
				try
				{
					if (count > this->m_capacity)
						this->reserve(count);
					else if (count < this->m_size)
					{
						for (size_t i = count; i < this->m_size ; i++)
							this->m_allocator.destroy(&this->m_data[i]);
					}
					for (size_type i = this->m_size; i < count; i++)
						this->m_allocator.construct(&this->m_data[i], value);
					this->m_size = count;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			void swap( vector & other )
			{
				value_type * tmp = other.data();
				size_type size_tmp = other.size();
				size_type capacity_tmp = other.capacity();
				other.m_data = this->m_data;
				other.m_size = this->m_size;
				other.m_capacity = this->m_capacity;
				this->m_data = tmp;
				this->m_size = size_tmp;
				this->m_capacity = capacity_tmp;
			}

		protected:
			value_type *					m_data;
			size_type						m_size;
			size_type						m_capacity;
			Allocator						m_allocator;
	};

	template <typename T>
	void swap (ft::vector<T> & x, ft::vector<T> & y) { x.swap(y); }
	template <typename T>
	bool operator==( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		ft::random_access_iterator<const T> rtb = rhs.begin();
		for (ft::random_access_iterator<const T> ltb = lhs.begin(); ltb != lhs.end(); ltb++)
		{
			if (*ltb != *rtb)
				return (false);
			rtb++;
		}
		return (true);
	}
	template <typename T>
	bool operator!=( const ft::vector<T> & lhs, const ft::vector<T> & rhs ) { return (!(lhs == rhs)); }
	template <typename T>
	bool operator<( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		ft::random_access_iterator<const T> ltb = lhs.begin();
		ft::random_access_iterator<const T> rtb = rhs.begin();
		ft::random_access_iterator<const T> lte = lhs.end();
		ft::random_access_iterator<const T> rte = rhs.end();
		return (ft::lexicographical_compare(ltb, lte, rtb, rte));
	}
	template <typename T>
	bool operator<=( const ft::vector<T> & lhs, const ft::vector<T> & rhs ) { return (lhs == rhs || lhs < rhs); }
	template <typename T>
	bool operator>( const ft::vector<T> & lhs, const ft::vector<T> & rhs ) { return (!(lhs <= rhs)); }
	template <typename T>
	bool operator>=( const ft::vector<T> & lhs, const ft::vector<T> & rhs )	{ return (!(lhs < rhs)); }
}

#endif
