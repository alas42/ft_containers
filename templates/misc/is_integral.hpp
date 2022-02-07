#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "integral_constant.hpp"

namespace ft
{
	template< class T >
	struct is_integral : ft::integral_constant<T, true>
	{};
}

#endif
