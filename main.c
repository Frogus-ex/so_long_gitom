/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:03:28 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/24 18:38:29 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include "mlx.h"
#include "so_long.h"

int	main()
{
	int		width;
	int		height;
	int		ligne;
	int		colonne;
	t_img	img;
	t_game	game;
	
	ligne = 0;
	colonne = 0;
	width = 0;
	height = 0;
	read_map(&game, "map/map1.ber");
	game.mlx = mlx_init();
	mlx_get_screen_size(game.mlx, &width, &height);
	game.win = mlx_new_window(game.mlx, width, height, WND_NAME);
	img.img = mlx_new_image(game.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);


	
	draw_background(&img, width, height);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 17, 1L<<2, cross_close, &game);
	mlx_hook(game.win, 8, 1L<<5, mouse_leave, NULL);
	mlx_hook(game.win, 7, 1L<<4, mouse_enter, NULL);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_loop(game.mlx);
}