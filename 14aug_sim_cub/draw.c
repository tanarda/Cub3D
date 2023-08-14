/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 08:26:29 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:26:46 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color(t_data *program)
{
	int	total;

	total = 0;
	total += (program->floor.r * 65536);
	total += (program->floor.g * 256);
	total += (program->floor.b * 1);
	program->floor.t = total;
	total = 0;
	total += (program->sky.r * 65536);
	total += (program->sky.g * 256);
	total += (program->sky.b * 1);
	program->sky.t = total;
}
