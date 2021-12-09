#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define RED "\033[31m"

class Map
{
	public :
		/*
		** Canonical Form
		*/
		Map(void);
		~Map(void);
		Map(Map const & other);
		Map & operator = (Map const & other);

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
