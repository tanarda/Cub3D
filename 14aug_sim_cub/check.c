/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 02:39:34 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:24:33 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg(t_data *program, char *str)
{
	if (!ft_strncmp(str, "WE", 2) && program->map_data.we != NULL)
		error();
	else if (!ft_strncmp(str, "EA", 2) && program->map_data.ea != NULL)
		error();
	else if (!ft_strncmp(str, "SO", 2) && program->map_data.so != NULL)
		error();
	else if (!ft_strncmp(str, "NO", 2) && program->map_data.no != NULL)
		error();
	else if (!ft_strncmp(str, "F", 1) && program->map_data.f != NULL)
		error();
	else if (!ft_strncmp(str, "C", 1) && program->map_data.c != NULL)
		error();
}

int	check_wall(char *tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
				|| tmp[i] == 'W' || tmp[i] == 'E')
				return (1);
			i++;
		}
	}
	return (0);
}

void	check_map(t_data *program)
{
	program->map_data.map[program->i] = NULL;
	program->i = 0;
	program->j = 0;
	program->map_data.map_l = 0;
	while (program->map_data.map[program->i] && program->map_data.map_l == 0)
	{
		if (check_var(program->map_data.map[program->i]) == 0)
			error();
		else if (check_var(program->map_data.map[program->i]) == 1)
			program->i++;
		else if (check_var(program->map_data.map[program->i]) == 2)
			program->map_data.map_l = program->i;
		else if (check_var(program->map_data.map[program->i]) == 3)
			program->map_data.map_l = ++(program->i);
	}
	if (program->map_data.map_l == 0)
		program->map_data.map_l = program->i;
	while (program->map_data.map[program->i])
	{
		check_tmp(program->map_data.map[program->i]);
		program->i++;
	}
}

void	map_checker(t_data *program)
{
	program->i = -1;
	while (program->map_data.map_l + 2 > ++(program->i))
	{
		program->j = -1;
		while (program->map_data.map_w + 2 > ++(program->j))
		{
			if (program->map_data.i_map[program->i][program->j] == 0
				|| program->map_data.i_map[program->i][program->j] == S
				|| program->map_data.i_map[program->i][program->j] == W
				|| program->map_data.i_map[program->i][program->j] == E
				|| program->map_data.i_map[program->i][program->j] == N)
				check_wall_player(program);
			if (program->map_data.i_map[program->i][program->j] == S
				|| program->map_data.i_map[program->i][program->j] == W
				|| program->map_data.i_map[program->i][program->j] == E
				|| program->map_data.i_map[program->i][program->j] == N)
				find_loc_player(program);
		}
	}
	if (program->counter != 1)
		error();
}

int	check_var(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if (tmp[i] == '\0' || tmp[i] == '\n')
		return (2);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
			|| tmp[i] == 'W' || tmp[i] == 'E' || tmp[i] == ' ')
			i++;
		else
			return (0);
	}
	if (tmp[i] == '\0')
		return (3);
	else if (i != 0)
		return (1);
	else
		return (2);
}
