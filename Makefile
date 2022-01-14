NAME = ft_containers

NAME2 = containers

FIRST_HEADER_FILES = templates/vector.hpp

FIRST_SOURCES_FILES =	vector_main.cpp

SCD_SOURCES_FILES = stl_vector_main.cpp

FIRST_OBJS = $(FIRST_SOURCES_FILES:.cpp=.o)

SCD_OBJS = $(SCD_SOURCES_FILES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra 
CC = clang++ -std=c++98

all: $(NAME) $(NAME2)

$(NAME): $(FIRST_OBJS) $(FIRST_HEADER_FILES)
	$(CC) $(CPPFLAGS) $(FIRST_SOURCES_FILES) -o $(NAME)

$(NAME2): $(SCD_OBJS)
	$(CC) $(CPPFLAGS) $(SCD_SOURCES_FILES) -o $(NAME2)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(FIRST_OBJS)
	rm -f $(SCD_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
