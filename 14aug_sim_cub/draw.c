/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:26:29 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:45:53 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_image(t_data *program, int i)
{
	int	a;

	a = program->game.draw_start;
	while (a < program->game.draw_end)
	{
		program->game.my = (int)program->game.pixel_nbr & (program->game.m_w - 1);
		program->game.pixel_nbr += program->game.pixel_cal;
		if (program->game.raydirx > 0 && program->game.side != 1)
			program->game.colour = program->map_data.i_so[program->game.m_w * program->game.my
				+ program->game.mx];
		else if (program->game.raydirx < 0 && program->game.side != 1)
			program->game.colour = program->map_data.i_no[program->game.m_w * program->game.my
				+ program->game.mx];
		else if ((program->game.raydirx <= 2 && program->game.raydiry >= 0)
			&& program->game.side == 1)
			program->game.colour = program->map_data.i_ea[program->game.m_w * program->game.my
				+ program->game.mx];
		else
			program->game.colour = program->map_data.i_we[program->game.m_w * program->game.my
				+ program->game.mx];
		program->game.addr[a * WIDTH + i] = program->game.colour;
		a++;
	}
}

void	get_color(t_data *program)
{
	int	total;

	total = 0;
	total += (program->floor.r * 65536);
	total += (program->floor.g * 256);
	total += (program->floor.b * 1);
	program->floor.t = total;
	total = 0;
	total += (program->sky.r * 65536);
	total += (program->sky.g * 256);
	total += (program->sky.b * 1);
	program->sky.t = total;
}

void	color_painting(t_data *program)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				program->game.addr[i * WIDTH + j] = program->sky.t;
			else
				program->game.addr[i * WIDTH + j] = program->floor.t;
			j++;
		}
		i++;
	}
}
