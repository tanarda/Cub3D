/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 03:11:33 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:12:28 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	path_check(t_data *program)
{
	if (ft_strncmp(program->map_data.we, "./", 2) || \
	ft_strncmp(program->map_data.so, "./", 2) || \
	ft_strncmp(program->map_data.ea, "./", 2) || \
	ft_strncmp(program->map_data.no, "./", 2))
		error();
	if (open(&program->map_data.we[2], O_RDWR) == -1 || \
	open(&program->map_data.so[2], O_RDWR) == -1 || \
	open(&program->map_data.ea[2], O_RDWR) == -1 || \
	open(&program->map_data.no[2], O_RDWR, 0777) == -1)
		error();
}

void	location_path_check(t_data *program)
{
	program->map_data.ea = path_ret(program->map_data.ea);
	program->map_data.so = path_ret(program->map_data.so);
	program->map_data.we = path_ret(program->map_data.we);
	program->map_data.no = path_ret(program->map_data.no);
	program->map_data.f = path_ret(program->map_data.f);
	program->map_data.c = path_ret(program->map_data.c);
	program->map_data.ea = path_ret(&program->map_data.ea[2]);
	program->map_data.so = path_ret(&program->map_data.so[2]);
	program->map_data.we = path_ret(&program->map_data.we[2]);
	program->map_data.no = path_ret(&program->map_data.no[2]);
	program->map_data.f = path_ret(&program->map_data.f[1]);
	program->map_data.c = path_ret(&program->map_data.c[1]);
	trim_nline(program->map_data.c);
	trim_nline(program->map_data.f);
	trim_nline(program->map_data.ea);
	trim_nline(program->map_data.so);
	trim_nline(program->map_data.no);
	trim_nline(program->map_data.we);
	check_xpm(program);
}

char	*path_ret(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] == ' ')
		i++;
	return (&tmp[i]);
}

void	check_xpm(t_data *program)
{
	int	i;
	int	j;
	int	k;
	int	x;

	i = ft_strlen(program->map_data.ea);
	j = ft_strlen(program->map_data.no);
	k = ft_strlen(program->map_data.so);
	x = ft_strlen(program->map_data.we);
	if (i <= 4 || j <= 4 || k <= 4 || x <= 4)
		error();
	if (ft_strncmp(&program->map_data.ea[i - 4], ".xpm", 4) || \
	ft_strncmp(&program->map_data.no[j - 4], ".xpm", 4) || \
	ft_strncmp(&program->map_data.so[k - 4], ".xpm", 4) || \
	ft_strncmp(&program->map_data.we[x - 4], ".xpm", 4))
		error();
}
