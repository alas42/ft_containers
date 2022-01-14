#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterator_traits.hpp"
# include "randomAccessIterator.hpp"

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"


namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		/*
			protected:
				value_type *					m_data;
				size_type						m_size;
				size_type						m_capacity;
				Allocator						m_allocator;
		*/
		public :
			typedef T 																			value_type;
			typedef Allocator																	allocator_type;
			typedef typename Allocator::size_type												size_type;
			typedef typename Allocator::difference_type											difference_type;
			typedef T &																			reference;
			typedef T const &																	const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef typename ft::randomAccessIterator<value_type>			iterator;
			typedef typename ft::randomAccessIterator<const value_type> 	const_iterator;
			typedef std::reverse_iterator<iterator> 											reverse_iterator;
			typedef std::reverse_iterator<const_iterator>										const_reverse_iterator;

			/*
			** Constructors
			*/
			vector(void): m_data(0), m_size(0), m_capacity(0)
			{
				std::cout << GREEN << "A vector(void) has been created" << RESET << std::endl;
			}
			
			explicit vector(Allocator const & alloc): m_data(0), m_size(0), m_capacity(0)
			{
				std::cout << GREEN << "A vector(alloc) has been created" << RESET << std::endl;
				this->m_allocator = alloc;
			}

			explicit vector(size_type count, T const & value, Allocator const & alloc = Allocator())
				:  m_data(0), m_size(count), m_capacity(count)
			{
				std::cout << GREEN << "A vector(count, value, alloc) has been created" << RESET << std::endl;
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
				std::cout << GREEN << "A vector(first, last, alloc) has been created" << RESET << std::endl;
				this->m_allocator = alloc;
				this->m_size = std::distance(first, last);
				this->m_capacity = m_size;
				std::uninitialized_copy(first, last, this->m_data);
			}

			vector(vector const & other): m_data(0), m_size(0), m_capacity(0)
			{
				std::cout << GREEN << "A vector(other) has been created" << RESET << std::endl;
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
				std::cout << RED << "A vector has been destroyed" << RESET << std::endl;
				for (size_type i = 0; i < this->m_size; i++)
					this->m_allocator.destroy(&m_data[0]);
				this->m_allocator.deallocate(m_data, this->m_capacity);
			}

			vector & operator = (vector const & other)
			{
				std::cout << MAGENTA << "vector Assignation called" << RESET << std::endl;
				if (this != &other)
				{
					for (size_type i = 0; i < this->m_size; i++)
						this->m_allocator.destroy(&m_data[0]);
					this->m_allocator.deallocate(m_data, this->m_capacity);
					this->m_size = other.m_size;
					this->m_capacity = other.m_capacity;
					try
					{
						this->m_data = this->m_allocator.allocate(this->m_capacity, this->m_data);
						for(size_type i = 0; i < this->m_size; i++)
							this->m_allocator.construct(&this->m_data[i], other.m_data[i]);
					}
					catch(const std::exception& e)
					{
						std::cerr << e.what() << '\n';
						throw;
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
				(void)count;
				(void)value;
			}

			template< class InputIt >
			void assign(InputIt first, InputIt last)
			{
				(void)first;
				(void)last;
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

			T* data()
			{
				return m_data;
			}
			const T* data() const
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
				(void)new_cap;
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
					this->m_allocator.destroy(&m_data[0]);
				this->m_size = 0;
			}

			iterator insert( iterator pos, T const & value )
			{
				(void)pos;
				(void)value;
			}
			void insert( iterator pos, size_type count, T const & value )
			{
				(void)pos;
				(void)count;
				(void)value;
			}
			template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last )
			{
				(void)pos;
				(void)first;
				(void)last;
			}

			iterator erase( iterator pos )
			{
				(void)pos;
			}
			iterator erase( iterator first, iterator last )
			{
				(void)first;
				(void)last;
			}

			void push_back( T const & value )
			{
				(void)value;
			}

			void pop_back()
			{

			}

			void resize( size_type count )
			{
				(void)count;
			}
			void resize( size_type count, T value = T() )
			{
				(void)count;
				(void)value;
			}

			void swap( vector & other )
			{
				(void)other;
			}
			/*
			** End of modifiers
			*/

		protected:
			value_type *					m_data;
			size_type						m_size;
			size_type						m_capacity;
			Allocator						m_allocator;
	};

/*			**** SOMETHING WITH FRIEND KEYWORD ****							
	template <typename T, typename Allocator>
	void swap (ft::vector<T, Alloc> & x, ft::vector<T, Alloc> & y);
	bool operator==( const ft::vector<T,Alloc> & lhs, const ft::vector<T,Alloc> & rhs );
	bool operator!=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
	bool operator<( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
	bool operator<=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
	bool operator>( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
	bool operator>=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
*/
}

#endif
