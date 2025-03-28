/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:40:18 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 20:04:12 by nquecedo         ###   ########.fr       */
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

static int ft_check_map_chars(t_args *t_args, char **map)
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

static void ft_copy_map(t_args *t_args)
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

void ft_flood_fill(t_args *g, int x, int y)
{
	// Check array boundaries and prevent stack overflow
	if (x < 0 || x >= g->map_heigth || y < 0 || y >= (int)ft_strlen(g->map_cpy[x]))
		return;

	// Get line length safely
	int line_len = ft_strlen(g->map_cpy[x]);
	if (y > line_len || g->map_cpy[x][y] == '\0')
		return;

	// Check if position is already visited or a wall
	char current = g->map_cpy[x][y];
	if (current == 'x' || current == '1')
		return;

	// Mark as visited
	if (current == '0' || current == ' ' || ft_isplayer(current))
		g->map_cpy[x][y] = 'x';

	// Continue flood fill in the 4 directions
	ft_flood_fill(g, x, y - 1); // Left
	ft_flood_fill(g, x, y + 1); // Right
	ft_flood_fill(g, x - 1, y); // Up
	ft_flood_fill(g, x + 1, y); // Down
}

int ft_check_map(t_args *t_args)
{
	while (t_args->map[t_args->map_heigth])
	{
		t_args->map_heigth++;
	}
	for (int i = 0; t_args->map[i]; i++)
		printf("MAP: %s", t_args->map[i]);

	if (ft_check_map_chars(t_args, t_args->map))
		return (printf("%s Map fail%s\n", RED, RESET), FAIL);
	printf("\n===================\n\n");
	ft_copy_map(t_args);
	for (int i = 0; t_args->map[i]; i++)
		printf("COPY: %s", t_args->map_cpy[i]);
	printf("\n===================\n\n");

	ft_flood_fill(t_args, t_args->player_x, t_args->player_y);
	for (int i = 0; t_args->map[i]; i++)
		printf("COPY_FOOD: %s", t_args->map_cpy[i]);

	return (0);
}