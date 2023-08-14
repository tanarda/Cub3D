/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:44:12 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 00:45:39 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
