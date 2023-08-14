/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:24:57 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 03:22:09 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub(char **ag)
{
	int	i;

	i = ft_strlen(ag[1]);
	if (i <= 4)
		error();
	if (ft_strncmp(&ag[1][i - 4], ".cub", 4))
		error();
}

int	ft_wmaplen(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	return (i);
}

void	check_tmp(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			i++;
		else
			error();
	}
}

void	trim_nline(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		tmp[i] = '\0';
}

void	error(void)
{
	printf("Error\n");
	exit(1);
}

int	get_map_size(char **av)
{
	int		fd;
	char	*tmp;
	int		count;

	count = 0;
	fd = open(av[1], O_RDWR, 0777);
	if (fd == -1)
		error();
	tmp = get_next_line(fd);
	while (tmp)
	{
		count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}
