#include "cub3d.h"

char	*ft_texture_trim(char *str)
{
	char	*trimed_space;
	int		i;
	i = 0;
	trimed_space = ft_strtrim(str, " ");
	return(ft_strtrim((trimed_space + 2), " "));
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

