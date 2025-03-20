/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:07:43 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/20 21:58:17 by nquecedo         ###   ########.fr       */
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
	printf("Get_next_line: %s", get_next_line(t_args->fd_file));
	return (0);
}

int	ft_get_file_data(int argc, char **argv, t_args *t_args)
{
	if (ft_arg_cheker(argc, argv, t_args))
		return (FAIL);

	return (0);
}