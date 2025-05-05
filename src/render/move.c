/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:17:07 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/05 19:17:41 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void move_forward(t_structure *game)
{
    double new_x = game->player_x + game->dir_x * MOVE_SPEED;
    double new_y = game->player_y + game->dir_y * MOVE_SPEED;
    
    // Comprobaciones separadas para permitir deslizarse por las paredes
    // Sin verificación diagonal que cancele todo el movimiento
    if (game->map[(int)game->player_y][(int)new_x] == 0)
        game->player_x = new_x;
    if (game->map[(int)new_y][(int)game->player_x] == 0)
        game->player_y = new_y;
}

void move_backward(t_structure *game)
{
    double new_x = game->player_x - game->dir_x * MOVE_SPEED;
    double new_y = game->player_y - game->dir_y * MOVE_SPEED;
    
    // Comprobaciones separadas para permitir deslizarse por las paredes
    // Sin verificación diagonal que cancele todo el movimiento
    if (game->map[(int)game->player_y][(int)new_x] == 0)
        game->player_x = new_x;
    if (game->map[(int)new_y][(int)game->player_x] == 0)
        game->player_y = new_y;
}

void move_right(t_structure *game)
{
	if (game->map[(int)(game->player_y)][(int)(game->player_x - game->dir_x * MOVE_SPEED)] == 0)
        game->player_x -= game->dir_x * MOVE_SPEED;
    if (game->map[(int)(game->player_y + game->dir_y * MOVE_SPEED)][(int)(game->player_x)] == 0)
        game->player_y += game->dir_y * MOVE_SPEED;
}

//PINTAMOS EL MAPA EN LA TERMINAL
void	pain_map_position(t_structure *game)
{
	static int current_x;
	static int current_y;

	int i = -1;
	if (current_x != (int)game->player_x || current_y != (int)game->player_y)
	{
		while (++i < game->map_height)
		{
			int j = -1;
			while (++j < game->map_width)
			{
				if (i == (int)game->player_y && j == (int)game->player_x)
					printf("X");
				else	
					printf("%i", game->map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	current_x = (int)game->player_x;
	current_y = (int)game->player_y;
}
