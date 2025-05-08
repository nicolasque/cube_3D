/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:09:39 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/08 20:24:13 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "colors.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define ESC_KEY 65307
# define MOVE_SPEED 0.1
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define FAIL -2
# define MAX_MAP 4000

typedef struct s_args
{
	char			*file_name;
	int				fd_file;

	char			**content;

	int				flor_color[3];
	int				cealing_color[3];

	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;

	char			**map;
	char			**map_cpy;
	int				map_heigth;
	int				map_with;
	char			player_chr;
	int				player_x;
	int				player_y;
	uint32_t		roof_color;
	uint32_t		floor_color;
}					t_args;

typedef struct s_structure
{
	t_args			*t_args;
	int				**map;
	int				map_width;
	int				map_height;

	double			screen_height;
	double			screen_width;
	mlx_image_t		*img;
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture_n;
	mlx_texture_t	*texture_s;
	mlx_texture_t	*texture_w;
	mlx_texture_t	*texture_e;
	int				tex_x;
	int				tex_y;

	uint32_t		roof_color;
	uint32_t		floor_color;

	double			player_x;
	double			player_y;

	double			dir_x;
	double			dir_y;

	double			camera_x;
	double			camera_y;

	double			ray_dir_x;
	double			ray_dir_y;

	double			delta_dist_x;
	double			desta_dist_y;

	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				side;

	int				map_x;
	int				map_y;

	double			dist[2];

	char			direction;
	int				line_height;

}					t_structure;

// PARSEO

int					ft_get_file_data(int argc, char **argv, t_args *t_args);
int					ft_get_data(t_args *t_args);
int					ft_get_color_code(t_args *t_args, int color_code[3],
						const char *code);
int					ft_get_textures(t_args *t_args);
int					ft_get_map(t_args *t_args);
int					ft_check_map(t_args *t_args);
int					ft_file_long(t_args *t_args);
int					ft_isplayer(char c);
int					ft_isplayer_pos(t_args *t_args, char c, int x, int y);
int					ft_check_map_chars(t_args *t_args, char **map);
void				ft_copy_map(t_args *t_args);
void				ft_get_player_dir(t_args *t_args);
// PRINTS

void				ft_print_map(char *str);
// UTILS

char				*ft_strjoin_clean_s1(char *s1, char *s2);
char				*ft_strjoin_clean_s2(char *s1, char *s2);
char				*ft_strjoin_clean_s1_s2(char *s1, char *s2);
void				ft_delete_jump(t_args *t_args);
int					ft_extension_cheker(char *file, const char *extension);
// RENDER

void				render(void *param);
void				start_structure(t_structure *game, t_args *t_args);
// KEY_MANAGEMENT

void				key_press(mlx_key_data_t keydata, void *param);
int					key_free(int keycode, t_structure *game);
void				key_press(mlx_key_data_t keydata, void *param);
void				key_press_negative(mlx_key_data_t keydata,
						t_structure *game);
void				key_press_positive(mlx_key_data_t keydata,
						t_structure *game);
// MAKE_MAP

void				free_memory(t_structure *game);
int					make_map(t_structure *game);
int					saved_map(t_structure *game, int fd);
// DIRECTION
void				choose_direction_2(t_structure *game, char direction);
void				choose_direction(t_structure *game, char direction);

// paint, move starfe
void				draw_background(t_structure *game, int x);
void				rotate_player(t_structure *game, double rot_speed);
void				move_forward(t_structure *game);
void				move_backward(t_structure *game);
void				move_right(t_structure *game);
void				strafe_player(t_structure *game, int direction);
void				pain_map_position(t_structure *game);
int					close_window(t_structure *game);
uint32_t			get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y);


// RENDER_2
int					perform_dda(t_structure *game, double *side_dist_x, double *side_dist_y);
void				init_dda(t_structure *game, double *side_dist_x, double *side_dist_y);
void				get_ray_direction(t_structure *g, double camera_x);
uint32_t			get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y);
void				calculate_wall_data(t_structure *game, double *dist, double *wall_x);

#endif // CUBE_3D_H