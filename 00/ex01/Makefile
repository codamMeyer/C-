CC=g++
CFLAGS= -Wall -Werror -Wextra #-std=c++98

NAME=yellow_book

HEADER_FILES = 				\
	yellow_book.hpp			\
	contact.hpp				\
	parser.hpp				\

SRC_FILES=					\
	yellow_book.cpp			\
	contact.cpp				\
	parser.cpp				\

TEST_FILES = test.cpp

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) main.cpp $(SRC_FILES) -o $(NAME)

clean:

test:
	@g++ -std=c++11 -Wall -I ../../tests -c ../../tests/main.cpp
	@g++ -std=c++11 -Wall -I ../../tests -o test main.o test.cpp && ./test --success

re: fclean all

fclean: clean
	rm -f $(NAME)

run:
	$(CC) -ggdb3 $(TEST_INC_PATH) $(USER_INC_PATH) $(TEST_FILES) $(USER_LDFLAGS) -o $(TEST_NAME)


.PHONY: all clean fclean re test libft run
