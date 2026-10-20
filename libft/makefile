CC = cc
WFLAG = -Werror -Wextra -Wall
NAME = libft.a
SRC := $(shell ls ft_*.c)
OBJ = $(SRC:.c=.o)

.PHONY: all fclean clean re

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rcv $@ $?

$(OBJ): $(SRC)
	$(CC) $(WFLAG) -c $?

re: fclean all

clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(NAME)
