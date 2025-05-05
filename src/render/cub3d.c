/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:08:31 by mikegonz          #+#    #+#             */
/*   Updated: 2025/03/15 11:12:45 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void start_structure(t_structure *game, t_args *t_args)
{
	game->t_args = t_args;
	game->screen_width = WINDOW_WIDTH;
	game->screen_height = WINDOW_HEIGHT;
	game->map_width = t_args->map_with;
	game->map_height = t_args->map_heigth;
	game->roof_color = t_args->roof_color;
	game->floor_color = t_args->floor_color;
	game->player_x = t_args->player_x;
	game->player_y = t_args->player_y;
	game->direction = t_args->player_chr;
	game->map_x = 0;
	game->map_y = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->dist[0] = 0;
	game->dist[1] = 0;
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D G4M3", true);
	// TODO PROTEGER LAS TEXTURAS 
	game->texture_N = mlx_load_png(t_args->no_path);
	game->texture_E = mlx_load_png(t_args->ea_path);
	game->texture_S = mlx_load_png(t_args->so_path);
	game->texture_W = mlx_load_png(t_args->we_path);
	game->img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	choose_direction(game, game->direction);
	make_map(game);
}

void draw_background(t_structure *game, int x)
{
	int i;
	
	i = -1;
	while (++i < game->screen_height)
	{
		x = -1;
		while (++x < game->screen_width)
		{
			if (i < (game->screen_height /2))
				mlx_put_pixel(game->img, x, i, game->floor_color);
			else
				mlx_put_pixel(game->img, x, i, game->roof_color);

		}
	}
}

void rotate_player(t_structure *game, double rot_speed)
{
    double old_dir_x = game->dir_x;
    double old_camera_x = game->camera_x;

    // Rotar dirección del jugador
    game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
    game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);

    // Rotar plano de la cámara
    game->camera_x = game->camera_x * cos(rot_speed) - game->camera_y * sin(rot_speed);
    game->camera_y = old_camera_x * sin(rot_speed) + game->camera_y * cos(rot_speed);
}

void strafe_player(t_structure *game, int direction)
{
    double strafe_x = game->dir_y * direction;
    double strafe_y = -game->dir_x * direction;
    double new_x = game->player_x + strafe_x * MOVE_SPEED;
    double new_y = game->player_y + strafe_y * MOVE_SPEED;
    
    // Comprobaciones separadas para permitir deslizarse por las paredes
    // Sin verificación diagonal que cancele todo el movimiento
    if (game->map[(int)game->player_y][(int)new_x] == 0)
        game->player_x = new_x;
    if (game->map[(int)new_y][(int)game->player_x] == 0)
        game->player_y = new_y;
}

int close_window(t_structure *game)
{
	// mlx_clear_window(game->mlx, game->windows);
	mlx_close_window(game->mlx);
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_texture(game->texture);
	mlx_terminate(game->mlx);
	free_memory(game);
	exit(0);
}

// int main(void)
// {
// 	t_structure game;

// 	start_structure(&game);
// 	mlx_image_to_window(game.mlx, game.img, 0, 0);
// 	mlx_key_hook(game.mlx, &key_press, &game);
// 	mlx_loop_hook(game.mlx, &render, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }