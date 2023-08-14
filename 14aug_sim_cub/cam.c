/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:57:54 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 10:58:44 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_right(t_data *program)
{
	program->game.old = program->game.dirx;
	program->game.dirx = program->game.dirx * cos(program->game.rotate_speed) - \
	program->game.diry * sin(program->game.rotate_speed);
	program->game.diry = program->game.old * sin(program->game.rotate_speed) + \
	program->game.diry * cos(program->game.rotate_speed);
	program->game.old2 = program->game.planex;
	program->game.planex = program->game.planex * cos(program->game.rotate_speed) - \
	program->game.planey * sin(program->game.rotate_speed);
	program->game.planey = program->game.old2 * sin(program->game.rotate_speed) + \
	program->game.planey * cos(program->game.rotate_speed);
}

void	cam_left(t_data *program)
{
	program->game.old = program->game.dirx;
	program->game.dirx = program->game.dirx * cos(-program->game.rotate_speed) - \
	program->game.diry * sin(-program->game.rotate_speed);
	program->game.diry = program->game.old * sin(-program->game.rotate_speed) + \
	program->game.diry * cos(-program->game.rotate_speed);
	program->game.old2 = program->game.planex;
	program->game.planex = program->game.planex * cos(-program->game.rotate_speed) - \
	program->game.planey * sin(-program->game.rotate_speed);
	program->game.planey = program->game.old2 * sin(-program->game.rotate_speed) + \
	program->game.planey * cos(-program->game.rotate_speed);
}
