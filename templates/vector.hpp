#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

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
			typedef T 										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::size_type			size_type;
			typedef typename Allocator::difference_type		difference_type;
			typedef T & 									reference;
			typedef T const &								const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename std::iterator<std::random_access_iterator_tag, value_type>	iterator;
			typedef typename std::iterator<std::random_access_iterator_tag, const value_type> const_iterator;
			typedef std::reverse_iterator<iterator> 		reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			/*
			** Constructors
			*/
			vector(void)
			{
				std::cout << GREEN << "A vector(void) has been created" << RESET << std::endl;
			}
			
			explicit vector(Allocator const & alloc)
			{
				(void)alloc;
				std::cout << GREEN << "A vector(alloc) has been created" << RESET << std::endl;
			}
			explicit vector(size_type count, T const & value, Allocator const & alloc = Allocator())
			{
				(void)alloc;
				(void)count;
				(void)value;
				std::cout << GREEN << "A vector(count, value, alloc) has been created" << RESET << std::endl;
			}

			template < typename InputIt>
			vector(InputIt first, InputIt last, Allocator const & alloc = Allocator())
			{
				(void)alloc;
				(void)first;
				(void)last;
				std::cout << GREEN << "A vector(first, last, alloc) has been created" << RESET << std::endl;
			}

			vector(vector const & other)
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
			}
			vector & operator = (vector const & other)
			{
				if (this != &other)
				{
					std::cout << MAGENTA << "vector Assignation called" << RESET << std::endl;
				}
				return *this;
			}
			/*
			** End of Destructor and = operator
			*/

			/*
			** Misc
			*/
			void assign(size_type count, value_type const & value);

			template< class InputIt >
			void assign(InputIt first, InputIt last);
			/*
			** End of Misc

			*/
			/*
			** Guetters and setters
			*/
			Allocator	get_allocator() const;
			/*
			** End of Guetters and setters
			*/

			/*
			** Element access
			*/
			T & at( size_type pos );
			T const & at( size_type pos ) const;
			T & operator[]( size_type pos );
			T const & operator[]( size_type pos ) const;
			T & front();
			T const & front() const;
			T & back();
			T const & back() const;
			T* data();
			const T* data() const;
			/*
			** End of Element access
			*/

			/*
			** Iterators WICHTIG
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
			** End ITERATORS
			*/

			/*
			** Capacity
			*/
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void reserve( size_type new_cap );
			size_type capacity() const;
			/*
			** End of capacity
			*/

			/*
			** Modifiers
			*/
			void clear();
			iterator insert( iterator pos, T const & value );
			void insert( iterator pos, size_type count, T const & value );
			template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last );
			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );
			void push_back( T const & value )
			{
				(void)value;
			}
			void pop_back();
			void resize( size_type count );
			void resize( size_type count, T value = T() );
			void swap( vector & other )
			{
				(void)other;
			}
			/*
			** End of modifiers
			*/
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
