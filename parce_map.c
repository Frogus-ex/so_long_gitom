/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:12:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/15 10:28:56 by tlorette         ###   ########.fr       */
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
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != WALL)
			ft_error(game, "map invalide car pas ferme");
		if (game->map[y][game->width - 1] != WALL)
			ft_error(game, "map invalide car pas ferme");
		y++;
	}
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != WALL)
			ft_error(game, "map invalide car pas ferme");
		if (game->map[game->height - 1][x] != WALL)
			ft_error(game, "map invalide car pas ferme");
		x++;
	}
}

static void	check_tile(t_game *game, char tile, int x, int y)
{
	if (!ft_strchr("CEP10", tile))
		ft_error(game, "parametres de la map invalide");
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
	else if (tile == FLOOR)
		game->content.count_f++;
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
		ft_error(game, "map invalide car pas de collectibles");
	else if (game->content.count_e != 1)
		ft_error(game, "map invalide car pas le bon nombre de sorties");
	else if (game->content.count_p != 1)
		ft_error(game, "map invalide car pas le bon nombre de joueurs");
	else if (game->content.count_f < 1)
		ft_error(game, "map invalide car pas de floor tiles");
}
