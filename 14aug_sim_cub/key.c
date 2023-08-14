/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:31:08 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:31:50 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_1(int key, t_data *program)
{
	if (key == ESC)
		close_window(program);
	if (key == KW)
		program->key.w_key = 1;
	if (key == KA)
		program->key.a_key = 1;
	if (key == KS)
		program->key.s_key = 1;
	if (key == KD)
		program->key.d_key = 1;
	if (key == LEFT)
		program->key.cam_left = 1;
	if (key == RIGHT)
		program->key.cam_right = 1;
	return (0);
}

int	move_2(int key, t_data *program)
{
	if (key == ESC)
		close_window(program);
	if (key == KW)
		program->key.w_key = 0;
	if (key == KA)
		program->key.a_key = 0;
	if (key == KS)
		program->key.s_key = 0;
	if (key == KD)
		program->key.d_key = 0;
	if (key == LEFT)
		program->key.cam_left = 0;
	if (key == RIGHT)
		program->key.cam_right = 0;
	return (0);
}

int	close_window(t_data *program)
{
	mlx_destroy_window(program->game.mlx, program->game.win);
	exit(0);
	return (0);
}
