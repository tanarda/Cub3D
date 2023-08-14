/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:42:21 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:23:18 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	filecheck(t_data *program, char **av)
{
	program->map_data.map = malloc(sizeof(char *) * get_map_size(av));
	program->fd = open(av[1], O_RDWR, 0777);
	if (program->fd == -1)
		error();
	program->tmp_line = get_next_line(program->fd);
	while (program->tmp_line)
	{
		check_arg(program, program->tmp_line);
		if (set_arg(program, program->tmp_line))
		{
			if (check_wall(program->tmp_line))
				break ;
			check_tmp(program->tmp_line);
			free(program->tmp_line);
		}
		program->tmp_line = get_next_line(program->fd);
	}
	set_check_args(program, 1);
	if (!program->tmp_line)
		error();
	while (program->tmp_line)
	{
		program->map_data.map[(program->i)++] = program->tmp_line;
		program->tmp_line = get_next_line(program->fd);
	}

}

int	set_arg(t_data *program, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!ft_strncmp(&str[i], "WE ", 3))
		program->map_data.we = str;
	else if (!ft_strncmp(&str[i], "EA ", 3))
		program->map_data.ea = str;
	else if (!ft_strncmp(&str[i], "SO ", 3))
		program->map_data.so = str;
	else if (!ft_strncmp(&str[i], "NO ", 3))
		program->map_data.no = str;
	else if (!ft_strncmp(&str[i], "F ", 2))
		program->map_data.f = str;
	else if (!ft_strncmp(&str[i], "C ", 2))
		program->map_data.c = str;
	else
		return (1);
	return (0);
}

void	set_check_args(t_data *program, int flag)
{
	if (flag == 0)
	{
		program->map_data.we = NULL;
		program->map_data.ea = NULL;
		program->map_data.so = NULL;
		program->map_data.no = NULL;
		program->map_data.f = NULL;
		program->map_data.c = NULL;
		program->i = 0;
		program->j = 0;
		program->counter = 0;
	}
	else if (flag == 1)
	{
		if (program->map_data.we != NULL && program->map_data.ea != NULL && program->map_data.no != NULL
			&& program->map_data.so != NULL && program->map_data.f != NULL && program->map_data.c != NULL)
			return ;
		else
			error();
	}
	return ;
}
