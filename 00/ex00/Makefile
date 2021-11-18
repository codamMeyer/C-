CC=g++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=megaphone


HEADER_FILES=		\
	megaphone.hpp	\

SRC_FILES=			\
	megaphone.cpp	\

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) main.c $(SRC_FILES) -o $(NAME)

test:
	@g++ -std=c++11 -Wall $(SRC_FILES) ../../tests/main.cpp test.cpp -o test && ./test --success

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

.PHONY: all clean fclean re
