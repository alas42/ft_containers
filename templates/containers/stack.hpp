#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template < typename T, typename Container = ft::vector<T> >
	class stack
	{
		public :
			typedef	Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;	
			typedef typename Container::const_reference const_reference;

			/*
			** Canonical Form
			*/
			explicit stack( const Container& cont = Container() )
			{
				this->C(cont);
			}
			~stack(void)
			{
				this->~C();
			}
			stack & operator = (stack const & other)
			{
				if (this != &other)
				{
					this->C = other.C;
				}
				return *this;
			}

			/*
			** Misc
			*/
			reference top() { return (this->C.back()); }
			const_reference top() const { return (this->C.back()); }
			bool empty() const { return (this->C.empty()); }
			size_type size() const { return (this->C.size()); }
			void push( const value_type& value ) { this->C.push_back(value); }
			void pop() { this->C.pop_back(); }

		protected :
			container_type	C;
	};
	
	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.C == rhs.C);
	}

	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.C < rhs.C);
	}

	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs < rhs || lhs == rhs);
	}

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.C > rhs.C);
	}

	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs > rhs || lhs == rhs);
	}
}

#endif
