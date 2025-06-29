/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:22:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/06/29 16:18:41 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "so_long.h"

void	check_arg_param(int ac, char **av, t_game *game)
{
	int	map_param_len;
	
	game->map_alloc = false;
	if (ac > 2)
	{
		ft_printf("Too many arg\n");
		exit(EXIT_FAILURE);
	}
	if (ac < 2)
	{
		ft_printf("map arg missing\n");
		exit(EXIT_FAILURE);
	}
	map_param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_param_len - 4], ".ber", 4))
		ft_printf("map file extention must be .ber\n");
}
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

int	read_map(t_game *game, char *av)
{
	int		fd;
	char	*line;
	int	i;
	
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	game->height = 0;
	line = get_next_line(fd);
	if (!line)
		{
			close(fd);
			return (1);
		}
	game->width = ft_gnlen(line);
	while (line)
	{
		// ft_printf("%s", line);
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < game->height)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	// ft_printf("\n%d\n%d", game->width, game->height);
	return (0);
}