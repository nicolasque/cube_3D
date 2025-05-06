/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:57:55 by mikegonz          #+#    #+#             */
/*   Updated: 2025/05/06 15:05:41 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

uint32_t	get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t	index;
	uint8_t		r, g, b, a;

	index = (tex_y * texture->width + tex_x) * 4;
	if (index >= texture->width * texture->height * 4)
		return (0xFF000000);
	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
void	get_ray_direction(t_structure *g, double camera_x)
{
	g->ray_dir_x = g->dir_x + g->camera_x * camera_x;
	g->ray_dir_y = g->dir_y + g->camera_y * camera_x;
}
void	init_dda(t_structure *g, int *map_x, int *map_y, double *side_dist_x, double *side_dist_y)
{
	*map_x = (int)g->player_x;
	*map_y = (int)g->player_y;
	g->dist[0] = fabs(1 / g->ray_dir_x);
	g->dist[1] = fabs(1 / g->ray_dir_y);
	if (g->ray_dir_x < 0)
	{
		g->step_x = -1;
		*side_dist_x = (g->player_x - *map_x) * g->dist[0];
	}
	else
	{
		g->step_x = 1;
		*side_dist_x = (*map_x + 1.0 - g->player_x) * g->dist[0];
	}
	if (g->ray_dir_y < 0)
	{
		g->step_y = -1;
		*side_dist_y = (g->player_y - *map_y) * g->dist[1];
	}
	else
	{
		g->step_y = 1;
		*side_dist_y = (*map_y + 1.0 - g->player_y) * g->dist[1];
	}
}

int	perform_dda(t_structure *g, int *map_x, int *map_y,
		double *side_dist_x, double *side_dist_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (*side_dist_x < *side_dist_y)
		{
			*side_dist_x += g->dist[0];
			*map_x += g->step_x;
			g->side = 0;
		}
		else
		{
			*side_dist_y += g->dist[1];
			*map_y += g->step_y;
			g->side = 1;
		}
		if (g->map[*map_y][*map_x] > 0)
			hit = 1;
	}
	return (g->side);
}

void	calculate_wall_data(t_structure *g, int map_x, int map_y,
		double *dist, double *wall_x, int *line_height)
{
	if (g->side == 0)
		*dist = (map_x - g->player_x + (1 - g->step_x) / 2)
			/ g->ray_dir_x;
	else
		*dist = (map_y - g->player_y + (1 - g->step_y) / 2)
			/ g->ray_dir_y;
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

void	draw_textured_line(t_structure *g, int x, int line_height,
		int side, mlx_texture_t *texture, double wall_x)
{
	int		start = (g->screen_height - line_height) / 2;
	int		end = (g->screen_height + line_height) / 2;
	int		i, tex_x, tex_y;
	double	step, tex_pos;

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
void	render_column(t_structure *g, int x)
{
	double	camera_x = 2 * x / (double)g->screen_width - 1;
	double	side_x, side_y, wall_x, dist;
	int		map_x, map_y, height;

	get_ray_direction(g, camera_x);
	init_dda(g, &map_x, &map_y, &side_x, &side_y);
	perform_dda(g, &map_x, &map_y, &side_x, &side_y);
	calculate_wall_data(g, map_x, map_y, &dist, &wall_x, &height);
	select_texture(g);
	draw_textured_line(g, x, height, g->side, g->texture, wall_x);
}
void	render(void *param)
{
	t_structure	*game = (t_structure *)param;
	int			x;

	x = 0;
	while (x < game->screen_width)
	{
		render_column(game, x);
		x++;
	}
}


