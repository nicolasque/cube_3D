/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:26:00 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/09 17:36:16 by nquecedo         ###   ########.fr       */
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
	t_args->map_heigth = 0;
	t_args->player_x = 0;
	t_args->player_y = 0;
	t_args->flor_color[0] = -1;
	t_args->flor_color[1] = -1;
	t_args->flor_color[2] = -1;
	t_args->cealing_color[0] = -1;
	t_args->cealing_color[1] = -1;
	t_args->cealing_color[2] = -1;
	t_args->content = NULL;
	t_args->map = NULL;
	t_args->map_cpy = NULL;
}

void ft_clean_args(t_args *t_args)
{
	if (!t_args)
		return;

	if (t_args->no_path)
		ft_memdel(t_args->no_path);
	if (t_args->so_path)
		ft_memdel(t_args->so_path);
	if (t_args->we_path)
		ft_memdel(t_args->ea_path);
	if (t_args->content)
		ft_free_array(t_args->content);
	if (t_args->map)
		ft_free_array(t_args->map);
	if (t_args->map_cpy)
		ft_free_array(t_args->map_cpy);
}

int main(int argc, char **argv)
{
	t_args t_args;
	t_structure game;

	ft_init_args(&t_args);
	if (ft_get_file_data(argc, argv, &t_args))
		return (printf("%sArguments error%s\n", RED, RESET), ft_clean_args(&t_args), 1);
	start_structure(&game, &t_args);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	mlx_key_hook(game.mlx, &key_press, &game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	return (0);
}
