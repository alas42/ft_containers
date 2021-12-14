#ifndef STACK_HPP
# define STACK_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

namespace ft
{
	template < typename T, typename C = ft::vector<T> >
	class stack
	{
		public :
			/*
			** Canonical Form
			*/
			stack(void);
			~stack(void);
			stack(stack const & other);
			stack & operator = (stack const & other);

			/*
			** Other constructors
			*/
			/*
			** Misc
			*/
			/*
			** Guetters and setters
			*/
		private :
		
	};
}

#endif
