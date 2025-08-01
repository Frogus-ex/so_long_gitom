/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:38:08 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/11 14:49:52 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include "printf/ft_printf.h"

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define A 97
# define S 115
# define D 100
# define W 119

# define MOVE_FRONT 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define MOVE_BACK 4

# define IMG_PXL 50
# define TILE_SIZE 50
# define WND_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'

typedef struct s_player {
	int		y;
	int		x;
	int		moves;
}				t_player;

typedef struct s_cnt {
	int			count_p;
	int			count_e;
	int			count_c;
	int			count_f;
	int			tiles;
	t_player	player;
}				t_cnt;

struct	s_img;

typedef struct s_game{
	void			*mlx;
	void			*win;
	char			*line;
	int				len;
	int				fd;
	int				width;
	int				height;
	int				ignore_exit;
	char			**map;
	char			**tmp_map;
	t_player		player;
	t_cnt			content;
	struct s_img	*img;
}				t_game;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
	void	*wall;
	void	*exit;
	void	*player;
	void	*floor;
	void	*collect;
	t_game	*game;
}				t_img;

int		cleanup(t_game *game);
void	ft_victory(t_img *img);
void	ft_error(t_game *game, char *str);
int		key_press(int keycode, t_game *game);
int		cross_close(t_game *game);
void	ft_check_map(t_game *game);
void	map_check(t_game *game);
void	check_param(t_game *game);
void	ft_verify_param(t_game *game);
void	check_arg_param(int ac, char **av, t_game *game);
int		ft_gnlen(char	*gnl);
int		read_map(t_game *game, char *av);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
void	draw_map(t_img *img);
void	player_moves(t_img *img, int new_y, int new_x);
int		player_input(int keycode, t_img *img);
void	free_map(char **map);
void	flood_fill(t_game *game);
void	game_init(t_game **game, t_img *img);
void	init_mlx(t_game *game, t_img *img);
void	load_texture(t_game *game, t_img *img);
void	free_textures(t_game *game, t_img *img);
void	draw_moves(t_game *game);

#endif