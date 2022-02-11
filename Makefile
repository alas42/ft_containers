NAME = 	ft_containers
NAME2 = stl_containers

HEADER_FILES = templates/containers/vector.hpp \
	templates/containers/stack.hpp \
	templates/containers/map.hpp \
	templates/tree/Node.hpp \
	templates/tree/RedBlackTree.hpp \
	templates/iterators/iterator_traits.hpp \
	templates/iterators/randomAccessIterator.hpp \
	templates/iterators/reverse_iterator.hpp \
	templates/iterators/bidirectionalIterator.hpp

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
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

re2: fclean all stl

.PHONY: all clean fclean re stl
