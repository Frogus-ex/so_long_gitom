.SILENT:

NAME = so_long

SRC  = main.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		key_handle.c \
		draw.c \
		parce_map.c \
		utils.c \
		map_init.c \
		printf/ft_printf.c \
		printf/ft_putaddr.c \
		printf/ft_putchar.c \
		printf/ft_puthex_maj.c \
		printf/ft_puthex_min.c \
		printf/ft_putnbr.c \
		printf/ft_putstr.c \
		printf/ft_unsigned.c \
		cleaner.c

OBJ  = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./GNL -I./printf

LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) created"

clean:
	rm -f $(OBJ)
	@echo "All objects files deleted"

fclean: clean
	rm -f $(NAME)
	@echo "All objects files & library deleted"

re: fclean all

.PHONY: all clean fclean re bonus
