CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=serialization

HEADER_FILES = 		\
	Serializer.hpp	\
	Data.hpp				\

SRC_FILES=				\
	Serializer.cpp	\
	Data.cpp				\

TEST=$(NAME)Test

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) $(SRC_FILES) main.cpp -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.PHONY: all clean fclean re
