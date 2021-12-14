#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>

namespace ft
{
	template< typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T& >
	struct iterator
	{
		public:
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;

	};
}

#endif
