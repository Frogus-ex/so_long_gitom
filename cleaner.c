/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:08:36 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/07 14:18:02 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	cleanup(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game->map)
		free_map(game->map);
	if (game->img && game->mlx && game->img->img)
		mlx_destroy_image(game->mlx, game->img->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(EXIT_FAILURE);
}

void	ft_victory(t_img *img)
{
	ft_printf("GG TU ES TROP FORT A LE JEU VIDEO !!!");
	cleanup(img->game);
}

void	ft_error(t_game *game, char	*str)
{
	ft_printf("Error\n%s\n", str);
	cleanup(game);
}
