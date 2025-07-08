/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:42:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/08 18:48:42 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == '1'
		|| game->map[game->player.y][game->player.x] == 'V')
		return ;
	if (game->map[game->player.y][game->player.x] == 'C'
		|| game->map[game->player.y][game->player.x] == 'E' ||
			game->map[game->player.y][game->player.x] == '0'
			|| game->map[game->player.y][game->player.x] == 'P')
		game->map[game->player.y][game->player.x] = 'V';
	else
		return ;

	flood_fill(game, game->map[game->player.y + 1][game->player.x]);
	flood_fill(game->map[game->player.y - 1][game->player.x]);
	flood_fill(game->map[game->player.y][game->player.x + 1]);
	flood_fill(game->map[game->player.y][game->player.x - 1]);
}

