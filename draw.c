/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:02:02 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/29 17:05:22 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_background(t_img *img, int width, int height)
{
	int colonne = 0;
	int ligne;

	while (colonne < height)
	{
		ligne = 0;
		while (ligne < width)
		{
			my_mlx_pixel_put(img, ligne, colonne, 0x00660066);
			ligne++;
		}
		colonne++;
	}
}

void	draw_tiles(t_img *img, int x, int y, int color)
{
	int	px;
	int py;
	
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
void	draw_map(t_img *img)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while(y < img->game->height)
	{
		x = 0;
		while (x < img->game->width)
		{
			tile = img->game->map[y][x];
			if (tile == WALL)
				draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x0033FFFF);
			else if (tile == PLAYER)
				draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FFFFFF);
			else if (tile == EXIT)
				draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x0000FF00);
			else if (tile == COLLECT)
				draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FFD700);
			else if (tile == FLOOR)
				draw_tiles(img, x * TILE_SIZE, y * TILE_SIZE, 0x00FF0000);	
			x++;
		}
		y++;
	}
	if (y == x)
	{
		printf("Erreur\n Map carre !!\n");
		exit (0);
	}
}