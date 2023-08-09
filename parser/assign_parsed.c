#include "../cub3d.h"

char	*ft_color_trim(char *str)
{
	char	*trimed_space;
	int		i;

	i = 0;
	trimed_space = ft_strtrim(str, " ");
	return (ft_strtrim(++trimed_space, " "));
}

int	assign_color_values(char *str, t_rgbcolor *color)
{
	char	**values;

	values = ft_split(str, ',');
	if (values[0] && values[1] && values[2])
	{
		if (values[0])
			color->red = ft_atoi(ft_strtrim(values[0], " "));
		if (values[1])
			color->green = ft_atoi(ft_strtrim(values[1], " "));
		if (values[2])
			color->blue = ft_atoi(ft_strtrim(values[2], " "));
		free_array(values);
		return (1);
	}
	else
		free_array(values);
	return (0);
}

char	*ft_texture_trim(char *str)
{
	char	*trimed_space;
	int		i;

	i = 0;
	trimed_space = ft_strtrim(str, " ");
	return (ft_strtrim((trimed_space + 2), " "));
}

int	assign_texture_paths(char *str, char **direction)
{
	if (*str && *direction)
	{
		*direction = &(*str);
		return (1);
	}
	return (0);
}

void	set_parsed_items(t_data *map_cub)
{
	assign_texture_paths(ft_texture_trim(map_cub->south), &map_cub->south);
	assign_texture_paths(ft_texture_trim(map_cub->north), &map_cub->north);
	assign_texture_paths(ft_texture_trim(map_cub->east), &map_cub->east);
	assign_texture_paths(ft_texture_trim(map_cub->west), &map_cub->west);
	assign_color_values(ft_color_trim(map_cub->c_color), map_cub->c_rgb);
	assign_color_values(ft_color_trim(map_cub->f_color), map_cub->f_rgb);
}
