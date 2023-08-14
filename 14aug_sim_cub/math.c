/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:37:21 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:43:54 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_image_values(t_data *program)
{
	if (program->game.side == 0)
		program->game.wallx = program->game.y_loc_p + program->game.wall_dist
			* program->game.raydiry;
	else
		program->game.wallx = program->game.x_loc_p + program->game.wall_dist
			* program->game.raydirx;
	program->game.wallx -= floor(program->game.wallx);
	program->game.mx = (int)(program->game.wallx * 64);
	if (program->game.side == 0 && program->game.raydirx > 0)
		program->game.mx = 64 - program->game.mx - 1;
	if (program->game.side == 1 && program->game.raydiry < 0)
		program->game.mx = 64 - program->game.mx - 1;
	program->game.pixel_cal = 1.0 * 64 / program->game.line_height;
	program->game.pixel_nbr = (program->game.draw_start - HEIGHT / 2 \
	+ program->game.line_height / 2) * program->game.pixel_cal;
}

void	hitcheck(t_data *program)
{
	while (program->game.hit == 0)
	{
		if (program->game.sidedistx < program->game.sidedisty)
		{
			program->game.sidedistx += program->game.deltadistx;
			program->game.mapx += program->game.stepx;
			program->game.side = 0;
		}
		else
		{
			program->game.sidedisty += program->game.deltadisty;
			program->game.mapy += program->game.stepy;
			program->game.side = 1;
		}
		if (program->map_data.map[program->game.mapy][program->game.mapx] == '1')
			program->game.hit = 1;
	}
}

void	get_dist(t_data *program)
{
	if (program->game.side == 0)
		program->game.wall_dist = program->game.sidedistx - program->game.deltadistx;
	else
		program->game.wall_dist = program->game.sidedisty - program->game.deltadisty;
	program->game.line_height = (int)(HEIGHT / program->game.wall_dist);
	program->game.draw_start = -program->game.line_height / 2 + HEIGHT / 2;
	if (program->game.draw_start < 0)
		program->game.draw_start = 0;
	program->game.draw_end = program->game.line_height / 2 + HEIGHT / 2;
	if (program->game.draw_end >= HEIGHT)
		program->game.draw_end = HEIGHT - 1;
}


void	wallcheck(t_data *program)
{
	if (program->game.raydirx < 0)
	{
		program->game.stepx = -1;
		program->game.sidedistx = (program->game.x_loc_p - program->game.mapx)
			* program->game.deltadistx;
	}
	else
	{
		program->game.stepx = 1;
		program->game.sidedistx = (program->game.mapx + 1.0 - program->game.x_loc_p)
			* program->game.deltadistx;
	}
	if (program->game.raydiry < 0)
	{
		program->game.stepy = -1;
		program->game.sidedisty = (program->game.y_loc_p - program->game.mapy)
			* program->game.deltadisty;
	}
	else
	{
		program->game.stepy = 1;
		program->game.sidedisty = (program->game.mapy + 1.0 - program->game.y_loc_p)
			* program->game.deltadisty;
	}
}

void	set_data(t_data *program, int width)
{
	program->game.camerax = (2 * width / (double)WIDTH - 1);
	program->game.raydirx = program->game.dirx + program->game.planex * program->game.camerax;
	program->game.raydiry = program->game.diry + program->game.planey * program->game.camerax;
	program->game.mapx = (int)program->game.x_loc_p;
	program->game.mapy = (int)program->game.y_loc_p;
	program->game.deltadistx = fabs(1 / program->game.raydirx);
	program->game.deltadisty = fabs(1 / program->game.raydiry);
	program->game.hit = 0;
}
