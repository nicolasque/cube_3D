/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:04:12 by nquecedo          #+#    #+#             */
/*   Updated: 2025/03/24 17:17:23 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

static int	ft_check_color_code(char *color_str, const char *code)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (color_str[i])
	{
		if (color_str[i] == ',')
			comma_count++;
		if (color_str[i] != code[0] && color_str[i] != ' '
			&& color_str[i] != ',' && !ft_isdigit(color_str[i]))
			return (printf("%sInvalid color code (invalid characters)\n%s", RED,
					RESET), FAIL);
		i++;
	}
	if (comma_count != 2)
		return (printf("%sInvalid color code.\n%s", RED, RESET), FAIL);
	return (0);
}

static int	ft_get_color_nbr(char *color_code_str, int color_code[3])
{
	int		i;
	int		j;
	char	**spliteado;

	i = 0;
	spliteado = ft_split(color_code_str, ',');
	while (spliteado[i])
	{
		j = 0;
		while (spliteado[i][j])
		{
			if (ft_isdigit(spliteado[i][j]))
			{
				color_code[i] = ft_atoi(((spliteado[i])) + j);
				if (color_code[i] > 255)
					return (ft_free_array(spliteado), FAIL);
				break ;
			}
			j++;
		}
		i++;
	}
	ft_free_array(spliteado);
	return (0);
}

// Esta funcion ya es llamada dos veces, una para techo y otra para suelo
int	ft_get_color_code(t_args *t_args, int color_code[3], const char *code)
{
	char	*color_code_str;
	int		i;

	i = 0;
	while (t_args->content[i])
	{
		if (ft_strnstr(t_args->content[i], code, ft_strlen(t_args->content[i])))
		{
			color_code_str = ft_strdup(ft_strnstr(t_args->content[i], code,
						ft_strlen(t_args->content[i])));
		}
		i++;
	}
	if (ft_check_color_code(color_code_str, code))
		return (FAIL);
	printf("Color, code: %s\n", color_code_str);
	if (ft_get_color_nbr(color_code_str, color_code))
		return (printf("%sInvalid color code%s\n", RED, RESET), FAIL);
	return (0);
}
