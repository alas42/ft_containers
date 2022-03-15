NAME = 	ft_containers
NAME2 = stl_containers

HEADER_FILES = vector.hpp \
	stack.hpp \
	iterator_traits.hpp \
	randomAccessIterator.hpp \
	reverse_iterator.hpp \
	bidirectionalIterator.hpp \
	binary_function.hpp \
	equal.hpp \
	lexicographical_compare.hpp \
	enable_if.hpp \
	integral_constant.hpp \
	is_integral.hpp \
	pair.hpp \
	map.hpp \
	RedBlackTree.hpp \
	Node.hpp \
	

SOURCES_FILES =	ft_containers_main.cpp
SOURCES_FILES2 = find_main.cpp

OBJS = $(SOURCES_FILES:.cpp=.o)
OBJS2 = $(SOURCES_FILES2:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra 
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	$(CC) $(CPPFLAGS) $(SOURCES_FILES) -o $(NAME)

stl : $(NAME2)

$(NAME2): $(OBJS2) $(HEADER_FILES)
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
