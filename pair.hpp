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
			pair(void): first(), second()
			{}

			pair( const T1& x, const T2& y ): first(x), second(y)
			{}

			template< typename U1, typename U2 >
			pair( const pair<U1, U2>& p ): first(p.first), second(p.second)
			{}
			/*
			** Misc
			*/
			pair& operator=( const pair& other )
			{
				if (this != &other)
				{
					first = other.first;
					second = other.second;
				}
				return *this;
			}
	};
	template< typename T1, typename T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< typename T1, typename T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< typename T1, typename T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first == rhs.second && lhs.second < lhs.second)
			return true;
		return false;
	}

	template< typename T1, typename T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs == rhs || lhs < rhs);
	}

	template< typename T1, typename T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(lhs <= rhs));
	}

	template< typename T1, typename T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair( T1 t, T2 u )
	{
		return (ft::pair<T1, T2>(t, u));
	}
}
#endif