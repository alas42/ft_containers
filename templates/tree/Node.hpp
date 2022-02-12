#ifndef NODE_HPP
# define NODE_HPP


namespace ft
{
	enum COLOR {CRED, BLACK};

	template <typename T> // std::pair<const Key, value>
	class Node
	{
		public:
			typedef T value_type;
	
		public:
			COLOR _c;
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
				if (_parent == 0)
					return 0;
				if(isOnLeft())
					return _parent->right;
				else
					return _parent->left;
			}
			void	moveDown(Node *n_parent)
			{
				if (_parent != 0)
				{
					if (isOnLeft())
						_parent->_left = n_parent;
					else
						_parent->right = n_parent;
				}
				n_parent->_parent = _parent;
				_parent = n_parent; 
			}
			bool hasRedChild(void)
			{
				return ((_left != 0 && _left->_c == CRED) || (_right != 0 && _right->_c == CRED));
			}
	};

}


#endif
