#ifndef STACK_HPP
# define STACK_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Stack
{
	public :
		/*
		** Canonical Form
		*/
		Stack(void);
		~Stack(void);
		Stack(Stack const & other);
		Stack & operator = (Stack const & other);

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

#endif
