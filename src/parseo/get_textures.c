/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:53:44 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 01:01:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static char	*ft_chech_paths(char *path_line)
{
	int	fd;

	if (!path_line)
		return (NULL);
	while (*path_line && *path_line == ' ')
		path_line++;
	fd = open(path_line, O_RDONLY);
	if (fd == -1)
		return (printf("%s%s : does not exists\n%s", YELLOW, path_line, RESET),
			NULL);
	close(fd);
	return (path_line);
}

static int	ft_get_paths(t_args *t_args)
{
	int	i;
	int j;

	i = 0;
	while (t_args->content[i])
	{
		if (t_args->content[i])
		{
			j = 0;
			while (t_args->content[i][j] && ft_isspace(t_args->content[i][j]))
				j++;
		}
		if (ft_strnstr(t_args->content[i], "NO ", 3 + j))
			t_args->no_path = ft_chech_paths(t_args->content[i] + 3 + j);
		if (ft_strnstr(t_args->content[i], "SO ", 3 + j))
			t_args->so_path = ft_chech_paths(t_args->content[i] + 3 + j);
		if (ft_strnstr(t_args->content[i], "WE ", 3 + j))
			t_args->we_path = ft_chech_paths(t_args->content[i] + 3 + j);
		if (ft_strnstr(t_args->content[i], "EA ", 3 + j))
			t_args->ea_path = ft_chech_paths(t_args->content[i] + 3 + j);
		i++;
	}
	return (0);
}

int	ft_get_textures(t_args *t_args)
{
	ft_get_paths(t_args);
	if (!t_args->no_path || !t_args->so_path || !t_args->we_path
		|| !t_args->ea_path)
		return (FAIL);
	printf("NO: %s\n", t_args->no_path);
	printf("SO: %s\n", t_args->so_path);
	printf("WE: %s\n", t_args->we_path);
	printf("EA: %s\n", t_args->ea_path);
	return (0);
}
