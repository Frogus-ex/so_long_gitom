/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:03:28 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/18 17:23:42 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "mlx.h"
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
int	main()
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		ligne;
	int		colonne;
	t_data	img;
	t_vars	vars;
	
	ligne = 0;
	colonne = 0;
	width = 0;
	height = 0;
	mlx = mlx_init();
	mlx_get_screen_size(mlx, &width, &height);
	mlx_win = mlx_new_window(mlx, width, height, "Hello World!");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// while(ligne < 100)
	// {
	// 	my_mlx_pixel_put(&img, ligne, 0, 0x00FF0000);
	// 	ligne++;
	// }
	// while(colonne < 100)
	// {
	// 	my_mlx_pixel_put(&img, 0, colonne, 0x00FF0000);
	// 	colonne++;
	// }
	// ligne = 0;
	// while(ligne < 100)
	// {
	// 	my_mlx_pixel_put(&img, ligne, 100, 0x00FF0000);
	// 	ligne++;
	// }
	// colonne = 0;
	// while(colonne < 100)
	// {
	// 	my_mlx_pixel_put(&img, 100, colonne, 0x00FF0000);
	// 	colonne++;
	// }
	while (colonne < height)
	{
		ligne = 0;
		while (ligne < width)
		{
			my_mlx_pixel_put(&img, ligne, colonne, 0x00FF0000);
			ligne++;
		}
		colonne++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L<<0, close, &vars);
	mlx_loop(mlx);
}