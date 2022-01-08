CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98 -pedantic

TEST_FLAGS=-Wl,-rpath=/usr/local/lib -lgtest -lgtest_main -lpthread -O0 -ggdb

NAME=converter

HEADER_FILES = 						\
	Converter.hpp						\
	ConversionPrinter.hpp		\

SRC_FILES=								\
	Converter.cpp						\
	ConversionPrinter.cpp		\

TEST=$(NAME)Test

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES) main.cpp
	$(CC) $(CFLAGS) $(SRC_FILES) main.cpp -o $(NAME)

test: $(SRC_FILES) $(HEADER_FILES) test.cpp
	@g++ $(TEST_FLAGS) $(SRC_FILES) test.cpp -o $(TEST) && ./$(TEST)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

.PHONY: all clean fclean re
