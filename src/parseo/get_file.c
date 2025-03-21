/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:07:43 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/21 01:48:35 by nquecedo         ###   ########.fr       */
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
	return (0);
}

static int ft_read_file(t_args *t_args)
{
	char *line;
	char *tmp;

	line = ft_strdup("\0");
	tmp = get_next_line(t_args->fd_file);
	if (!tmp)
		return (FAIL);
	while (tmp)
	{
		line = ft_strjoin_clean_s1_s2(tmp, line);
		tmp = get_next_line(t_args->fd_file);
	}
	t_args->content = ft_split(line, '\n');
	ft_memdel(line);
	return (0);
}

int	ft_get_file_data(int argc, char **argv, t_args *t_args)
{
	if (ft_arg_cheker(argc, argv, t_args))
		return (FAIL);
	if (ft_read_file(t_args))
		return (FAIL);
	if (ft_get_data(t_args))
		return (FAIL);
	return (0);
}