/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:02:02 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/02 18:42:21 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_tiles(t_img *img, int x, int y, int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < TILE_SIZE)
	{
		px = 0;
		{
			while (px < TILE_SIZE)
			{
				my_mlx_pixel_put(img, x + px, y + py, color);
				px++;
			}
			py++;
		}
	}
}

void	if_draw(t_img *img, int y, int x)
{
	if (img->game->map[y][x] == WALL)
		draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x0033FFFF);
	else if (img->game->map[y][x] == PLAYER)
		draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FFFFFF);
	else if (img->game->map[y][x] == EXIT)
		draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x0000FF00);
	else if (img->game->map[y][x] == COLLECT)
		draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FFD700);
	else if (img->game->map[y][x] == FLOOR)
		draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FF0000);
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
		ft_error(img->game, "Map carre !!\n");
}
