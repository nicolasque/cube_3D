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

int saved_map(t_structure *game, int fd)
{
	int i;
	int j;
	char *line;
	(void)fd;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		line = game->t_args->map[i];
		if (!line)
			break;
		game->map[i] = malloc((game->map_width) * sizeof(int));
		if (!game->map[i])
			return (1);
		while (++j < game->map_width)
		{
			if (line[j] != '0' && line[j] != '1')
				line[j] = '1';
		
			game->map[i][j] = line[j] - '0';
		}
		free(line);
	}
	return (0);
}

void free_memory(t_structure *game)
{
	int i;

	i = -1;
	while (++i < game->map_height)
			free(game->map[i]);

	free(game->map);
	game->map = NULL;
}
int make_map(t_structure *game)
{
	int fd;
	(void)game;
	
	// // fd = open("map", O_RDONLY);
	// if (fd < 0)
	// {
	// 	perror("Error open file");
	// 	return (1);
	// }
	game->map = malloc(game->map_height * sizeof(int *));
	if (!game->map)
		return (1);
	fd = 0;
	if (saved_map(game, fd))
	{
		free_memory(game);
		printf("map error!\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
void choose_direction_2(t_structure *game, char direction)
{
	if (direction == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->camera_x = -0.66;
		game->camera_y = 0;
	}
	else if (direction == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->camera_x = 0.66;
		game->camera_y = 0;
	}
}

void choose_direction(t_structure *game, char direction)
{
	if (direction == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->camera_x = 0;
		game->camera_y = 0.66;
	}
	else if (direction == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->camera_x = 0;
		game->camera_y = -0.66;
	}
	else
		choose_direction_2(game, direction);

}
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
	game->texture_N = mlx_load_png("src/includes/textures/texture_N.png");
	game->texture_E = mlx_load_png("src/includes/textures/texture_E.png");
	game->texture_S = mlx_load_png("src/includes/textures/texture_S.png");
	game->texture_W = mlx_load_png("src/includes/textures/texture_W.png");
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

void move_forward(t_structure *game)
{
    double new_x = game->player_x + game->dir_x * MOVE_SPEED;
    double new_y = game->player_y + game->dir_y * MOVE_SPEED;
    
    // Comprobaciones separadas para permitir deslizarse por las paredes
    // Sin verificación diagonal que cancele todo el movimiento
    if (game->map[(int)game->player_y][(int)new_x] == 0)
        game->player_x = new_x;
    if (game->map[(int)new_y][(int)game->player_x] == 0)
        game->player_y = new_y;
}

void move_backward(t_structure *game)
{
    double new_x = game->player_x - game->dir_x * MOVE_SPEED;
    double new_y = game->player_y - game->dir_y * MOVE_SPEED;
    
    // Comprobaciones separadas para permitir deslizarse por las paredes
    // Sin verificación diagonal que cancele todo el movimiento
    if (game->map[(int)game->player_y][(int)new_x] == 0)
        game->player_x = new_x;
    if (game->map[(int)new_y][(int)game->player_x] == 0)
        game->player_y = new_y;
}

void move_right(t_structure *game)
{
	if (game->map[(int)(game->player_y)][(int)(game->player_x - game->dir_x * MOVE_SPEED)] == 0)
        game->player_x -= game->dir_x * MOVE_SPEED;
    if (game->map[(int)(game->player_y + game->dir_y * MOVE_SPEED)][(int)(game->player_x)] == 0)
        game->player_y += game->dir_y * MOVE_SPEED;
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

//PINTAMOS EL MAPA EN LA TERMINAL
void	pain_map_position(t_structure *game)
{
	static int current_x;
	static int current_y;

	int i = -1;
	if (current_x != (int)game->player_x || current_y != (int)game->player_y)
	{
		while (++i < game->map_height)
		{
			int j = -1;
			while (++j < game->map_width)
			{
				if (i == (int)game->player_y && j == (int)game->player_x)
					printf("X");
				else	
					printf("%i", game->map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	current_x = (int)game->player_x;
	current_y = (int)game->player_y;
}
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