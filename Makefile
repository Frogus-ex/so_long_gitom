NAME = so_long

SRC  = main.c 

OBJ  = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux 

LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
