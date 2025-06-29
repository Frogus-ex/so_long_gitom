/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:21:09 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/29 16:42:46 by tlorette         ###   ########.fr       */
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

int	player_input(int keycode, t_img *img)
{
	// ft_printf("KEY PRESSED = %d\n", keycode);
	// ft_printf("img = %p, img->game = %p\n", img, img->game);
	// ft_printf("player x = %d, y = %d\n", img->game->player.x, img->game->player.y);
	
	if (keycode == UP || keycode == W)
		player_moves(img, img->game->player.y - 1, img->game->player.x, MOVE_BACK);
	if (keycode == DOWN || keycode == S)
		player_moves(img, img->game->player.y + 1, img->game->player.x, MOVE_FRONT);
	if (keycode == RIGHT || keycode == D)
		player_moves(img, img->game->player.y, img->game->player.x + 1, MOVE_RIGHT);
	if (keycode == LEFT || keycode == A)
		player_moves(img, img->game->player.y, img->game->player.x - 1, MOVE_LEFT);
	return (0);
}

void	player_moves(t_img *img, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	last_x = img->game->player.x;
	last_y = img->game->player.y;
	img->game->player_sprite = player_sprite;
	if (new_y < 0 || new_y >= img->game->height || new_x < 0 || new_x >= img->game->width)
	{
		ft_printf("depassement de map");
		return ;
	}
	if (img->game->map[new_y][new_x] == EXIT && img->game->content.count_c == 0)
	{
		ft_printf("\ngg victoire !!!!");
		mlx_destroy_window(img->game->mlx, img->game->win);
		exit (0);
	}
	else if (img->game->map[new_y][new_x] == FLOOR || img->game->map[new_y][new_x] == COLLECT)
	{
		if (img->game->map[new_y][new_x] == COLLECT)
		{
			img->game->content.count_c--;
		}
		img->game->map[last_y][last_x] = FLOOR;
		img->game->player.x = new_x;
		img->game->player.y = new_y;
		img->game->map[new_y][new_x] = PLAYER;
		img->game->player.moves++;
		ft_printf("%d\n", img->game->player.moves);
		draw_map(img);
		mlx_put_image_to_window(img->game->mlx, img->game->win, img->img, 0, 0);
	}
}