#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <memory>
# include "iterator_traits.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public :
			typedef Iter									iterator_type;
			typedef typename Iter::value_type				value_type;
			typedef typename Iter::iterator_category		iterator_category;
			typedef typename Iter::difference_type			difference_type;
			typedef typename Iter::pointer					pointer;
			typedef typename Iter::reference				reference;

			reverse_iterator(void){}
			explicit reverse_iterator( iterator_type x ): current(x){}

			reverse_iterator( const reverse_iterator<value_type> & other )
			{
				*this = other;
			}
			reverse_iterator<Iter>& operator=( const reverse_iterator<value_type> & other )
			{
				if (this != &other)
				{
					current = other.base();
				}
				return *this;
			}
			iterator_type base() const
			{
				return current;
			}
			reference operator*() const
			{
				Iter tmp = current;
				return *--tmp;
			}
			pointer operator->() const
			{
				Iter tmp(this->current);
				tmp--;
				return (tmp.operator->());
			}
			value_type operator[]( difference_type n ) const
			{
				return base()[-n - 1];
			}
			reverse_iterator<Iter>& operator++()
			{
				--current;
				return *this;
			}
			reverse_iterator<Iter>& operator--()
			{
				++current;
				return *this;
			}
			reverse_iterator<Iter> operator++( int )
			{
				reverse_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			reverse_iterator<Iter> operator--( int )
			{
				reverse_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
			reverse_iterator<Iter> operator+( difference_type n ) const
			{
				reverse_iterator temp(current - n);
				return temp;
			}
			reverse_iterator<Iter> operator-( difference_type n ) const
			{
				reverse_iterator temp(current + n);
				return temp;
			}
			reverse_iterator<Iter>& operator+=( difference_type n )
			{
				current -= n;return (*this);
			}
			reverse_iterator<Iter>& operator-=( difference_type n )
			{
				current += n;return (*this);
			}
		
		protected :
			iterator_type current;
		
	};
	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() == rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() != rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() > rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() >= rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() < rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() <= rhs.base());
	}
	template< class Iter >
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it )
	{
		return (reverse_iterator<Iter>(it.base() - n));
	}
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs )
	{
		return (rhs.base() - lhs.base());
	}
}

#endif
