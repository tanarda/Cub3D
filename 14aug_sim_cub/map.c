/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:55:01 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:10:13 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	int_map_set(t_data *program)
{
	program->i = 0;
	program->map_data.map_w = 0;
	program->map_data.i_map = malloc(sizeof(int *) * (program->map_data.map_l + 3));
	while (program->i < program->map_data.map_l)
	{
		if (ft_wmaplen(program->map_data.map[program->i]) > program->map_data.map_w)
			program->map_data.map_w = ft_wmaplen(program->map_data.map[program->i]);
		(program->i)++;
	}
	program->i = -1;
	while (++(program->i) < (program->map_data.map_l + 2))
	{
		program->j = 0;
		program->map_data.i_map[program->i] = malloc(sizeof(int) * (program->map_data.map_w + 2));
		if (program->i == 0)
		{
			while (program->j < (program->map_data.map_w + 2))
				program->map_data.i_map[program->i][(program->j)++] = 2;
		}
		else if (program->i == program->map_data.map_l + 1)
		{
			while (program->j < (program->map_data.map_w + 2))
				program->map_data.i_map[program->i][(program->j)++] = 2;
		}
	}
}

void	map_convert(t_data *program)
{
	int	i;
	int	j;

	i = -1;
	while (++i < program->map_data.map_l)
	{
		j = 0;
		if (j == 0)
			program->map_data.i_map[i + 1][0] = 2;
		while (program->map_data.map[i][j] && program->map_data.map[i][j] != '\n')
		{
			if (program->map_data.map[i][j] == ' ')
				program->map_data.i_map[i + 1][j + 1] = 2;
			else
				program->map_data.i_map[i + 1][j + 1] = program->map_data.map[i][j] - 48;
			j++;
		}
		while (j < program->map_data.map_w + 1)
		{
			program->map_data.i_map[i + 1][j + 1] = 2;
			j++;
		}
	}
	program->map_data.i_map[i + 2] = NULL;
}

void	find_loc_player(t_data *program)
{
	(program->counter)++;
	if (program->map_data.i_map[program->i][program->j] == W)
	{
		program->game.dirx = -1;
		program->game.planey = -0.66;
	}
	else if (program->map_data.i_map[program->i][program->j] == E)
	{
		program->game.dirx = 1;
		program->game.planey = 0.66;
	}
	else if (program->map_data.i_map[program->i][program->j] == N)
	{
		program->game.diry = -1;
		program->game.planex = 0.66;
	}
	else if (program->map_data.i_map[program->i][program->j] == S)
	{
		program->game.diry = 1;
		program->game.planex = -0.66;
	}
	program->game.x_loc_p = program->j - 0.5;
	program->game.y_loc_p = program->i - 0.5;
	program->game.player_direction = program->map_data.map[program->i - 1][program->j - 1];
}

void	check_wall_player(t_data *program)
{
	if ((program->map_data.i_map[program->i + 1][program->j] == 2 || program->map_data.i_map[program->i
			- 1][program->j] == 2 || program->map_data.i_map[program->i][program->j + 1] == 2
			|| program->map_data.i_map[program->i][program->j - 1] == 2))
		error();
	return ;
}
