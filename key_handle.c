/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:21:09 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/27 16:36:29 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "mlx.h"
#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	return (0);
}

int	cross_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	mouse_enter(void)
{
	write (1, "hello\n", 6);
	return(0);
}

int	mouse_leave(void)
{
	write (1, "bye\n", 4);
	return(0);
}