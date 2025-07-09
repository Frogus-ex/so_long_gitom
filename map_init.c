/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:22:37 by tlorette          #+#    #+#             */
/*   Updated: 2025/07/09 14:48:33 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg_param(int ac, char **av, t_game *game)
{
	int		len;
	char	*name;

	if (ac > 2)
		ft_error(game, "Too many arguments");
	if (ac < 2)
		ft_error(game, "Missing map argument");
	name = av[1];
	len = ft_strlen(name);
	if (len < 5 || ft_strncmp(name + len - 4, ".ber", 4) != 0)
		ft_error(game, "Map file extension must be .ber");
	if (ft_strnstr(name, ".ber", len - 4))
		ft_error(game, "Map filename must not contain multiple .ber");
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
		return (ft_error(game, "Map inexistante"), 1);
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
			ft_error(game, "la map n est pas rectangualaire");
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
		ft_error(game, "map inexistante");
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
		return (ft_error(game, "Fonction read_map invalide"), 1);
	if (fill_map(game, av))
		return (1);
	return (0);
}
