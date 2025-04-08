/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension_cheker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:19:06 by nquecedo          #+#    #+#             */
/*   Updated: 2025/04/08 17:29:01 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_extension_cheker(char *file, const char *extension)
{
	if (ft_strnstr(file, extension, ft_strlen(extension) + 1))
	{
		return (0);
	}
	else
		printf("%sFile with invalid extension%s\n", YELLOW, RESET);
	return (FAIL);
}
