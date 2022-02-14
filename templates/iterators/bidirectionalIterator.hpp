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
		/*
		** I modified nothing public, the iterator does return a std::pair<> pointer
		** and not the complete node, I hope I am correct in my assumptions
		*/
			public:
				typedef typename ft::bidirectional_iterator_tag		iterator_category;
				typedef PAIR										value_type;
				typedef std::ptrdiff_t								difference_type;
				typedef value_type *								pointer;
				typedef value_type &								reference;

			protected:
				typedef ft::Node<value_type> * node_pointer;
				node_pointer m_ptr;

			public:
				bidirectionalIterator(): m_ptr(0){}
				bidirectionalIterator(node_pointer node)
				{
					m_ptr = node;
				}
				bidirectionalIterator(const bidirectionalIterator<value_type> & copy)
				{
					*this = copy;
				}
				~bidirectionalIterator(){}
				bidirectionalIterator<value_type>&	operator=(const bidirectionalIterator<value_type> & copy)
				{
					if (this != &copy)
					{
						this->m_ptr = copy.m_ptr;
					}
					return (*this);
				}
				reference 					operator*() const
				{
					return this->m_ptr->_value;
				}
				pointer 					operator->() const
				{
					return &(this->m_ptr->_value);
				}
				bool						operator!=(const bidirectionalIterator<value_type> & b)
				{
					return (this->m_ptr != b.m_ptr);
				}
				bool						operator==(const bidirectionalIterator<value_type> & b)
				{
					return (this->m_ptr == b.m_ptr);
				}
				bidirectionalIterator<value_type>&	operator++()
				{
					m_ptr = m_ptr->successor();
					return (*this);
				}
				bidirectionalIterator<value_type>&	operator--()
				{
					m_ptr = m_ptr->predecessor();
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
	};
}

#endif
