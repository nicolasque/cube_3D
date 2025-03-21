/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:23:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/21 02:18:47 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_get_data(t_args *t_args)
{
	if (ft_get_color_code(t_args, "F ")
		|| ft_get_color_code(t_args, "C "))
		return (FAIL);

	return (0);
}