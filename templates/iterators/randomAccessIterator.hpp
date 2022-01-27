#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename T>
	class randomAccessIterator
	{
			public:
				typedef typename ft::random_access_iterator_tag	iterator_category;
				typedef T										value_type;
				typedef std::ptrdiff_t							difference_type;
				typedef T *										pointer;
				typedef T &										reference;
			
			public:
				randomAccessIterator(): m_ptr(0){}
				randomAccessIterator(pointer ptr): m_ptr(ptr){}
				randomAccessIterator(const randomAccessIterator<T> & copy){*this = copy;}
				~randomAccessIterator(){}

				randomAccessIterator<T>&	operator=(pointer ptr)
				{
					m_ptr = ptr;
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
				bool						operator!=(const randomAccessIterator<T> & b)
				{
					return (this->m_ptr != b.m_ptr);
				}
				bool						operator==(const randomAccessIterator<T> & b)
				{
					return (this->m_ptr == b.m_ptr);
				}
				randomAccessIterator<T>&	operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
				randomAccessIterator<T>&	operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
				randomAccessIterator<T>&	operator++(){++m_ptr;return (*this);}
				randomAccessIterator<T>&	operator--(){--m_ptr;return (*this);}

				randomAccessIterator<T>		operator++(int)
				{
					randomAccessIterator temp(*this);
					++m_ptr;
					return temp;
				}
				randomAccessIterator<T>		operator--(int)
				{
					randomAccessIterator temp(*this);
					--m_ptr;
					return temp;
				}
				
				randomAccessIterator<T>		operator+(const difference_type& movement)
				{
					randomAccessIterator temp(m_ptr + movement);
					return temp;
				}
				randomAccessIterator<T>		operator-(const difference_type & movement)
				{
					randomAccessIterator temp(m_ptr - movement);
					return temp;
				}

				difference_type				operator-(const randomAccessIterator<T>& rawIterator)
				{
					return std::distance(rawIterator.m_ptr, m_ptr);
				}

				reference operator[](difference_type count) const
				{
					return (*(this->m_ptr + count));
				}

			protected:
				pointer	m_ptr;
	};
	template <typename T>
	bool operator<(const randomAccessIterator<T> & a, const randomAccessIterator<T> & b)
	{
		return (a.m_ptr < b.m_ptr);
	}
	template <typename T>
	bool operator>(const randomAccessIterator<T> & a, const randomAccessIterator<T> & b)
	{
		return (a.m_ptr > b.m_ptr);
	}
	template <typename T>
	bool operator<=(const randomAccessIterator<T> & a, const randomAccessIterator<T> & b)
	{
		return (a.m_ptr <= b.m_ptr);
	}
	template <typename T>
	bool operator>=(const randomAccessIterator<T> & a, const randomAccessIterator<T> & b)
	{
		return (a.m_ptr >= b.m_ptr);
	}

}

#endif
