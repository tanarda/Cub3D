/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:20:24 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 11:23:18 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_val(t_data *program)
{
	program->game.posx = 22;
	program->game.posy = 12;
	program->game.move_speed = 0.07;
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


void	game_image(t_data *program)
{
	program->map_data.n_o = mlx_xpm_file_to_image(program->game.mlx, program->map_data.no, \
	&program->game.m_w, &program->game.m_w);
	program->map_data.s_o = mlx_xpm_file_to_image(program->game.mlx, program->map_data.so, \
	&program->game.m_w, &program->game.m_w);
	program->map_data.e_a = mlx_xpm_file_to_image(program->game.mlx, program->map_data.ea, \
	&program->game.m_w, &program->game.m_w);
	program->map_data.w_e = mlx_xpm_file_to_image(program->game.mlx, program->map_data.we, \
	&program->game.m_w, &program->game.m_w);
	if (program->map_data.w_e == NULL || program->map_data.e_a == NULL || program->map_data.s_o == NULL \
	|| program->map_data.n_o == NULL)
		error();
	program->map_data.i_no = (int *)mlx_get_data_addr(program->map_data.n_o, \
	&program->game.bpp, &program->game.sl, &program->game.end);
	program->map_data.i_so = (int *)mlx_get_data_addr(program->map_data.s_o, \
	&program->game.bpp, &program->game.sl, &program->game.end);
	program->map_data.i_ea = (int *)mlx_get_data_addr(program->map_data.e_a, \
	&program->game.bpp, &program->game.sl, &program->game.end);
	program->map_data.i_we = (int *)mlx_get_data_addr(program->map_data.w_e, \
	&program->game.bpp, &program->game.sl, &program->game.end);
	if (program->map_data.i_no == NULL || program->map_data.i_so == NULL || program->map_data.i_ea == NULL \
	|| program->map_data.i_we == NULL)
		error();
}


void start_game(t_data *program)
{
	start_val(program);
	program->game.mlx = mlx_init();
	program->game.win = mlx_new_window(program->game.mlx, WIDTH, HEIGHT, "cub3D");
	program->game.img = mlx_new_image(program->game.mlx, WIDTH, HEIGHT);
	program->game.addr = (int *)mlx_get_data_addr(program->game.img, \
	&program->game.bpp, &program->game.sl, &program->game.end);
	game_image(program);
	mlx_hook(program->game.win, 17, 0, close_window, program);
	mlx_loop_hook(program->game.mlx, screen_fill, program);
	mlx_hook(program->game.win, 3, 0, move_2, program);
	mlx_hook(program->game.win, 2, 0, move_1, program);
	mlx_loop(program->game.mlx);
}

int	screen_fill(t_data *program)
{
	int	width;

	mlx_clear_window(program->game.mlx, program->game.win);
	color_painting(program);
	width = 0;
	while (width < WIDTH)
	{
		set_data(program, width);
		wallcheck(program);
		hitcheck(program);
		get_dist(program);
		set_image_values(program);
		draw_image(program, width);
		width++;
	}
	mlx_put_image_to_window(program->game.mlx, program->game.win, program->game.img, 0, 0);
	move_func(program);
	return (0);
}
