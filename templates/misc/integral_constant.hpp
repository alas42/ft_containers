#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

namespace ft
{
	template< class T, T v >
	struct integral_constant
	{
        static const T value = v;
        typedef T value_type;
        typedef ft::integral_constant<T, v> type;

        operator value_type() const
        {
            return value;
        }
	};
}

#endif
