/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:01:53 by nquecedo          #+#    #+#             */
/*   Updated: 2025/04/29 14:43:36 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void ft_get_player_dir(t_args *t_args)
{
	char player_char;

	player_char = t_args->map[t_args->player_x][t_args->player_y];
	if (player_char == 'W')
		t_args->dir_x = -1;
	else if (player_char == 'E')
		t_args->player_x = 1;
	else if (player_char == 'N')
	{
		t_args->player_x = 0;
		t_args->player_y = 1;
	}
	else if (player_char == 'S')
	{
		t_args->player_x = 0;
		t_args->player_y = -1;
	}
}