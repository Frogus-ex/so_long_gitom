/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:12:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/29 12:19:54 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include "so_long.h"
#include "GNL/get_next_line.h"

void	col_check(t_game *game);
void	line_check(t_game *game);
void	check_param(t_game *game);
void	ft_verify_param(t_game *game);

void ft_check_map(t_game *game)
{
	col_check(game);
	line_check(game);
	check_param(game);
	ft_verify_param(game);
}


void	col_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != WALL)
			ft_printf("map invalide car pas close\n");
		if (game->map[i][game->width - 1] != WALL)
			ft_printf("map invalide car pas close\n");
		i++;
	}
}

void	line_check(t_game *game)
{
	int	i;

	i = 0;
	while(i < game->width)
	{
		if (game->map[0][i] != WALL)
			ft_printf("map invalide car pas close\n");
		if (game->map[game->height - 1][i] != WALL)
			ft_printf("map invalide car pas close\n");
		i++;
	}
}

void	check_param(t_game *game)
{
	int	y;
	int	x;
	char	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			if (!ft_strchr("CEP01", tile))
				ft_printf("invalid map params\n");
			else if (tile == PLAYER)
			{
				game->content.count_p++;
				game->player.x = x;
				game->player.y = y;
			}
			else if (tile == COLLECT)
			{
				game->content.count_c++;
			}
			else if (tile == EXIT)
				game->content.count_e++;
			x++;
		}
		y++;
	}
}

void	ft_verify_param(t_game *game)
{
	if (game->content.count_c == 0)
		ft_printf("invalid map no coins\n");		
	else if (game->content.count_e == 0)
		ft_printf("invalid map no exit\n");
	else if (game->content.count_p != 1)
		ft_printf("invalid map invalid player number\n");
}