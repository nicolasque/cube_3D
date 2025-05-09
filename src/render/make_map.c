/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:07:22 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/09 19:06:22 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	saved_map(t_structure *game, int fd)
{
	int		i;
	int		j;
	char	*line;

	(void)fd;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		line = game->t_args->map[i];
		if (!line)
			break ;
		game->map[i] = malloc((game->map_width) * sizeof(int));
		if (!game->map[i])
			return (1);
		while (++j < game->map_width)
		{
			if (line[j] != '0' && line[j] != '1')
				line[j] = '1';
			game->map[i][j] = line[j] - '0';
		}
	}
	return (0);
}

void	free_memory(t_structure *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
		ft_memdel(game->map[i]);
	ft_memdel(game->map);
	game->map = NULL;
	ft_clean_args(game->t_args);
}

int	make_map(t_structure *game)
{
	int	fd;

	(void)game;
	game->map = malloc(game->map_height * sizeof(int *));
	if (!game->map)
		return (1);
	fd = 0;
	if (saved_map(game, fd))
	{
		free_memory(game);
		printf("map error!\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
