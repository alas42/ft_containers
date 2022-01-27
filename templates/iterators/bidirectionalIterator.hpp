#ifndef bidirectionalIterator_HPP
#define bidirectionalIterator_HPP

#include "iterator_traits.hpp"

namespace ft
{

	template <typename T>
	class bidirectionalIterator
	{
			public:
				typedef typename ft::bidirectional_iterator_tag	iterator_category;
				typedef T										value_type;
				typedef std::ptrdiff_t							difference_type;
				typedef T *										pointer;
				typedef T &										reference;
			
			public:
				bidirectionalIterator(): m_ptr(0){}
				bidirectionalIterator(pointer ptr): m_ptr(ptr){}
				bidirectionalIterator(const bidirectionalIterator<T> & copy){*this = copy;}
				~bidirectionalIterator(){}

				bidirectionalIterator<T>&	operator=(pointer ptr)
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
				bool						operator!=(const bidirectionalIterator<T> & b)
				{
					return (this->m_ptr != b.m_ptr);
				}
				bool						operator==(const bidirectionalIterator<T> & b)
				{
					return (this->m_ptr == b.m_ptr);
				}
				bidirectionalIterator<T>&	operator++(){++m_ptr;return (*this);}
				bidirectionalIterator<T>&	operator--(){--m_ptr;return (*this);}

				bidirectionalIterator<T>		operator++(int)
				{
					bidirectionalIterator temp(*this);
					++m_ptr;
					return temp;
				}
				bidirectionalIterator<T>		operator--(int)
				{
					bidirectionalIterator temp(*this);
					--m_ptr;
					return temp;
				}

			protected:
				pointer	m_ptr;
	};
}

#endif
