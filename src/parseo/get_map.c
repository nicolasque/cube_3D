/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:29:51 by nquecedo          #+#             */
/*   Updated: 2025/03/29 15:59:22 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int ft_get_map_long(t_args *t_args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (t_args->content[i + 1])
		i++;
	while (t_args->content[i] && t_args->content[i][0] != '\n')
	{
		i--;
		j++;
	}
	return (j);
}

int ft_get_longest_line(t_args *t_args)
{
	int longest;
	int i;
	int j;

	i = 0;
	j = 0;
	longest = 0;
	while (t_args->content[i + 1])
		i++;
	while (t_args->content[i] && t_args->content[i][0] != '\n')
	{
		if ((int)ft_strlen(t_args->content[i]) > longest)
			longest = ft_strlen(t_args->content[i]);
		i--;
		j++;
	}
	return (longest);
}

int ft_reserve_map_space(t_args *t_args)
{
	int i;

	i = 0;
	t_args->map = (char **)malloc(sizeof(char *) * (t_args->map_heigth + 1));
	while (i < t_args->map_heigth)
	{
		t_args->map[i] = (char *)malloc(sizeof(char) * (t_args->map_with + 2));
		ft_memset(t_args->map[i], ' ', t_args->map_with - 1);
		t_args->map[i][t_args->map_with] = '\0';
		i++;
	}
	t_args->map[i] = NULL;
	return (0);
}

static void ft_copy_map_file(t_args *t_args)
{
	int i;
	int map_index;

	i = 0;
	map_index = t_args->map_heigth - 1; // Empezamos desde el final del mapa

	// Ir al final del contenido
	while (t_args->content[i + 1])
		i++;

	// Copiar cada línea del mapa
	while (t_args->content[i] && t_args->content[i][0] != '\n' && map_index >= 0)
	{
		ft_memcpy(t_args->map[map_index], t_args->content[i],
				  (ft_strlen(t_args->content[i]) - 1));
		i--;
		map_index--;
	}
}

int ft_get_map(t_args *t_args)
{

	for (int i = 0; t_args->content[i]; i++)
		printf("CONTENT: %s", t_args->content[i]);

	t_args->map_heigth = ft_get_map_long(t_args);
	t_args->map_with = ft_get_longest_line(t_args);
	ft_reserve_map_space(t_args);
	// PRINT MAP
	for (int i = 0; t_args->map[i]; i++)
		printf("MAP_APACE: %s\n", t_args->map[i]);

	ft_copy_map_file(t_args);
	// for (int i = 0; t_args->map[i]; i++)
	// 	printf("MAP: %s\n", t_args->map[i]);
	ft_check_map(t_args);

	return (0);
}
