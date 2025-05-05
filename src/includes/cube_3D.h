/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:09:39 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/05 19:16:07 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "colors.h"
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <math.h>
# include <memory.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

// Code of keys in X11
# define ESC_KEY 65307
// #define A 97
// #define W 119
// #define S 115
// #define D 100
# define left_arrow 65361
# define right_arrow 65363
# define MOVE_SPEED 0.1
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define FAIL -2
# define MAX_MAP 4000

typedef struct s_args
{
	char	*file_name;
	int		fd_file;

	char	**content;

	int		flor_color[3];
	int		cealing_color[3];

	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	char	**map;
	char	**map_cpy;
	int		map_heigth;
	int		map_with;
	char	player_chr;
	int		player_x;
	int		player_y;
	uint32_t roof_color;  // Color del techo
	uint32_t floor_color; // Color del suelo
}			t_args;

typedef struct s_structure
{
	t_args *t_args;
	int		**map;
	int map_width;  // Ancho del mapa
	int map_height; // Alto del mapa

	double screen_height; // Ancho de la ventana
	double screen_width;  // Alto de la ventana
	mlx_image_t *img;     // Dimensiones de la imagen
	mlx_t	*mlx;
	mlx_texture_t *texture;   // Imagen PNG
	mlx_texture_t *texture_N; // Imagen PNG
	mlx_texture_t *texture_S; // Imagen PNG
	mlx_texture_t *texture_W; // Imagen PNG
	mlx_texture_t *texture_E; // Imagen PNG
	// void	*mlx;
	// void	*windows;
	uint32_t roof_color;  // Color del techo
	uint32_t floor_color; // Color del suelo

	// Plano de camara para calcular el campo de vision
	double	player_x;
	double	player_y;

	// Direccion del jugador (mirando hacia la derecha)
	double dir_x; // dir_x = 1
	double dir_y; // dir_y = 0

	// Plano de la camara para calcular el campo de vision
	double	camera_x;
	double	camera_y;

	// Ray direction
	double	ray_dir_x;
	double	ray_dir_y;

	double delta_dist_x;
		// Distancia necesaria para moverse de una línea vertical a la siguiente en la cuadrícula.
	double desta_dist_y;
		// Distancia necesaria para moverse de una línea horizontal a la siguiente.

	// distancia desde la posición del jugador hasta la primera intersección con una celda.
	double	side_dist_X;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int side; // 0 si golpea una pared vertical, 1 si horizontal

	// Cordenadas del mapa actual en el DDA
	int		map_x;
	int		map_y;

	// Distancias (precomputadas para optimezar DDA)
	double	dist[2];

	char	direction;

}			t_structure;

// PARSEO
int			ft_get_file_data(int argc, char **argv, t_args *t_args);
int			ft_get_data(t_args *t_args);
int			ft_get_color_code(t_args *t_args, int color_code[3],
				const char *code);
int			ft_get_textures(t_args *t_args);
int			ft_get_map(t_args *t_args);
int			ft_check_map(t_args *t_args);
int			ft_file_long(t_args *t_args);
int			ft_isplayer(char c);
int			ft_isplayer_pos(t_args *t_args, char c, int x, int y);
int			ft_check_map_chars(t_args *t_args, char **map);
void		ft_copy_map(t_args *t_args);
void		ft_get_player_dir(t_args *t_args);

// PRINTS
void		ft_print_map(char *str);

// UTILS
char		*ft_strjoin_clean_s1(char *s1, char *s2);
char		*ft_strjoin_clean_s2(char *s1, char *s2);
char		*ft_strjoin_clean_s1_s2(char *s1, char *s2);
void		ft_delete_jump(t_args *t_args);
int			ft_extension_cheker(char *file, const char *extension);

// RENDER
void	render(void *param);
void start_structure(t_structure *game, t_args *t_args);

// KEY_MANAGEMENT
void key_press(mlx_key_data_t keydata, void *param);
int key_free(int keycode, t_structure *game);
void key_press(mlx_key_data_t keydata, void *param);
void key_press_negative(mlx_key_data_t keydata, t_structure *game);
void key_press_positive(mlx_key_data_t keydata, t_structure *game);

//MAKE_MAP
void free_memory(t_structure *game);
int make_map(t_structure *game);
int saved_map(t_structure *game, int fd);

//DIRECTION
void choose_direction_2(t_structure *game, char direction);
void choose_direction(t_structure *game, char direction);


// paint, move starfe
void draw_background(t_structure *game, int x);
void rotate_player(t_structure *game, double rot_speed);
void move_forward(t_structure *game);
void move_backward(t_structure *game);
void move_right(t_structure *game);
void strafe_player(t_structure *game, int direction);
void	pain_map_position(t_structure *game);
int close_window(t_structure *game);
















#endif // CUBE_3D_H