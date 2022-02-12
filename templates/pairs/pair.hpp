#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template < typename T1, typename T2 >
	class pair
	{
		public :
			typedef T1 first_type;
			typedef T2 second_type;
			T1 first;
			T2 second;

			/*
			**	Constructors
			*/
			pair(void)
			{}

			pair( const T1& x, const T2& y )
			{}

			template< typename U1, typename U2 >
			pair( const pair<U1, U2>& p )
			{}

			pair(const pair&) = default;

			/*
			** Misc
			*/
			pair& operator=( const pair& other )
			{}
	};
	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u )
	{

	}
	template< typename T1, typename T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}

	template< typename T1, typename T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}

	template< typename T1, typename T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}

	template< typename T1, typename T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}

	template< typename T1, typename T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}

	template< typename T1, typename T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{}
}
#endif