/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:46:35 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:47:08 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_func(t_data *program)
{
	move_forward(program);
	if (program->key.a_key)
		move_left(program);
	if (program->key.cam_left)
		cam_left(program);
	if (program->key.d_key)
		move_right(program);
	if (program->key.cam_right)
		cam_right(program);
}

void	move_backward(t_data *program)
{
	if (program->map_data.map[(int)(program->game.y_loc_p)][(int)(program->game.x_loc_p - \
	program->game.dirx * program->game.move_speed)] == '0' || \
	program->map_data.map[(int)(program->game.y_loc_p)][(int)(program->game.x_loc_p - \
	program->game.dirx * program->game.move_speed)] == program->game.player_direction)
		program->game.x_loc_p -= program->game.dirx * program->game.move_speed;
	if (program->map_data.map[(int)(program->game.y_loc_p - program->game.diry * \
	program->game.move_speed)][(int)program->game.x_loc_p] == '0' || \
	program->map_data.map[(int)(program->game.y_loc_p - program->game.diry * \
	program->game.move_speed)][(int)program->game.x_loc_p] == program->game.player_direction)
		program->game.y_loc_p -= program->game.diry * program->game.move_speed;
}

void	move_forward(t_data *program)
{
	if (program->key.w_key)
	{
		if (program->map_data.map[(int)(program->game.y_loc_p)][(int)(program->game.x_loc_p + \
		program->game.dirx * program->game.move_speed)] == '0' || \
		program->map_data.map[(int)(program->game.y_loc_p)][(int)(program->game.x_loc_p + \
		program->game.dirx * program->game.move_speed)] == program->game.player_direction)
			program->game.x_loc_p += program->game.dirx * program->game.move_speed;
		if (program->map_data.map[(int)(program->game.y_loc_p + program->game.diry * \
		program->game.move_speed)][(int)program->game.x_loc_p] == '0' || \
		program->map_data.map[(int)(program->game.y_loc_p + program->game.diry * \
		program->game.move_speed)][(int)program->game.x_loc_p] \
		== program->game.player_direction)
			program->game.y_loc_p += program->game.diry * program->game.move_speed;
	}
	else if (program->key.s_key)
		move_backward(program);
}

void	move_left(t_data *program)
{
	if (program->map_data.map[(int)program->game.y_loc_p][(int)(program->game.x_loc_p \
	- program->game.planex * program->game.move_speed)] == '0' || \
	program->map_data.map[(int)program->game.y_loc_p][(int)(program->game.x_loc_p - \
	program->game.planex * program->game.move_speed)] == program->game.player_direction)
		program->game.x_loc_p -= program->game.planex * program->game.move_speed;
	if (program->map_data.map[(int)(program->game.y_loc_p \
	- program->game.planey * program->game.move_speed)][(int)program->game.x_loc_p] == '0' || \
	program->map_data.map[(int)(program->game.y_loc_p - program->game.planey * \
	program->game.move_speed)][(int)program->game.x_loc_p] == program->game.player_direction)
		program->game.y_loc_p -= program->game.planey * program->game.move_speed;
}

void	move_right(t_data *program)
{
	if (program->map_data.map[(int)program->game.y_loc_p][(int)(program->game.x_loc_p + \
	program->game.planex * program->game.move_speed)] == '0' || \
	program->map_data.map[(int)program->game.y_loc_p][(int)(program->game.x_loc_p + program->game.planex \
	* program->game.move_speed)] == program->game.player_direction)
		program->game.x_loc_p += program->game.planex * program->game.move_speed;
	if (program->map_data.map[(int)(program->game.y_loc_p + program->game.planey * \
	program->game.move_speed)][(int)program->game.x_loc_p] == '0' || \
	program->map_data.map[(int)(program->game.y_loc_p + program->game.planey * \
	program->game.move_speed)][(int)program->game.x_loc_p] == program->game.player_direction)
		program->game.y_loc_p += program->game.planey * program->game.move_speed;
}
