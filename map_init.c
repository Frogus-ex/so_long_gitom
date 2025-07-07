/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:22:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/07 17:27:08 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg_param(int ac, char **av, t_game *game)
{
	int	map_param_len;

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
	char	*stash;

	stash = NULL;
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
		return (1);
	game->height = 0;
	game->line = get_next_line(game->fd, &stash);
	if (!game->line)
		return (free(game->line), close(game->fd), 1);
	game->width = ft_gnlen(game->line);
	while (game->line)
	{
		game->len = ft_gnlen(game->line);
		if (game->len == 0 || game->width == 0 || game->len != game->width)
		{
			free(game->line);
			free(stash);
			ft_error(game, "map au format non valide");
		}
		game->height++;
		free(game->line);
		game->line = get_next_line(game->fd, &stash);
	}
	return (close(game->fd), 0);
}

static int	fill_map(t_game *game, char *av)
{
	int		i;
	char	*stash;

	stash = NULL;
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (1);
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
		return (free(game->map), 1);
	i = 0;
	game->line = get_next_line(game->fd, &stash);
	while (game->line && i < game->height)
	{
		game->map[i] = ft_strdup(game->line);
		if (!game->map[i])
			return (free(game->line), free_map(game->map), close(game->fd), 1);
		free(game->line);
		game->line = get_next_line(game->fd, &stash);
		i++;
	}
	free(game->line);
	game->map[i] = NULL;
	return (close(game->fd), 0);
}

int	read_map(t_game *game, char *av)
{
	if (count_lines(game, av))
		return (1);
	if (fill_map(game, av))
		return (1);
	return (0);
}
