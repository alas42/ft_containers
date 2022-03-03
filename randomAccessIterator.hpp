#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template <typename T>
	class random_access_iterator
	{
			public:
				typedef T								value_type;
				typedef std::random_access_iterator_tag	iterator_category;
				typedef std::ptrdiff_t					difference_type;
				typedef T *								pointer;
				typedef T &								reference;

			public:
				random_access_iterator(): m_ptr(0){}
				random_access_iterator(pointer ptr): m_ptr(ptr){}
				random_access_iterator(const random_access_iterator & copy){*this = copy;}
				~random_access_iterator(){}
				operator random_access_iterator<const T>(void) const	{ return random_access_iterator<const T>(this->operator->()); }
				random_access_iterator&	operator=(const random_access_iterator& copy)
				{
					if (this != &copy)
					{
						this->m_ptr = copy.m_ptr;
					}
					return (*this);
				}
				reference 					operator*() const
				{
					return *this->m_ptr;
				}
				pointer 					operator->() const
				{
					return this->m_ptr;
				}
				bool						operator!=(const random_access_iterator & b)
				{
					return (this->m_ptr != b.m_ptr);
				}
				bool						operator==(const random_access_iterator & b)
				{
					return (this->m_ptr == b.m_ptr);
				}
				random_access_iterator&	operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
				random_access_iterator&	operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
				random_access_iterator&	operator++(){++m_ptr;return (*this);}
				random_access_iterator&	operator--(){--m_ptr;return (*this);}

				random_access_iterator		operator++(int)
				{
					random_access_iterator temp(*this);
					++m_ptr;
					return temp;
				}
				random_access_iterator		operator--(int)
				{
					random_access_iterator temp(*this);
					--m_ptr;
					return temp;
				}
				
				random_access_iterator		operator+(const difference_type& movement) const
				{
					random_access_iterator temp(m_ptr + movement);
					return temp;
				}
				random_access_iterator		operator-(const difference_type & movement) const
				{
					random_access_iterator temp(m_ptr - movement);
					return temp;
				}

				difference_type				operator-(const random_access_iterator& rawIterator) const
				{
					return std::distance(rawIterator.m_ptr, m_ptr);
				}

				reference operator[](difference_type count) const
				{
					return (*(this->m_ptr + count));
				}

			public:
				pointer	m_ptr;
	};
	template <typename T>
	bool operator<(const random_access_iterator<T> & a, const random_access_iterator<T> & b)
	{
		return (a.m_ptr < b.m_ptr);
	}
	template <typename T>
	bool operator>(const random_access_iterator<T> & a, const random_access_iterator<T> & b)
	{
		return (a.m_ptr > b.m_ptr);
	}
	template <typename T>
	bool operator<=(const random_access_iterator<T> & a, const random_access_iterator<T> & b)
	{
		return (a.m_ptr <= b.m_ptr);
	}
	template <typename T>
	bool operator>=(const random_access_iterator<T> & a, const random_access_iterator<T> & b)
	{
		return (a.m_ptr >= b.m_ptr);
	}

}

#endif
