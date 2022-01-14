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
				randomAccessIterator(T * ptr = 0){m_ptr = ptr;}
				randomAccessIterator(const randomAccessIterator<T>& copy){m_ptr = copy.m_ptr;}
				~randomAccessIterator(){}

				randomAccessIterator<T>&	operator=(T * ptr)
				{
					m_ptr = ptr;
					return (*this);
				}
				randomAccessIterator<T>&                  operator+=(const difference_type& movement){m_ptr += movement;return (*this);}
				randomAccessIterator<T>&                  operator-=(const difference_type& movement){m_ptr -= movement;return (*this);}
				randomAccessIterator<T>&                  operator++(){++m_ptr;return (*this);}
				randomAccessIterator<T>&                  operator--(){--m_ptr;return (*this);}
				randomAccessIterator<T>                   operator++(int)
				{
					T * temp = *this;
					++m_ptr;
					return temp;
				}
				randomAccessIterator<T>                  operator--(int)
				{
					T * temp = *this ;
					--m_ptr;
					return temp;
				}
				
				randomAccessIterator<T>                  operator+(const difference_type& movement)
				{
					T * oldPtr = m_ptr;
					m_ptr += movement;
					T * temp = *this;
					m_ptr = oldPtr;
					return temp;
				}
				randomAccessIterator<T>                   operator-(const difference_type & movement)
				{
					T * oldPtr = m_ptr;
					m_ptr -= movement;
					T * temp = *this;
					m_ptr = oldPtr;
					return temp;
				}

				difference_type                             operator-(const randomAccessIterator<T>& rawIterator){return std::distance(rawIterator.getPtr(),this->getPtr());}
			
				T *                                 getPtr()const{return m_ptr;}
				const T *                           getConstPtr()const{return m_ptr;}

			private:
				T *	m_ptr;
	};

}

#endif
