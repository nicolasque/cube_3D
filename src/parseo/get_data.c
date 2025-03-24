/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:23:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/24 17:19:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_get_data(t_args *t_args)
{
	if (ft_get_color_code(t_args, t_args->flor_color, "F ")
		|| ft_get_color_code(t_args, t_args->cealing_color, "C "))
		return (FAIL);
	for (int i = 0; i < 3; i++)
		printf("Color code(int): %d\n", t_args->flor_color[i]);
	printf("\n=========================\n\n");
	for (int i = 0; i < 3; i++)
		printf("Color code(int): %d\n", t_args->cealing_color[i]);
	return (0);
}