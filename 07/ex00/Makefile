CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98 -pedantic

NAME=templates

HEADER_FILES = 						\
	whatever.hpp						\

all: $(NAME)

$(NAME): $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
