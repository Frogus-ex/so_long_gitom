#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363valgrind
#define IMG_PXL 50
#define WND_NAME "so_long"

typedef struct s_player {
	int	y;
	int	x;
}				t_player;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


typedef struct	s_cnt {
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_img	*img;
	t_player	player;
	size_t		size;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
}				t_game;

void 	draw_background(t_img *img, int width, int height);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		key_press(int keycode, t_game *game);
int		cross_close(t_game *game);
int		mouse_enter(void);
int		mouse_leave(void);
void	read_map(t_game *game, char *path);
void	ft_error(char	*str);


#endif