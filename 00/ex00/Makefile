CC=g++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=megaphone

SRC_FILES=			\
	megaphone.cpp	\

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
