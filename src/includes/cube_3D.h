/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:09:39 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/29 15:29:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
#define CUBE_3D_H

#include "colors.h"
#include "libft/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

#define FAIL -2
#define MAX_MAP 4000

typedef struct s_args
{
	char *file_name;
	int fd_file;

	char **content;

	int flor_color[3];
	int cealing_color[3];

	char *no_path;
	char *so_path;
	char *we_path;
	char *ea_path;

	char **map;
	char **map_cpy;
	int map_heigth;
	int map_with;
	int player_x;
	int player_y;
	int heig;
} t_args;

// PARSEO
int ft_get_file_data(int argc, char **argv, t_args *t_args);
int ft_get_data(t_args *t_args);
int ft_get_color_code(t_args *t_args, int color_code[3],
					  const char *code);
int ft_get_textures(t_args *t_args);
int ft_get_map(t_args *t_args);
int ft_check_map(t_args *t_args);
int ft_file_long(t_args *t_args);
int ft_isplayer(char c);
int ft_isplayer_pos(t_args *t_args, char c, int x, int y);
int ft_check_map_chars(t_args *t_args, char **map);
void ft_copy_map(t_args *t_args);

// PRINTS
void ft_print_map(char *str);

// UTILS
char *ft_strjoin_clean_s1(char *s1, char *s2);
char *ft_strjoin_clean_s2(char *s1, char *s2);
char *ft_strjoin_clean_s1_s2(char *s1, char *s2);
void ft_delete_jump(t_args *t_args);

#endif // CUBE_3D_H