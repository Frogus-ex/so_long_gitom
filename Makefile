.SILENT:

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

SRC = main.c \
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
	cleaner.c \
	flood_fill.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I./GNL -I./printf -I$(LIBFT_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(MLX_LIB):
	if [ ! -d $(MLX_DIR) ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	$(MAKE) -C $(MLX_DIR)

$(OBJ): $(MLX_LIB)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	cc $(OBJ) $(LIBFT) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(NAME) created"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	@if [ -d $(MLX_DIR) ]; then $(MAKE) clean -C $(MLX_DIR); fi
	@echo "All object files deleted"

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	@if [ -d $(MLX_DIR) ]; then rm -rf $(MLX_DIR); fi
	@echo "All object files, binary & minilibx deleted"

re: fclean all

.PHONY: all clean fclean re bonus