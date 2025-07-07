.SILENT:

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

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

CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux -I./GNL -I./printf -I$(LIBFT_DIR)

LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) created"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	@echo "All object files deleted"

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "All object files & libraries deleted"

re: fclean all

.PHONY: all clean fclean re bonus
