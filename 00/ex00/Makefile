CC=clang++
CFLAGS= -ggdb -Wall -Werror -Wextra 

NAME=megaphone

HEADER_FILES=		\
	megaphone.hpp	\

SRC_FILES=			\
	megaphone.cpp	\

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) -std=c++98 main.c $(SRC_FILES) -o $(NAME)

test: test.cpp
	@$(CC) $(CFLAGS) -std=c++17 $(SRC_FILES) ../../tests/main.cpp test.cpp -o test -lCatch2Main -lCatch2  && ./test --success

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

.PHONY: all clean fclean re
