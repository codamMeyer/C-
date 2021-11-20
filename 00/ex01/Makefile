CC=g++
CFLAGS= -Wall -Werror -Wextra 

NAME=phoneBook

HEADER_FILES = 				\
	IODevice.hpp			\
	PhoneBook.hpp			\

SRC_FILES=					\
	IODevice.cpp			\
	PhoneBook.cpp			\

TEST_FILES = test.cpp

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) main.cpp $(SRC_FILES) -o $(NAME)

clean:

test:
	@$(CC) $(CFLAGS) -std=c++17 $(SRC_FILES) ../../tests/main.cpp test.cpp -o test -lCatch2Main -lCatch2 && ./test --success

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

run:
	$(CC) -ggdb3 $(TEST_INC_PATH) $(USER_INC_PATH) $(TEST_FILES) $(USER_LDFLAGS) -o $(TEST_NAME)


.PHONY: all clean fclean re test libft run
