/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:40:18 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/27 23:46:36 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

char **ft_copy_map(t_args *t_args)
{
	int i;
	char **map_cpy;

	map_cpy = (char **)malloc(sizeof(char *) * (t_args->heig + 1));
	i = 0;
	while (t_args->map[i])
	{
		map_cpy[i] = ft_strdup(t_args->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int ft_check_map(t_args *t_args)
{
	char **map_cpy;

	map_cpy = ft_copy_map(t_args);
	for (int i = 0; map_cpy[i]; i++)
		printf("COPY: %s\n", map_cpy[i]);

	return (0);
}