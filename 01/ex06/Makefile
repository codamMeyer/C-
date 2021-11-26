CC=clang++
CFLAGS= -Wall -Wextra -Werror

NAME=karenFilter

HEADER_FILES = 	\
	Karen.hpp	\

SRC_FILES=		\
	Karen.cpp	\

TEST_FILES = test.cpp

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	@$(CC) $(CFLAGS) -std=c++98 main.cpp $(SRC_FILES) -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

.PHONY: all clean fclean re test
