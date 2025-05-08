/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_jump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 05:45:41 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/08 20:32:30 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void	ft_delete_jump(t_args *t_args)
{
	int	file_long;
	int	i;

	i = 0;
	file_long = ft_file_long(t_args);
	while (i < file_long)
	{
		if (ft_strlen(t_args->content[i]))
			t_args->content[i][ft_strlen(t_args->content[i]) - 1] = '\0';
		i++;
	}
}
