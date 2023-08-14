/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:20:24 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:30:54 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_val(t_data *program)
{
	program->game.posx = 22;
	program->game.posy = 12;
	program->game.move_speed = 0.03;
	program->key.w_key = 0;
	program->key.a_key = 0;
	program->key.s_key = 0;
	program->key.d_key = 0;
	program->game.m_w = 0;
	program->key.cam_left = 0;
	program->key.cam_right = 0;
	program->key.map_key = 0;
	program->game.rotate_speed = 0.032;
	get_color(program);
}


void start_game(t_data *program)
{

	program->game.mlx = mlx_init();
	program->game.win = mlx_new_window(program->game.mlx, WIDTH, HEIGHT, "cub3D");
	program->game.img = mlx_new_image(program->game.mlx, WIDTH, HEIGHT);
	program->game.addr = (int *)mlx_get_data_addr(program->game.img, \
	&program->game.bpp, &program->game.sl, &program->game.end);

	mlx_hook(bm->game.win, 17, 0, close_window, program);
	mlx_loop(program->game.mlx);
}
