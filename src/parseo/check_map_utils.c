/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:29:42 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/29 14:49:35 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int ft_isplayer(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int ft_isplayer_pos(t_args *t_args, char c, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		t_args->player_x = x;
		t_args->player_y = y;
		return (1);
	}
	return (0);
}

int ft_check_map_chars(t_args *t_args, char **map)
{
	int i;
	int j;
	int player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && !ft_isspace(map[i][j]) && !ft_isplayer(map[i][j]))
				return (printf("%s %c: invalid character in map%s\n", YELLOW,
							   map[i][j], RESET),
						FAIL);
			if (ft_isplayer_pos(t_args, map[i][j], i, j))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (printf("%sPlayer count: %d%s\n", YELLOW, player_count, RESET), FAIL);
	return (0);
}

void ft_copy_map(t_args *t_args)
{
	int i;

	i = 0;
	while (t_args->map[i])
	{
		t_args->map_cpy[i] = ft_strdup(t_args->map[i]);
		i++;
	}
	t_args->map_cpy[i] = NULL;
}
