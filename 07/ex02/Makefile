CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98 -pedantic

TEST_FLAGS=-Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -O0 -ggdb

NAME=Array

HEADER_FILES =Array.hpp

TEST=$(NAME)Test

all: $(NAME)

$(NAME): $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(NAME)

test: $(HEADER_FILES) test.cpp
	@g++ $(TEST_FLAGS) test.cpp -o $(TEST) && ./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.PHONY: all clean fclean re
