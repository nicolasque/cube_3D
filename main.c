/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:26:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/25 23:53:50 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/includes/cube_3D.h"

void ft_init_args(t_args *t_args)
{
	t_args->file_name = NULL;
	t_args->no_path = NULL;
	t_args->so_path = NULL;
	t_args->we_path = NULL;
	t_args->ea_path = NULL;
    t_args->flor_color[0] = -1;
    t_args->flor_color[1] = -1;
    t_args->flor_color[2] = -1;
    t_args->cealing_color[0] = -1;
    t_args->cealing_color[1] = -1;
    t_args->cealing_color[2] = -1;
}

int	main(int argc, char **argv)
{
	t_args t_args;

	ft_init_args(&t_args);
	if (ft_get_file_data(argc, argv, &t_args))
		return (printf("%sArguments error%s\n", RED, RESET), 1);


	return (0);
}

