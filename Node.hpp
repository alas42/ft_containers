#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	enum COLOR {CRED, BLACK};

	template <typename T>
	class Node
	{
		public:
			T  				_value;
			Node			*_parent, *_left, *_right;
			COLOR			_c;

		public:
			Node(void): _value(), _parent(0), _left(0), _right(0), _c(CRED){}
			Node(T const & value): _value(value)
			{
				_parent = _left = _right = 0;
				_c = CRED;
			}
			Node(Node const & other): _value(other._value), _parent(other._parent), _left(other._left), _right(other._right), _c(other._c){}
			Node operator=(Node const & other)
			{
				if (this != &other)
				{
					_value = other._value;
					_c = other._c;
					_parent = other._parent;
					_left = other._left;
					_right = other._right;
				}
				return *this;
			}
			bool isOnLeft(void) { return this == _parent->_left; }
			bool hasRedChild(void) { return ((_left != 0 && _left->_c == CRED) || (_right != 0 && _right->_c == CRED));	}
			Node * max(void) { return (_right == 0 ? this :	_right->max()); }
			Node * min(void) { return (_left == 0 ? this : _left->min()); }
			Node * predecessor(void)
			{
				if (_left != 0)
					return (_left->max());
				if (!isOnLeft())
					return _parent;
				Node * pred_node = this;
				for (; pred_node != 0 && pred_node->isOnLeft(); pred_node = pred_node->_parent);
				if (pred_node != 0)
					return pred_node->_parent;
				return 0;
			}
			Node * successor(void)
			{
				if (_right != 0)
					return (_right->min());
				if (isOnLeft())
					return _parent;
				Node * succ_node = this;
				for (; succ_node != 0 && !succ_node->isOnLeft(); succ_node = succ_node->_parent);
				if (succ_node != 0)
					return succ_node->_parent;
				return 0;
			}
	};
	template <typename PAIR>
	Node<PAIR> * max(Node<PAIR> * node) { return (node->_right == 0 ? node : max(node->_right)); }
	template <typename PAIR>
	Node<PAIR> * min(Node<PAIR> * node) { return (node->_left == 0 ? node : min(node->_left)); }
}

#endif
