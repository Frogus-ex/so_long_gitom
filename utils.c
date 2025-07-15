/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:00:06 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/15 10:18:15 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

void	game_init(t_game **game, t_img *img)
{
	*game = ft_calloc(1, sizeof(t_game));
	if (!*game)
		cleanup(NULL);
	img->game = *game;
	img->img = NULL;
	img->addr = NULL;
	img->wall = NULL;
	img->floor = NULL;
	img->player = NULL;
	img->collect = NULL;
	img->exit = NULL;
	img->width = 0;
	img->height = 0;
	img->screen_width = 0;
	img->screen_height = 0;
	(*game)->img = img;
	(*game)->player.moves = 0;
}

void	init_mlx(t_game *game, t_img *img)
{
	img->width = TILE_SIZE * game->width;
	img->height = TILE_SIZE * game->height;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(game, "mlx_init echoue");
	load_texture(game, img);
	mlx_get_screen_size(game->mlx, &img->screen_width, &img->screen_height);
	if (img->width > img->screen_width || img->height > img->screen_height)
		ft_error(game, "map trop grande");
	game->win = mlx_new_window(game->mlx, img->width, img->height, WND_NAME);
	img->img = mlx_new_image(game->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	free_textures(t_game *game, t_img *img)
{
	if (img->wall)
		mlx_destroy_image(game->mlx, img->wall);
	if (img->floor)
		mlx_destroy_image(game->mlx, img->floor);
	if (img->player)
		mlx_destroy_image(game->mlx, img->player);
	if (img->collect)
		mlx_destroy_image(game->mlx, img->collect);
	if (img->exit)
		mlx_destroy_image(game->mlx, img->exit);
}
