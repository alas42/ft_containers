#ifndef BINARY_FUNCTION_HPP
#define BINARY_FUNCTION_HPP

namespace ft
{
    template < typename Arg1, typename Arg2, class Result >
    struct binary_function
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
}

#endif