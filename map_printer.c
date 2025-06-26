/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:38:49 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/24 14:09:26 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "so_long.h"
#include "libft/libft.h"

static	void	map_type(t_map *map, int x, int  y)
{
	int	type;
	
	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map ->mlx, map->win, map->img.player_down1, x + 8, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->img.exit, x, y);
	else if (type == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.wall, x, y);
}
void map_printer(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			map_type(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0
		y++;
	}
}