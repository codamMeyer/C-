CC=g++
CFLAGS= -Wall -Werror -Wextra -std=c++98

NAME=hiThisIsBrain

all: $(NAME)

$(NAME): main.cpp
	$(CC) $(CFLAGS) $(SRC_FILES) main.cpp -o $(NAME)

clean:

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
