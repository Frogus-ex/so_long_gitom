/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:03:28 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/27 17:45:40 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include "mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		width;
	int		height;
	int		ligne;
	int		colonne;
	t_img	img;
	t_game	*game;
	
	ligne = 0;
	colonne = 0;
	width = 1300;
	height = 1300;
	game = malloc(sizeof(t_game));
	img.game = game;
	if (!game)
		exit(EXIT_FAILURE);
	game->path = av[1];
	check_arg_param(ac, av, game);
	read_map(game, av[1]);
	ft_check_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, WND_NAME);
	img.img = mlx_new_image(game->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);


	draw_background(&img, width, height);
	draw_map(&img);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	if (!mlx_key_hook(game->win, key_press, game))
		return (0);
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_loop(game->mlx);
	return (0);
}