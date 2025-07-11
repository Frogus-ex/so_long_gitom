/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:03:28 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/09 17:21:40 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include "mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_img	img;
	t_game	*game;

	game_init(&game, &img);
	check_arg_param(ac, av, game);
	read_map(game, av[1]);
	ft_check_map(game);
	flood_fill(game);
	init_mlx(game, &img);
	draw_map(&img);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 2, 1L << 0, player_input, &img);
	mlx_hook(game->win, 17, 0, cross_close, game);
	mlx_loop(game->mlx);
	return (0);
}
