/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:02:02 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/24 12:52:56 by tlorette         ###   ########.fr       */
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