/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:42:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/15 10:51:46 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game)
{
	int	y;
	int	i;

	y = 0;
	i = 0;
	game->tmp_map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->tmp_map)
		return (ft_error(game, "erreur malloc tmp_map"));
	while (i <= game->height)
	{
		game->tmp_map[i] = NULL;
		i++;
	}
	while (y < game->height)
	{
		game->tmp_map[y] = ft_strdup(game->map[y]);
		if (!game->tmp_map[y])
			return (free_map(game->tmp_map),
				ft_error(game, "erreur strdup tmp_map"));
		y++;
	}
	game->tmp_map[game->height] = NULL;
}

void	fill(t_game *game, char **tmp_map, int y, int x)
{
	if (tmp_map[y][x] == 'V' || tmp_map[y][x] == '1')
		return ;
	if (tmp_map[y][x] == 'E' && game->ignore_exit == 1)
		return ;
	if (tmp_map[y][x] == 'C' || tmp_map[y][x] == '0' || tmp_map[y][x] == 'P'
		|| tmp_map[y][x] == 'E')
		tmp_map[y][x] = 'V';
	else
		return ;
	fill(game, tmp_map, y + 1, x);
	fill(game, tmp_map, y - 1, x);
	fill(game, tmp_map, y, x + 1);
	fill(game, tmp_map, y, x - 1);
}

void	check_fill(t_game *game, int y, int x)
{
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->tmp_map[y][x] == COLLECT || (game->tmp_map[y][x] == 'E'
				&& game->ignore_exit == 0))
				return (free_map(game->tmp_map),
					ft_error(game, "pas de passage valide"));
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game)
{
	copy_map(game);
	game->ignore_exit = 1;
	fill(game, game->tmp_map, game->player.y, game->player.x);
	check_fill(game, game->player.y, game->player.x);
	free_map(game->tmp_map);
	copy_map(game);
	game->ignore_exit = 0;
	fill(game, game->tmp_map, game->player.y, game->player.x);
	check_fill(game, game->player.y, game->player.x);
	free_map(game->tmp_map);
}
