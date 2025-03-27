/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:29:51 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/27 23:38:05 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int ft_check_line(char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0' && str[i] != 'N')
			return (1);
		i ++;
	}
	return (0);
}

static int	ft_map_len(char **content)
{
	int	map_len;

	map_len = 0;
	while (!ft_check_line(content[map_len]))
	{
		// printf("%s\n", content[map_len]);
		map_len++;
	}
	return (map_len);
}

static int	ft_copy_map(t_args *t_args)
{
	int i;
	
	i = 0;
	while (i < t_args->heig)
	{
		t_args->map[i] = ft_strdup(t_args->content[i]);
		i++;
	}
	t_args->map[i] = NULL;
	return (0);
}

int	ft_get_map(t_args *t_args)
{
	
	t_args->heig = ft_map_len(t_args->content);
	t_args->map = (char **)malloc(sizeof(char *) * (t_args->heig + 1));
	ft_copy_map(t_args);

	for (int i = 0; i < t_args->heig; i++)
		printf("MAPA: %s\n", t_args->map[i]);
	return (0);
}
