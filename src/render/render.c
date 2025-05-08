/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikegonz <mikegonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:57:55 by mikegonz          #+#    #+#             */
/*   Updated: 2025/05/08 19:30:33 by mikegonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube_3D.h"

void	select_texture(t_structure *game)
{
	if (game->side == 0)
	{
		if (game->step_x == 1)
			game->texture = game->texture_w;
		else
			game->texture = game->texture_e;
	}
	else
	{
		if (game->step_y == 1)
			game->texture = game->texture_s;
		else
			game->texture = game->texture_n;
	}
}

void	calculate_start_end(t_structure *game, int *start, int *end)
{
	*start = (game->screen_height - game->line_height) / 2;
	*end = (game->screen_height + game->line_height) / 2;
	if (*start < 0)
		*start = 0;
	if (*end >= game->screen_height)
		*end = game->screen_height - 1;
}

void	draw_textured_line(t_structure *g, int x, \
							mlx_texture_t *texture, double wall_x)
{
	int		start;
	int		end;
	int		i;
	double	step;
	double	tex_pos;

	calculate_start_end(g, &start, &end);
	g->tex_x = (int)(wall_x * texture->width);
	if ((g->side == 0 && g->ray_dir_x > 0) \
		|| (g->side == 1 && g->ray_dir_y < 0))
		g->tex_x = texture->width - g->tex_x - 1;
	step = 1.0 * texture->height / g->line_height;
	tex_pos = (start - g->screen_height / 2 + g->line_height / 2) * step;
	i = start;
	while (i < end)
	{
		g->tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		mlx_put_pixel(g->img, x, i, \
				get_texture_color(texture, g->tex_x, g->tex_y));
		i++;
	}
}

void	render_column(t_structure *game, int x)
{
	double	camera_x;
	double	side_x;
	double	side_y;
	double	wall_x;
	double	dist;

	camera_x = 2 * x / (double)game->screen_width - 1;
	get_ray_direction(game, camera_x);
	init_dda(game, &side_x, &side_y);
	perform_dda(game, &side_x, &side_y);
	calculate_wall_data(game, &dist, &wall_x);
	select_texture(game);
	draw_textured_line(game, x, game->texture, wall_x);
}

void	render(void *param)
{
	t_structure	*game;
	int			x;

	game = (t_structure *)param;
	x = 0;
	while (x < game->screen_width)
	{
		render_column(game, x);
		x++;
	}
}
