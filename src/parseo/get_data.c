/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:23:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/09 17:37:03 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static void	ft_color_to_hexa(t_args *t_args)
{
	uint32_t	alpha;

	alpha = 0xFF000000;
	t_args->roof_color = ((unsigned long int)t_args->cealing_color[0] << 16) | \
	((unsigned long int)t_args->cealing_color[1] << 8) | \
	((unsigned long int)t_args->cealing_color[2]) | alpha;
	t_args->floor_color = ((unsigned long int)t_args->flor_color[0] << 16) | \
	((unsigned long int)t_args->flor_color[1] << 8) | \
	((unsigned long int)t_args->flor_color[2]) | alpha;
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
