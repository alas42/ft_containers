#ifndef NODE_HPP
# define NODE_HPP


namespace ft
{
	enum COLOR {CRED, BLACK};

	template <typename PAIR> // std::pair<const Key, value>
	class Node
	{
		public:
			typedef PAIR value_type;
	
		public:
			COLOR _c;
			/*
			** left and right are the children of the parent -> one is the node itself the other one its sibling
			*/
			Node *_parent, *_left, *_right;
			value_type  _value;

		public:
			Node(value_type & value): _value(value)
			{
				_parent = _left = _right = 0;
				_c = CRED;
			}
			Node *uncle(void)
			{
				if (_parent == 0 || _parent->_parent == 0)
					return 0;
				if (_parent->isOnLeft())
					return _parent->_parent->_right;
				else
					return _parent->_parent->_left;
			}
			bool isOnLeft(void)
			{
				return this == _parent->_left;
			}
			Node *sibling(void)
			{
				if (this == 0 || _parent == 0)
					return 0;
				if(isOnLeft())
					return _parent->_right;
				else
					return _parent->_left;
			}
			void	moveDown(Node *n_parent)
			{
				if (_parent != 0)
				{
					if (isOnLeft())
						_parent->_left = n_parent;
					else
						_parent->_right = n_parent;
				}
				n_parent->_parent = _parent;
				_parent = n_parent; 
			}
			bool hasRedChild(void)
			{
				return ((_left != 0 && _left->_c == CRED) || (_right != 0 && _right->_c == CRED));
			}
			Node * max(void)
			{
				if (_right == 0)
					return this;
				return _right->max();
			}
			Node * min(void)
			{
				if (_left == 0)
					return this;
				return _left->min();
			}
			Node * predecessor(void)
			{
				if (this != 0)
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
				return 0;
			}
			Node * successor(void)
			{
				if (this != 0)
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
				return 0;
			}
	};
}


#endif
