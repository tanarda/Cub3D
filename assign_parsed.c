#include "cub3d.h"

void	set_parsed_items(t_data *map_cub)
{
	assign_texture_paths(ft_texture_trim(map_cub->south), &map_cub->south);
	assign_texture_paths(ft_texture_trim(map_cub->north), &map_cub->north);
	assign_texture_paths(ft_texture_trim(map_cub->east), &map_cub->east);
	assign_texture_paths(ft_texture_trim(map_cub->west), &map_cub->west);
	assign_color_values(ft_color_trim(map_cub->c_color), map_cub->c_rgb);
	assign_color_values(ft_color_trim(map_cub->f_color), map_cub->f_rgb);
}
