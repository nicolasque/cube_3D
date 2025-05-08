/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension_cheker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:19:06 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/08 20:31:14 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_extension_cheker(char *file, const char *extension)
{
	if (ft_strnstr(file, extension, ft_strlen(extension)))
	{
		return (0);
	}
	return (0);
}
