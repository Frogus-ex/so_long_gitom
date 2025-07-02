/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:22:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/02 19:11:08 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "so_long.h"

void	check_arg_param(int ac, char **av, t_game *game)
{
	int	map_param_len;

	game->map_alloc = false;
	if (ac > 2)
		ft_error(game, "Too many arg\n");
	if (ac < 2)
		ft_error(game, "map arg missing\n");
	map_param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_param_len - 4], ".ber", 4))
		ft_error(game, "map file extention must be .ber\n");
}

int	ft_gnlen(char *gnl)
{
	int	i;

	i = 0;
	while (gnl[i] && gnl[i] != '\n')
	{
		i++;
	}
	return (i);
}

static int	count_lines(t_game *game, char *av)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	game->height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		return (1);
	}
	game->width = ft_gnlen(line);
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

static int	fill_map(t_game *game, char *av)
{
	int		fd;
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (free(game->map), 1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (free(game->map), 1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < game->height)
	{
		game->map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(game->map);
	close(fd);
	return (0);
}

int	read_map(t_game *game, char *av)
{
	if (count_lines(game, av))
		return (1);
	if (fill_map(game, av))
		return (1);
	return (0);
}
