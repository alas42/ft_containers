#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include "../iterators/iterator_traits.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/randomAccessIterator.hpp"
# include "../misc/is_integral.hpp"
# include "../misc/enable_if.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"


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
			typedef typename ft::randomAccessIterator<value_type>								iterator;
			typedef typename ft::randomAccessIterator<const value_type> 						const_iterator;
			typedef ft::reverse_iterator<iterator> 												reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;

			/*
			** Constructors
			*/
			vector(void): m_data(0), m_size(0), m_capacity(0)
			{}
			
			explicit vector(Allocator const & alloc): m_data(0), m_size(0), m_capacity(0)
			{
				this->m_allocator = alloc;
			}

			explicit vector(size_type count, T const & value, Allocator const & alloc = Allocator())
				:  m_data(0), m_size(count), m_capacity(count)
			{
				this->m_allocator = alloc;
				try
				{
					m_data = this->m_allocator.allocate(count, m_data);
					for(size_type i = 0; i < this->m_size; i++)
						this->m_allocator.construct(&m_data[i], value);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw;
				}
			}

			template < typename InputIt>
			vector(InputIt first, InputIt last, Allocator const & alloc = Allocator())
				: m_data(0), m_size(0), m_capacity(0) 
			{
				this->m_allocator = alloc;
				this->m_size = std::distance(first, last);
				this->m_capacity = m_size;
				std::uninitialized_copy(first, last, this->m_data);
			}

			vector(vector const & other): m_data(0), m_size(0), m_capacity(0)
			{
				*this = other;
			}
			/*
			** End of Constructors
			*/

			/*
			** Destructor and = operator
			*/
			~vector(void)
			{
				this->clear();
				this->m_allocator.deallocate(m_data, this->m_capacity);
			}

			vector & operator = (vector const & other)
			{
				if (this != &other)
				{
					for (size_type i = 0; i < this->m_size; i++)
						this->m_allocator.destroy(&m_data[0]);
					this->m_allocator.deallocate(m_data, this->m_capacity);
					this->m_size = other.size();
					this->m_capacity = other.capacity();
					try
					{
						this->m_data = this->m_allocator.allocate(this->m_capacity, this->m_data);
						for(size_type i = 0; i < this->m_size; i++)
							this->m_allocator.construct(&this->m_data[i], other.m_data[i]);
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						throw ("=");
					}
				}
				return *this;
			}
			/*
			** End of Destructor and = operator
			*/

			/*
			** Misc
			*/
			void assign(size_type count, value_type const & value)
			{
				try
				{
					erase(begin(), end());
					insert(begin(), count, value);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw ("assign");
				}
			}

			template< class InputIt >
			void assign(InputIt first, InputIt last)
			{
				try
				{
					erase(begin(), end());
					insert(begin(), first, last);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw ("assign");
				}
			}
			/*
			** End of Misc

			*/
			/*
			** Guetters and setters
			*/
			Allocator	get_allocator() const
			{
				return this->m_allocator;
			}
			/*
			** End of Guetters and setters
			*/

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

			T & operator[]( size_type pos )
			{
				return m_data[pos];
			}
			T const & operator[]( size_type pos ) const
			{
				return m_data[pos];
			}

			T & front()
			{
				return m_data[0];
			}
			T const & front() const
			{
				return m_data[0];
			}

			T & back()
			{
				return m_data[m_size - 1];
			}
			T const & back() const
			{
				return m_data[m_size - 1];
			}

			T * data()
			{
				return m_data;
			}
			const T * data() const
			{
				return m_data;
			}
			/*
			** End of Element access
			*/

			/*
			** Iterators WICHTIG
			*/
			iterator begin()
			{
				return iterator(&m_data[0]);
			}
			const_iterator begin() const
			{
				return const_iterator(&m_data[0]);
			}

			iterator end()
			{
				return iterator(&m_data[m_size]);
			}
			const_iterator end() const
			{
				return const_iterator(&m_data[m_size]);
			}
			reverse_iterator rbegin()
			{
				return reverse_iterator(&m_data[m_size - 1]);
			}
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(&m_data[m_size - 1]);
			}

			reverse_iterator rend()
			{
				return reverse_iterator(&m_data[-1]);
			}
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(&m_data[-1]);
			}
			/*
			** End ITERATORS
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
				return this->m_size;
			}

			size_type max_size() const
			{
				return this->m_allocator.max_size();
			}

			void reserve( size_type new_cap )
			{
				size_type power_of_two = 2;
				if (new_cap <= this->m_capacity)
					return ;
				else if (new_cap > max_size())
					throw std::length_error("length-error in reserve");
				try
				{
					while (power_of_two < new_cap && power_of_two < max_size())
						power_of_two *= 2;
					allocator_type alloc;
					value_type * new_data = alloc.allocate(power_of_two, 0);
					for (size_type i = 0; i < this->size(); i++)
					{
						alloc.construct(&new_data[i], this->m_data[i]);
						alloc.destroy(&this->m_data[i]);
					}
					alloc.deallocate(m_data, this->m_capacity);
					this->m_data = new_data;
					this->m_capacity = power_of_two;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw ("reserve");
				}
			}

			size_type capacity() const
			{
				return this->m_capacity;
			}
			/*
			** End of capacity
			*/

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
				Allocator alloc;
				
				for (size_type i = this->size(); i >= offset; i--)
				{
					alloc.construct(&this->m_data[i + count], this->m_data[i]);
					alloc.destroy(&this->m_data[i]);
					if (i == 0)
						break ;
				}
				for (size_type i = 0; i < count; i++)
				{
					alloc.destroy(&this->m_data[offset + i]);
					alloc.construct(&this->m_data[offset + i], value);
				}
				this->m_size += count;
			}

			template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last )
			{
				size_type offset = pos - this->begin();
				size_type count = last - first;
				this->reserve(this->m_size + count);

				for (size_type i = this->size(); i >= offset; i--)
				{
					this->m_allocator.construct(&this->m_data[i + count], this->m_data[i]);
					this->m_allocator.destroy(&this->m_data[i]);
					if (i == 0)
						break ;
				}
				for (size_type i = 0; i < count; i++)
				{
					this->m_allocator.destroy(&this->m_data[offset + i]);
					this->m_allocator.construct(&this->m_data[offset + i], *(first + i));
				}
				this->m_size += count;
			}

			iterator erase( iterator pos )
			{
				try
				{
					~*pos();
					this->left_shift(pos);
					this->m_size--;
					return (iterator(&(m_data[pos + 1])));
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw ("erase");
				}
			}

			iterator erase( iterator first, iterator last )
			{
				iterator i;
				try
				{
					if (first == last)
						throw ("no-op");
					if (last == end())
						i = end();
					else
						i = last + 1;
					while (first != last)
					{
						this->m_allocator.destroy(&(*first));
						first++;
						this->m_size--;
					}
					return (i);
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what() << '\n';
					throw ("erase it2");
				}
			}

			void push_back( T const & value )
			{
				try
				{
					if (this->m_size == this->m_capacity)
						this->reserve(m_size + 1);
					this->m_data[this->m_size] = value;
					this->m_size++;
				}
				catch(const std::exception & e)
				{
					std::cerr << e.what() << '\n';
					throw ("push_back");
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
					throw ("pop_back");
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
						{
							this->m_allocator.destroy(&this->m_data[i]);
						}
					}
					for (size_type i = this->m_size; i < count; i++)
					{
						this->m_allocator.construct(&this->m_data[i], value);
					}
					this->m_size = count;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					throw ("resize");
				}
			}

			void swap( vector & other )
			{
				vector tmp(*this);
				*this = other;
				other = tmp;
			}
			/*
			** End of modifiers
			*/

		protected:
			value_type *					m_data;
			size_type						m_size;
			size_type						m_capacity;
			Allocator						m_allocator;

		private:
			void left_shift(iterator position)
			{
				while (position != end())
				{
					position = position + 1;
					position++;
				}
			}
	};

	template <typename T>
	void swap (ft::vector<T> & x, ft::vector<T> & y)
	{
		x.swap(y);
	}
	template <typename T>
	bool operator==( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		ft::randomAccessIterator<const T> rtb = rhs.begin();
		for (ft::randomAccessIterator<const T> ltb = lhs.begin(); ltb != lhs.end(); ltb++)
		{
			if (*ltb != *rtb)
				return (false);
			rtb++;
		}
		return (true);
	}
	template <typename T>
	bool operator!=( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		return (!(lhs == rhs));
	}
	template <typename T>
	bool operator<( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		ft::randomAccessIterator<const T> ltb = lhs.begin();
		ft::randomAccessIterator<const T> rtb = rhs.begin();
		ft::randomAccessIterator<const T> lte = lhs.end();
		ft::randomAccessIterator<const T> rte = rhs.end();
		return (std::lexicographical_compare(ltb, lte, rtb, rte));
	}
	template <typename T>
	bool operator<=( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		return (lhs < rhs || lhs < rhs);
	}
	template <typename T>
	bool operator>( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		return (!(lhs < rhs));
	}
	template <typename T>
	bool operator>=( const ft::vector<T> & lhs, const ft::vector<T> & rhs )
	{
		return (lhs > rhs || lhs == rhs);
	}

}

#endif
