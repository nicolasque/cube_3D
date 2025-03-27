/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:29:51 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/27 19:04:36 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int ft_map_len(char **content, int file_len)
{
	int map_len;

	map_len = 0;
	while (content[file_len][0] != '\n')
	{
		file_len --;
		map_len ++;
	}
	return (map_len);
}

int ft_get_map(t_args *t_args)
{
	int file_len;

	file_len = 0;
	while (t_args->content[file_len])
		file_len ++;
	t_args->heig = ft_map_len(t_args->content, file_len);
	
	return (0);
}
