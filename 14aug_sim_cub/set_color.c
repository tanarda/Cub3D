/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:15:50 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:17:09 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_val_check(t_data *program)
{
	int	i;

	i = 0;
	while (program->map_data.c[i])
	{
		if (((program->map_data.c[i] == ' ' || program->map_data.c[i] == ',')
				|| (program->map_data.c[i] >= '0' && program->map_data.c[i] <= '9'))
			&& program->map_data.c[i])
			i++;
		else
			error();
	}
	i = 0;
	while (program->map_data.f[i])
	{
		if (((program->map_data.f[i] == ' ' || program->map_data.f[i] == ',')
				|| (program->map_data.f[i] >= '0' && program->map_data.f[i] <= '9'))
			&& program->map_data.f[i])
			i++;
		else
			error();
	}
}

void	comma_check(t_data *program)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (program->map_data.f[++i])
	{
		if (program->map_data.f[i] == ',')
			count++;
	}
	if (count != 2)
		error();
	i = -1;
	count = 0;
	while (program->map_data.c[++i])
	{
		if (program->map_data.c[i] == ',')
			count++;
	}
	if (count != 2)
		error();
}

void	color_extra_check(t_data *program)
{
	int	i;

	i = 0;
	program->tmpf = ft_split(program->map_data.f, ',');
	program->tmpc = ft_split(program->map_data.c, ',');
	while (program->tmpf[i])
		i++;
	if (i != 3)
		error();
	i = 0;
	while (program->tmpc[i])
		i++;
	if (i != 3)
		error();
}

int	color_max_min(int i)
{
	if (i < 0 || i > 255)
		error();
	return (i);
}

void	color_set(t_data *program)
{
	color_val_check(program);
	comma_check(program);
	color_extra_check(program);
	program->floor.r = color_max_min(ft_atoi(program->tmpf[0]));
	program->floor.g = color_max_min(ft_atoi(program->tmpf[1]));
	program->floor.b = color_max_min(ft_atoi(program->tmpf[2]));
	program->sky.r = color_max_min(ft_atoi(program->tmpc[0]));
	program->sky.g = color_max_min(ft_atoi(program->tmpc[1]));
	program->sky.b = color_max_min(ft_atoi(program->tmpc[2]));
}
