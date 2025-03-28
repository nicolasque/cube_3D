/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:40:18 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 01:16:40 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int	ft_check_map_chars(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && !ft_isspace(map[i][j])
				&& !ft_isplayer(map[i][j]))
				return (printf("%s %c: invalid character in map%s\n", YELLOW,
						map[i][j], RESET), FAIL);
			if (ft_isplayer(map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count > 1)
		return (printf("%sPlayer count: %d%s\n",YELLOW, player_count, RESET), FAIL);
	return (0);
}

static char	**ft_copy_map(t_args *t_args)
{
	int		i;
	char	**map_cpy;

	map_cpy = (char **)malloc(sizeof(char *) * (t_args->heig + 1));
	i = 0;
	while (t_args->map[i])
	{
		map_cpy[i] = ft_strdup(t_args->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	ft_check_map(t_args *t_args)
{
	char **map_cpy;

	if (ft_check_map_chars(t_args->map))
		return (printf("%s Map fail%s\n", RED, RESET), FAIL);
	printf("\n===================\n\n");
	map_cpy = ft_copy_map(t_args);
	for (int i = 0; map_cpy[i]; i++)
		printf("COPY: %s\n", map_cpy[i]);

	return (0);
}