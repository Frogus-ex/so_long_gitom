/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:12:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/02 18:41:36 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_game *game);
void	check_param(t_game *game);
void	ft_verify_param(t_game *game);

void	ft_check_map(t_game *game)
{
	game->content.count_c = 0;
	game->content.count_e = 0;
	game->content.count_p = 0;
	map_check(game);
	check_param(game);
	ft_verify_param(game);
}

void	map_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != WALL)
			ft_error(game, "map invalide car pas close\n");
		if (game->map[i][game->width - 1] != WALL)
			ft_error(game, "map invalide car pas close\n");
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != WALL)
			ft_error(game, "map invalide car pas close\n");
		if (game->map[game->height - 1][i] != WALL)
			ft_error(game, "map invalide car pas close\n");
		i++;
	}
}

static void	check_tile(t_game *game, char tile, int x, int y)
{
	if (!ft_strchr("CEP01", tile))
		ft_error(game, "invalid map params\n");
	else if (tile == PLAYER)
	{
		game->content.count_p++;
		game->player.x = x;
		game->player.y = y;
	}
	else if (tile == COLLECT)
		game->content.count_c++;
	else if (tile == EXIT)
		game->content.count_e++;
}

void	check_param(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			check_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_verify_param(t_game *game)
{
	if (game->content.count_c == 0)
		ft_error(game, "invalid map no coins\n");
	else if (game->content.count_e == 0)
		ft_error(game, "invalid map no exit\n");
	else if (game->content.count_p != 1)
		ft_error(game, "invalid map invalid player number\n");
}
