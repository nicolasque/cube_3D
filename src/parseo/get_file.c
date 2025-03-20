/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:07:43 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/20 21:27:43 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

int	ft_get_file_data(int argc, char **argv, t_args *t_args)
{
	if (argc != 2)
		return (printf("%sArguments, error \n%s", RED, RESET), 1);
	argv++;
	t_args->file_name = *argv;
	return (0);
}