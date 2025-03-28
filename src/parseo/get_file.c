/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:07:43 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/28 03:22:58 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int	ft_arg_cheker(int argc, char **argv, t_args *t_args)
{
	if (argc != 2)
		return (printf("%sArguments, error \n%s", RED, RESET), FAIL);
	argv++;
	t_args->file_name = *argv;
	t_args->fd_file = open(t_args->file_name, O_RDONLY);
	if (t_args->fd_file < 0)
		return (printf("%sFile doesent exist \n%s", RED, RESET), FAIL);
	close(t_args->fd_file);
	return (0);
}

static int ft_file_long(t_args *t_args)
{
	int file_long;
	char *line;
	
	t_args->fd_file = open(t_args->file_name, O_RDONLY);
	file_long = 0;
	line = get_next_line(t_args->fd_file);
	if (!line || ft_strlen(line) == 0)
	return (ft_memdel(line), FAIL);
	while (line)
	{
		line = get_next_line(t_args->fd_file);
		ft_memdel(line);
		file_long ++;
		
	}
	close(t_args->fd_file);
	return (file_long);
}


static int ft_read_file(t_args *t_args)
{
	int file_long;
	int i;

	i = 0;
	file_long = ft_file_long(t_args);
	t_args->fd_file = open(t_args->file_name, O_RDONLY);
	t_args->content = (char **)malloc(sizeof(char *) * (file_long + 1));
	while (i < file_long)
	{
		t_args->content[i] = get_next_line(t_args->fd_file);
		i++;
	}
	t_args->content[i] = NULL;
	close(t_args->fd_file);
	return (0);
}

int	ft_get_file_data(int argc, char **argv, t_args *t_args)
{
	if (ft_arg_cheker(argc, argv, t_args))
		return (FAIL);
	if (ft_read_file(t_args))
		return (FAIL);
	for (int i = 0; t_args->content[i]; i++)
		printf("CONTENT: %s", t_args->content[i]);
	if (ft_get_data(t_args))
		return (FAIL);
	if (ft_get_map(t_args))
		return (printf("%sMap error%s\n", RED, RESET), 1);
	return (0);
}