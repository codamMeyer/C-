CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98 -pedantic

TEST_FLAGS=-Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -O0 -ggdb

NAME=mutantstack

HEADER_FILES = 				\
	mutantstack.hpp			\

SOURCE_FILES = 				\
	mutantstack.cpp			\

TEST=$(NAME)Test

all: $(NAME)

$(NAME): $(SOURCE_FILES) $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) $(SOURCE_FILES) main.cpp -o $(NAME)

test: $(SOURCE_FILES) $(HEADER_FILES) test.cpp
	@g++ $(TEST_FLAGS) $(SOURCE_FILES) test.cpp -o $(TEST) && ./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.PHONY: all clean fclean re
