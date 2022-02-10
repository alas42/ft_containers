NAME = 	ft_containers

FIRST_HEADER_FILES = templates/containers/vector.hpp \
	templates/iterators/iterator_traits.hpp \
	templates/iterators/randomAccessIterator.hpp \
	templates/iterators/reverse_iterator.hpp

FIRST_SOURCES_FILES =	vector_main.cpp

FIRST_OBJS = $(FIRST_SOURCES_FILES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra 
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(FIRST_OBJS) $(FIRST_HEADER_FILES)
	$(CC) $(CPPFLAGS) $(FIRST_SOURCES_FILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(FIRST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
