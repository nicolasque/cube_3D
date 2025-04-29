/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:23:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/04/29 15:26:15 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static void	ft_color_to_hexa(t_args *t_args)
{
	unsigned long int	alpha;

	// Valor alfa máximo (0xFF - completamente opaco)
	alpha = 0xFF000000;
	// Combinamos el alfa con los componentes RGB
	t_args->roof_color = alpha | ((unsigned long int)t_args->cealing_color[0] << 16) | ((unsigned long int)t_args->cealing_color[1] << 8) | ((unsigned long int)t_args->cealing_color[2]);
	t_args->floor_color = alpha | ((unsigned long int)t_args->flor_color[0] << 16) | ((unsigned long int)t_args->flor_color[1] << 8) | ((unsigned long int)t_args->flor_color[2]);
	printf("Roof_color: 0x%lX\n", t_args->roof_color);
	printf("Floor_color: 0x%lX\n", t_args->floor_color);
}

int	ft_get_data(t_args *t_args)
{
	if (ft_get_color_code(t_args, t_args->flor_color, "F ")
		|| ft_get_color_code(t_args, t_args->cealing_color, "C "))
		return (FAIL);
	ft_color_to_hexa(t_args);
	if (ft_get_textures(t_args))
		return (printf("%sTexture error %s", RED, RESET), FAIL);

	return (0);
}