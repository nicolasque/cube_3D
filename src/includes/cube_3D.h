/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:09:39 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/21 02:11:12 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUBE_3D_H
# define CUBE_3D_H

# include "colors.h"
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <math.h>

# define FAIL 2

typedef struct s_args
{
	char *file_name;
	int fd_file;

	char **content;

	int flor_color[3];
	int cealing_color[3];
}	t_args;


// PARSEO
int	ft_get_file_data(int argc, char **argv, t_args *t_args);
int	ft_get_data(t_args *t_args);
int	ft_get_color_code(t_args *t_args, const char *code);


// PRINTS
void ft_print_map(char *str);


// UTILS
char	*ft_strjoin_clean_s1(char *s1, char *s2);
char	*ft_strjoin_clean_s2(char *s1, char *s2);
char	*ft_strjoin_clean_s1_s2(char *s1, char *s2);


#endif // CUBE_3D_H