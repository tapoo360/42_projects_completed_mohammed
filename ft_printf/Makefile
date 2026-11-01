CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a 
LIBFT = libft.a

all: $(NAME) clean

$(NAME): ft_printf.o
	ar rcs $(LIBFT) ft_printf.o
	mv $(LIBFT) $(NAME)

ft_printf.o:  ft_printf.c ft_printf.h $(LIBFT)
	$(CC) $(CFLAGS) -c ft_printf.c

$(LIBFT):
	cd libft && $(MAKE) && mv libft.a ../

clean:
	rm -f ft_printf.o
	$(MAKE) fclean -C libft