CC=g++
CFLAGS= -Wall -Werror -Wextra 

NAME=sedIsForLosers

HEADER_FILES = 	\
	IODevice.hpp	\
	Sed.hpp	\

SRC_FILES=		\
	IODevice.cpp	\
	Sed.cpp	\

TEST_FILES = test.cpp

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) -std=c++98 main.cpp $(SRC_FILES) -o $(NAME)

clean:

test:
	@$(CC) $(CFLAGS) -std=c++17 $(SRC_FILES) ../../tests/main.cpp $(TEST_FILES) -o test -lCatch2Main -lCatch2 && ./test

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test
	rm -f *.replace

run:
	$(CC) -ggdb3 $(TEST_INC_PATH) $(USER_INC_PATH) $(TEST_FILES) $(USER_LDFLAGS) -o $(TEST_NAME)


.PHONY: all clean fclean re test
