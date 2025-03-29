/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:40:18 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/29 15:00:10 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"


void ft_flood_fill(t_args *g, int x, int y)
{
	if (x < 0 || x >= g->map_heigth || y < 0 || y >= (int)ft_strlen(g->map_cpy[x]))
		return;

	int line_len = ft_strlen(g->map_cpy[x]);
	if (y > line_len || g->map_cpy[x][y] == '\n')
		return;

	char current = g->map_cpy[x][y];
	if (current == 'x' || current == '1')
		return;

	if (current == '0' || current == ' ' || ft_isplayer(current))
		g->map_cpy[x][y] = 'x';

	ft_flood_fill(g, x, y - 1);
	ft_flood_fill(g, x, y + 1);
	ft_flood_fill(g, x - 1, y);
	ft_flood_fill(g, x + 1, y);
}


int ft_clean_line_jump(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]))
			str[i][ft_strlen(str[i]) - 1] = '\0';
		i++;
	}
	return (0);
}

int ft_check_After_flood(t_args * t_args)
{
	
}


int ft_check_map(t_args *t_args)
{
	while (t_args->map[t_args->map_heigth])
	{
		t_args->map_heigth++;
	}
	ft_clean_line_jump(t_args->map);
	for (int i = 0; t_args->map[i]; i++)
		printf("MAP: %s\n", t_args->map[i]);

		
	if (ft_check_map_chars(t_args, t_args->map))
		return (printf("%s Map fail%s\n", RED, RESET), FAIL);
	printf("\n===================\n\n");
	ft_copy_map(t_args);
	for (int i = 0; t_args->map[i]; i++)
		printf("COPY: %s\n", t_args->map_cpy[i]);
	printf("\n===================\n\n");

	ft_flood_fill(t_args, t_args->player_x, t_args->player_y);

	if (ft_check_After_flood(t_args))
		return (FAIL);
	return (0);
}