/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:01:53 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/09 19:52:31 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void	ft_get_player_dir(t_args *t_args)
{
	t_args->player_chr = t_args->map[t_args->player_x][t_args->player_y];
}
