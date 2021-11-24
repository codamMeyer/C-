CC=g++
CFLAGS= -Wall -Werror -Wextra 

NAME=phoneBook

HEADER_FILES = 				\
	IODevice.hpp			\
	PhoneBook.hpp			\
	IOHandler.hpp			\

SRC_FILES=					\
	IODevice.cpp			\
	PhoneBook.cpp			\
	IOHandler.cpp			\

TEST_FILES = test.cpp

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) -std=c++98 main.cpp $(SRC_FILES) -o $(NAME)

clean:

test:
	@$(CC) $(CFLAGS) -std=c++17 $(SRC_FILES) ../../tests/main.cpp test.cpp -o test -lCatch2Main -lCatch2 && ./test

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

.PHONY: all clean fclean re test
