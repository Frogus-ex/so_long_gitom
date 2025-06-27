NAME = libftprintf.a

SRC  = ft_putstr.c \
	ft_putchar.c \
	ft_unsigned.c \
	ft_printf.c \
	ft_putaddr.c \
	ft_putnbr.c \
	ft_puthex_min.c \
	ft_puthex_maj.c \

OBJ  = $(SRC:.c=.o)

CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c libftprintf.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean