CC = cc
WFLAG = -Werror -Wextra -Wall
NAME = libft.a
SRC = $(shell ls ft_*.c)
OBJ = (SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	ar  rcv $@ $?

$(OBJ): $(SRC)
	$(CC) $(WFLAG) -c $?


.PHONY: all fclean clean re

clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all