#include "../cub3d.h"

char	**bound_map(int longest_line)
{
	char **bnd_map = (char **)malloc((longest_line + 2) * sizeof(char *));
	int	i;

	i = 0;
	while (i < longest_line)
	{
		bnd_map[i] = (char *) malloc((longest_line + 2) * sizeof(char));
		ft_memset(bnd_map[i], '#', longest_line + 1);
		bnd_map[i][longest_line + 1] = '\0';
		i++;
	}
	bnd_map[longest_line + 1] = NULL;
	return (bnd_map);
}

char	**ft_join_map(char **map, t_data *map_cub)
{
	int i;
	int j;
	char **bnd_map;

	bnd_map = bound_map(map_cub->height);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N'
			 || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				bnd_map[i + 1][j + 1] = map[i][j];
			j++;
		}
		i++;
	}
	return (bnd_map);
}
