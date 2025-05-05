/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:10:20 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/05 19:13:38 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void choose_direction_2(t_structure *game, char direction)
{
	if (direction == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->camera_x = -0.66;
		game->camera_y = 0;
	}
	else if (direction == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->camera_x = 0.66;
		game->camera_y = 0;
	}
}

void choose_direction(t_structure *game, char direction)
{
	if (direction == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->camera_x = 0;
		game->camera_y = 0.66;
	}
	else if (direction == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->camera_x = 0;
		game->camera_y = -0.66;
	}
	else
		choose_direction_2(game, direction);

}
