/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:03:08 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/05 19:08:03 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void key_press_positive(mlx_key_data_t keydata, t_structure *game)
{
	if (keydata.key == MLX_KEY_LEFT)
		rotate_player(game, 0.5);
	else if (keydata.key == MLX_KEY_RIGHT)
		rotate_player(game, -0.5);
	else if (keydata.key == MLX_KEY_A)
		strafe_player(game, -1);
	else if (keydata.key == MLX_KEY_D)
		strafe_player(game, 1);
}

void key_press_negative(mlx_key_data_t keydata, t_structure *game)
{
	if (keydata.key == MLX_KEY_LEFT)
		rotate_player(game, -0.5);
	else if (keydata.key == MLX_KEY_RIGHT)
		rotate_player(game, 0.5);
	else if (keydata.key == MLX_KEY_A)
		strafe_player(game, 1);
	else if (keydata.key == MLX_KEY_D)
		strafe_player(game, -1);
}

void key_press(mlx_key_data_t keydata, void *param)
{
	t_structure *game;

	game = (t_structure *) param;
	if (keydata.key == MLX_KEY_ESCAPE)// && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		free_memory(game);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_W)
		move_forward(game);
	else if (keydata.key == MLX_KEY_S)
		move_backward(game);

	// AQUI SE REALIZAN LAS PRUEBAS DE DIRECCION
	if (game->direction == 'N' || game->direction == 'S')
		key_press_positive(keydata, game);
	else
		key_press_negative(keydata, game);
	
	
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	draw_background(game, -1);
	pain_map_position(game);
}


int key_free(int keycode, t_structure *game) // Controlador de teclas
{
	(void)game;
	printf("key %d release\n", keycode);
	return (0);
}
