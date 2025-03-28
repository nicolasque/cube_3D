/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:29:51 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 05:00:06 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int	ft_copy_map(t_args *t_args)
{
	char *map[MAX_MAP];
	int	i;
	int j;

	i = 0;
	j = 0;
	t_args->map = map;
	while (t_args->content[i + 1])
		i++;
	while (t_args->content[i] && t_args->content[i][0] != '\n')
	{
		t_args->map[j] = ft_strdup(t_args->content[i]);
		i--;
		j++;
	}
	t_args->map[j] = NULL;
	return (0);
}

int	ft_get_map(t_args *t_args)
{
	ft_copy_map(t_args);
	for (int i = 0;t_args->map[i] ; i++)
		printf("MAPA: %s", t_args->map[i]);

	ft_check_map(t_args);

	return (0);
}
