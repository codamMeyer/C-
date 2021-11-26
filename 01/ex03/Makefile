CC=clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=unnecessaryViolence

HEADER_FILES = 		\
	HumanA.hpp		\
	HumanB.hpp		\
	Weapon.hpp		\

SRC_FILES=			\
	HumanA.cpp		\
	HumanB.cpp		\
	Weapon.cpp		\

all: $(NAME)

$(NAME): $(SRC_FILES) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) main.cpp -o $(NAME)

test: $(SRC_FILES) $(HEADER_FILES) test.cpp
	@$(CC) $(CFLAGS) -std=c++17 $(SRC_FILES) ../../tests/main.cpp test.cpp -o test -lCatch2Main -lCatch2 && ./test

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -f test

.PHONY: all clean fclean re
