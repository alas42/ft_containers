NAME = 	ft_containers
NAME2 = stl_containers

HEADER_FILES = templates/containers/vector.hpp \
	templates/containers/stack.hpp \
	templates/containers/map.hpp \
	templates/tree/RedBlackTree.hpp \
	templates/tree/Node.hpp \
	templates/iterators/iterator_traits.hpp \
	templates/iterators/randomAccessIterator.hpp \
	templates/iterators/reverse_iterator.hpp \
	templates/iterators/bidirectionalIterator.hpp \
	templates/comparisons/binary_function.hpp \
	templates/comparisons/equal.hpp \
	templates/comparisons/lexicographical_compare.hpp \
	templates/misc/enable_if.hpp \
	templates/misc/integral_constant.hpp \
	templates/misc/is_integral.hpp \
	templates/pairs/pair.hpp

SOURCES_FILES =	ft_containers_main.cpp
SOURCES_FILES2 = stl_containers_main.cpp

OBJS = $(SOURCES_FILES:.cpp=.o)
OBJS2 = $(SOURCES_FILES2:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra 
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	$(CC) $(CPPFLAGS) $(SOURCES_FILES) -o $(NAME)

stl : $(NAME2)

$(NAME2): $(OBJS2)
	$(CC) $(CPPFLAGS) $(SOURCES_FILES2) -o $(NAME2)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

clean2:
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME)

fclean2: clean2
	rm -f $(NAME2)

re: fclean all

re2: fclean2 stl

.PHONY: all clean fclean re stl
