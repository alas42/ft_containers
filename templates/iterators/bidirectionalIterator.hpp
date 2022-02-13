#ifndef bidirectionalIterator_HPP
#define bidirectionalIterator_HPP

#include "iterator_traits.hpp"
/*
** Cannot go wrong with that, am I ?
*/
#include "../tree/RedBlackTree.hpp"

namespace ft
{
	template <typename PAIR>
	class bidirectionalIterator
	{
			public:
				typedef typename ft::bidirectional_iterator_tag		iterator_category;
				typedef PAIR										value_type;
				typedef std::ptrdiff_t								difference_type;
				typedef value_type *								pointer;
				typedef value_type &								reference;

			public:
				bidirectionalIterator(): m_ptr2(0){}
				bidirectionalIterator(const bidirectionalIterator<value_type> & copy)
				{
					*this = copy;
				}
				~bidirectionalIterator(){}
				bidirectionalIterator<value_type>&	operator=(const bidirectionalIterator<value_type> & copy)
				{
					if (this != &copy)
					{
						/*
						** when begin() or something like that is called, 
						** here I could take the pointer to the node and add it.
						*/
						this->m_ptr2 = copy.m_ptr2;
					}
					return (*this);
				}
				reference 					operator*() const
				{
					return this->m_ptr2->_value;
				}
				pointer 					operator->() const
				{
					return &(this->m_ptr2->_value);
				}
				bool						operator!=(const bidirectionalIterator<value_type> & b)
				{
					return (this->m_ptr2 != b.m_ptr2);
				}
				bool						operator==(const bidirectionalIterator<value_type> & b)
				{
					return (this->m_ptr2== b.m_ptr2);
				}
				bidirectionalIterator<value_type>&	operator++()
				{
					m_ptr2 = m_ptr2->successor();
					return (*this);
				}
				bidirectionalIterator<value_type>&	operator--()
				{
					m_ptr2 = m_ptr2->predecessor();
					return (*this);
				}
				bidirectionalIterator<value_type>		operator++(int)
				{
					bidirectionalIterator temp(*this);
					operator++();
					return temp;
				}
				bidirectionalIterator<value_type>		operator--(int)
				{
					bidirectionalIterator temp(*this);
					operator--();
					return temp;
				}

			protected:
				typedef ft::Node<value_type> * node_pointer;
				node_pointer m_ptr2;
	};
}

#endif
