/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:17:45 by nquecedo          #+#    #+#             */
/*   Updated: 2025/05/06 18:06:41 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void	calculate_wall_data(t_structure *g, int map_x, int map_y, double *dist,
		double *wall_x, int *line_height)
{
	if (g->side == 0)
		*dist = (map_x - g->player_x + (1 - g->step_x) / 2) / g->ray_dir_x;
	else
		*dist = (map_y - g->player_y + (1 - g->step_y) / 2) / g->ray_dir_y;
	*line_height = (int)(g->screen_height / *dist);
	if (g->side == 0)
		*wall_x = g->player_y + *dist * g->ray_dir_y;
	else
		*wall_x = g->player_x + *dist * g->ray_dir_x;
	*wall_x -= floor(*wall_x);
}

void	select_texture(t_structure *g)
{
	if (g->side == 0)
		g->texture = (g->step_x == 1) ? g->texture_w : g->texture_e;
	else
		g->texture = (g->step_y == 1) ? g->texture_s : g->texture_n;
}

void	draw_textured_line(t_structure *g, int x, int line_height, int side,
		mlx_texture_t *texture, double wall_x)
{
	int	start;
	int	end;
	int i;
	int tex_x;
	int tex_y;
	double step;
	double tex_pos;

	start = (g->screen_height - line_height) / 2;
	end = (g->screen_height + line_height) / 2;
	if (start < 0)
		start = 0;
	if (end >= g->screen_height)
		end = g->screen_height - 1;
	tex_x = (int)(wall_x * texture->width);
	if ((side == 0 && g->ray_dir_x > 0) || (side == 1 && g->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->height / line_height;
	tex_pos = (start - g->screen_height / 2 + line_height / 2) * step;
	i = start;
	while (i < end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		mlx_put_pixel(g->img, x, i, get_texture_color(texture, tex_x, tex_y));
		i++;
	}
}
