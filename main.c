/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:03:28 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/03 14:27:30 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include "mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	int		screen_width;
	int		screen_height;
	t_img	img;
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		cleanup(game);
	img.game = game;
	game->img = &img;
	game->player.moves = 0;
	check_arg_param(ac, av, game);
	read_map(game, av[1]);
	ft_check_map(game);
	img.width = TILE_SIZE * game->width;
	img.height = TILE_SIZE * game->height;
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (img.width > screen_width || img.height > screen_height)
		ft_error(game, "map trop grande");
	game->win = mlx_new_window(game->mlx, img.width, img.height, WND_NAME);
	img.img = mlx_new_image(game->mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_map(&img);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 2, 1L << 0, player_input, &img);
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_loop(game->mlx);
	return (0);
}
