/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:16:48 by mikegonz          #+#    #+#             */
/*   Updated: 2025/05/08 19:29:27 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

uint32_t	get_texture_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t	index;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

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

void	init_dda(t_structure *game, double *side_dist_x, double *side_dist_y)
{
	game->map_x = (int)game->player_x;
	game->map_y = (int)game->player_y;
	game->dist[0] = fabs(1 / game->ray_dir_x);
	game->dist[1] = fabs(1 / game->ray_dir_y);
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		*side_dist_x = (game->player_x - game->map_x) * game->dist[0];
	}
	else
	{
		game->step_x = 1;
		*side_dist_x = (game->map_x + 1.0 - game->player_x) * game->dist[0];
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		*side_dist_y = (game->player_y - game->map_y) * game->dist[1];
	}
	else
	{
		game->step_y = 1;
		*side_dist_y = (game->map_y + 1.0 - game->player_y) * game->dist[1];
	}
}

int	perform_dda(t_structure *game, double *side_dist_x, double *side_dist_y)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (*side_dist_x < *side_dist_y)
		{
			*side_dist_x += game->dist[0];
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			*side_dist_y += game->dist[1];
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_y][game->map_x] > 0)
			hit = 1;
	}
	return (game->side);
}

void	calculate_wall_data(t_structure *game, double *dist, double *wall_x)
{
	if (game->side == 0)
		*dist = (game->map_x - game->player_x + (1 - game->step_x) / 2)
			/ game->ray_dir_x;
	else
		*dist = (game->map_y - game->player_y + (1 - game->step_y) / 2)
			/ game->ray_dir_y;
	game->line_height = (int)(game->screen_height / *dist);
	if (game->side == 0)
		*wall_x = game->player_y + *dist * game->ray_dir_y;
	else
		*wall_x = game->player_x + *dist * game->ray_dir_x;
	*wall_x -= floor(*wall_x);
}
