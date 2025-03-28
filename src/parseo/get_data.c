/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:23:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 04:54:08 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_get_data(t_args *t_args)
{
	if (ft_get_color_code(t_args, t_args->flor_color, "F ")
		|| ft_get_color_code(t_args, t_args->cealing_color, "C "))
		return (FAIL);
	if (ft_get_textures(t_args))
		return (printf("%sTexture error %s", RED, RESET), FAIL);
	
	return (0);
}