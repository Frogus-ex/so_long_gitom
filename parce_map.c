/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:12:56 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/24 19:04:44 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fcntl.h>
#include<stdio.h>
#include "so_long.h"
#include "GNL/get_next_line.h"

int	ft_gnlen(char	*gnl)
{
	int	i;
	
	i= 0;
	while (gnl[i] && gnl[i] != '\n')
	{
		i++;
	}
	return (i);
}


void	read_map(t_game *game, char *path)
{
	int		fd;
	char	*gnl;
	
	fd = open(path, O_RDONLY);
	gnl = get_next_line(fd);
	game->height = 0;
	game->width = ft_gnlen(gnl);
	while (gnl)
	{
		printf("%s", gnl);
		gnl = get_next_line(fd);
		game->height++;
	}
	printf("\n%d\n%d", game->width, game->height);
}

int	col_check(char	*map_line, char wall, t_game *game)
{
	int	i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		printf("map invalide car pas close\n");
		return (0);
	}
	game->width = i;
	return (1);
}

int	line_check(char *map_line, char wall)
{
	int	i;

	i = 0;
	while(map_line[i])
	{
		if (map_line[i] != wall)
		{
			printf("map invalide car pas close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_symbols(char	*map_line, t_cnt *content)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			printf("Erreur car il y a pas le bon nombre de sortie ou personnage");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->exit 
			&& map_line[i] != content->player && map_line[i] != content->collect 
			&& map_line[i] != content->space)
		{
			printf("Erreur symbole inconnu");
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_content(t_game *game)
{
	int	i;
	int	y;
	
	i = 0;
	y = 0;
	while (game->map[i])
	{
		while (game->map[i][y])
		{
			if (game->map[i][y] == game->content.collect)
				game->content.count_c += 1;
			if (game->map[i][y] == game->content.player)
				game->content.count_p += 1;
			if (game->map[i][y] == game->content.exit)
				game->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
	printf("%d\n", game->content.count_c);
}