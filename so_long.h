#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "GNL/get_next_line.h"
#include "printf/ft_printf.h"

#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

#define IMG_PXL 50
#define TILE_SIZE 100
#define WND_NAME "so_long"

#define WALL '1'
#define FLOOR '0'
#define COLLECT 'C'
#define PLAYER 'P'
#define EXIT 'E'

typedef enum e_bool 
{
	false,
	true
}	t_bool;

typedef struct s_player {
	int	y;
	int	x;
}				t_player;



typedef struct	s_cnt {
	int		count_p;
	int		count_e;
	int		count_c;
	int		tiles;
	t_player	player;
}				t_cnt;

typedef struct	s_game {
	void		*mlx;
	void		*win;
	char		*path;
	int			width;
	int			height;
	char		**map;
// t_img		*img;
	t_player	player;
	t_cnt		content;
	t_bool		map_alloc;
}				t_game;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_game	*game;
}				t_img;

void 	draw_background(t_img *img, int width, int height);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_press(int keycode, t_game *game);
int		cross_close(t_game *game);
int		mouse_enter(void);
int		mouse_leave(void);
void	ft_check_map(t_game *game);
void	col_check(t_game *game);
void	line_check(t_game *game);
void	check_param(t_game *game);
void	ft_verify_param(t_game *game);
void	check_arg_param(int ac, char **av, t_game *game);
int		ft_gnlen(char	*gnl);
int		read_map(t_game *game, char *av);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
void	draw_tiles(t_img *img, int x, int y, int color);
void	draw_map(t_img *img);


#endif