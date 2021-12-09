#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

template <typename T, typename Allocator = std::allocator<T> >
class Vector
{
	//typedef typename std::stack<T>::container_type::iterator iterator;
	public :
		T 										value_type;
		Allocator								allocator_type;
		std::size_t								size_type;
		std::ptrdiff_t							difference_type;
		T & 									reference;
		T const &								const_reference;
		typename Allocator::pointer				pointer;
		//std::reverse_iterator<iterator> 		reverse_iterator;
		//std::const_reverse_iterator<const_iterator>	const_reverse_iterator;

		/*
		** Constructors
		*/
		Vector(void){ std::cout << GREEN << "A vector has been created" << RESET << std::endl; }
		explicit Vector(Allocator const & alloc):
			allocator_type(alloc){ std::cout << GREEN << "A vector has been created" << RESET << std::endl; }
		explicit Vector(size_t count, T const & value, Allocator const & alloc = Allocator()):
			
		{
			std::cout << GREEN << "A vector has been created" << RESET << std::endl;
		}
		
		template < typename InputIt>
		Vector(InputIt first, InputIt last, Allocator const & alloc = Allocator())
		{
			std::cout << GREEN << "A vector has been created" << RESET << std::endl;
		}

		Vector(Vector const & other)
		{
			std::cout << GREEN << "A vector has been created" << RESET << std::endl;
			*this = other;
		}
		/*
		** End of Constructors
		*/

		/*
		** Destructor and = operator
		*/
		~Vector(void)
		{
			std::cout << RED << "A vector has been destroyed" << RESET << std::endl;
		}
		Vector & operator = (Vector const & other)
		{
			if (this != &other)
			{
				std::cout << MAGENTA << "Vector Assignation called" << RESET << std::endl;
			}
			return *this;
		}
		/*
		** End of Destructor and = operator
		*/

		/*
		** Misc
		*/
		void assign(size_t count, T const & value);

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
		T & at( size_t pos );
		T const & at( size_t pos ) const;
		T & operator[]( size_t pos );
		T const & operator[]( size_t pos ) const;
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
		size_t size() const;
		size_t max_size() const;
		void reserve( size_t new_cap );
		size_t capacity() const;
		/*
		** End of capacity
		*/

		/*
		** Modifiers
		*/
		void clear();
		iterator insert( iterator pos, T const & value );
		void insert( iterator pos, size_t count, T const & value );
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		void push_back( T const & value );
		void pop_back();
		void resize( size_t count );
		void resize( size_t count, T value = T() );
		void swap( Vector & other );
		/*
		** End of modifiers
		*/

};

/*
template <class T, class Alloc>
void swap (ft::Vector<T, Alloc> & x, ft::Vector<T,A lloc> & y);
template< class T, class Alloc >
bool operator==( const ft::Vector<T,Alloc> & lhs, const ft::Vector<T,Alloc> & rhs );
template< class T, class Alloc >
bool operator!=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
template< class T, class Alloc >
template< class T, class Alloc >
bool operator<( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
bool operator<=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
template< class T, class Alloc >
bool operator>( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
template< class T, class Alloc >
bool operator>=( const std::vector<T,Alloc> & lhs, const std::vector<T,Alloc> & rhs );
*/

#endif
