#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "integral_constant.hpp"

namespace ft
{
	template< typename T >
	struct is_integral : ft::integral_constant<bool, false>{};

	template<>
	struct is_integral<bool> : ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const bool> : ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<int> : ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const int>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned int>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned int>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<long>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const long>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned long>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned long>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<short>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const short>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned short>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned short>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<char>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const char>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<unsigned char>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const unsigned char>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<float>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const float>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<double>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const double>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<long double>: ft::integral_constant<bool, true>{};

	template<>
	struct is_integral<const long double>: ft::integral_constant<bool, true>{};
}

#endif
