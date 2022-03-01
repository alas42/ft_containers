#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
	struct bidirectional_iterator_tag{};
	struct random_access_iterator_tag : public ft::bidirectional_iterator_tag{};

	template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::iterator_category iterator_category;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
	};
}

#endif
