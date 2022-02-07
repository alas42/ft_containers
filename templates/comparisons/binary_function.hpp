#ifndef BINARY_FUNCTION_HPP
#define BINARY_FUNCTION_HPP

namespace ft
{
    template < typename T >
    struct binary_function
    {
        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;
    };
}

#endif