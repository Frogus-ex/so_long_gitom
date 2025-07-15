/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:02:02 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/15 10:23:49 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game, t_img *img)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	img->wall = mlx_xpm_file_to_image(game->mlx,
			"xpms/wall.xpm", &width, &height);
	if (!img->wall)
		ft_error(game, "impossible de dessiner les murs");
	img->floor = mlx_xpm_file_to_image(game->mlx,
			"xpms/floor.xpm", &width, &height);
	if (!img->floor)
		ft_error(game, "impossible de dessiner le sol");
	img->player = mlx_xpm_file_to_image(game->mlx,
			"xpms/player.xpm", &width, &height);
	if (!img->player)
		ft_error(game, "impossible de dessiner le joueur");
	img->collect = mlx_xpm_file_to_image(game->mlx,
			"xpms/collect.xpm", &width, &height);
	if (!img->collect)
		ft_error(game, "impossible de dessiner les collectibles");
	img->exit = mlx_xpm_file_to_image(game->mlx,
			"xpms/exit.xpm", &width, &height);
	if (!img->exit)
		ft_error(game, "impossible de dessiner la sortie");
}

void	if_draw(t_img *img, int y, int x)
{
	if (img->game->map[y][x] == WALL)
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (img->game->map[y][x] == PLAYER)
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (img->game->map[y][x] == EXIT)
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->exit,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (img->game->map[y][x] == COLLECT)
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->collect,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (img->game->map[y][x] == FLOOR)
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->floor,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_moves(t_game *game)
{
	char	*move_str;

	move_str = ft_itoa(game->player.moves);
	if (!move_str)
		ft_error(game, "ft_itoa a echoue");
	mlx_string_put(game->mlx, game->win, 10, 10, 0xCCFFFF, move_str);
	free(move_str);
}

void	draw_map(t_img *img)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < img->game->height)
	{
		x = 0;
		while (x < img->game->width)
		{
			tile = img->game->map[y][x];
			if_draw(img, y, x);
			x++;
		}
		y++;
	}
	if (y == x)
		ft_error(img->game, "Map carre !!");
	draw_moves(img->game);
}
