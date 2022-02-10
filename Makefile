NAME = ft_containers
NAME2 = containers

FIRST_HEADER_FILES = templates/containers/vector.hpp \
	templates/containers/stack.hpp \
	templates/iterators/iterator_traits.hpp \
	templates/iterators/randomAccessIterator.hpp \
	templates/iterators/reverse_iterator.hpp \
	templates/containers/map.hpp
#templates/iterators/bidirectionnalIterator.hpp

FIRST_SOURCES_FILES =	vector_main.cpp
SCD_SOURCES_FILES = stl_vector_main.cpp

SCD_OBJS = $(SCD_SOURCES_FILES:.cpp=.o)
FIRST_OBJS = $(FIRST_SOURCES_FILES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra 
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(FIRST_OBJS) $(FIRST_HEADER_FILES)
	$(CC) $(CPPFLAGS) $(FIRST_SOURCES_FILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

std: $(NAME2)

$(NAME2): $(SCD_OBJS)
	$(CC) $(CPPFLAGS) $(SCD_SOURCES_FILES) -o $(NAME2)

clean:
	rm -f $(FIRST_OBJS)
	rm -f $(SCD_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all std

.PHONY: all clean fclean re
