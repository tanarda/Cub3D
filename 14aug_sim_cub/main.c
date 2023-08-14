/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:06:04 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:19:30 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_file(t_data *program, char **av)
{
	check_cub(av);
	set_check_args(program, 0);
	filecheck(program, av);
	check_map(program);
	int_map_set(program);
	map_convert(program);
	map_checker(program);
	location_path_check(program);
	path_check(program);
	color_set(program);
}

int	main(int ac, char **av)
{
	t_data	program;

	if (ac == 2)
	{
		set_file(&program, av);
		start_game(&program);
	}
	else
		printf("Error\n");
	return (0);
}
