#ifndef bidirectionalIterator_HPP
#define bidirectionalIterator_HPP

#include "iterator_traits.hpp"
#include "../tree/RedBlackTree.hpp"

namespace ft
{
	template <typename node_type, typename T>
	class bidirectionalIterator
	{
			public:
				typedef typename ft::bidirectional_iterator_tag		iterator_category;
				typedef T											value_type;
				typedef std::ptrdiff_t								difference_type;
				typedef value_type *								pointer;
				typedef value_type &								reference;
				typedef node_type *									node_pointer;

			protected:
				node_pointer m_ptr;

			public:
				bidirectionalIterator(): m_ptr(0){}
				bidirectionalIterator(node_pointer node): m_ptr(node) {}
				bidirectionalIterator(const bidirectionalIterator & copy) {	*this = copy; }
				~bidirectionalIterator(){}
				bidirectionalIterator&	operator=(const bidirectionalIterator & copy)
				{
					if (this != &copy)
						this->m_ptr = copy.m_ptr;
					return (*this);
				}
				operator bidirectionalIterator<node_type, const T>(void) const	{ return bidirectionalIterator<node_type, const T>(this->getNode()); }
				node_pointer				getNode(void) const { return this->m_ptr; }
				reference 					operator*() const {	return this->m_ptr->_value;	}
				pointer 					operator->() const { return &(this->m_ptr->_value);	}
				bool						operator!=(const bidirectionalIterator & b)	{ return (this->m_ptr != b.m_ptr); }
				bool						operator==(const bidirectionalIterator & b)	{ return (this->m_ptr == b.m_ptr); }
				bidirectionalIterator&	operator++()
				{
					m_ptr = m_ptr->successor();
					return (*this);
				}
				bidirectionalIterator&	operator--()
				{
					m_ptr = m_ptr->predecessor();
					return (*this);
				}
				bidirectionalIterator		operator++(int)
				{
					bidirectionalIterator temp(*this);
					operator++();
					return temp;
				}
				bidirectionalIterator		operator--(int)
				{
					bidirectionalIterator temp(*this);
					operator--();
					return temp;
				}
	};
}

#endif
