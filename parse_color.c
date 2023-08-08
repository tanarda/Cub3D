#include "cub3d.h"

char	*ft_color_trim(char *str)
{
	char	*trimed_space;
	int		i;
	i = 0;
	trimed_space = ft_strtrim(str, " ");
	return(ft_strtrim(++trimed_space, " "));
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
		return(1);
	}
	else
		free_array(values);
		return (0);
}
