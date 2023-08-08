#include "cub3d.h"

void	init_data(t_data *map_cub, char *filename)
{
	map_cub->c_rgb = malloc(sizeof(t_rgbcolor));
	map_cub->f_rgb = malloc(sizeof(t_rgbcolor));
	map_cub->east = NULL;
	map_cub->north = NULL;
	map_cub->south = NULL;
	map_cub->west = NULL;
	map_cub->c_color = NULL;
	map_cub->f_color = NULL;
	map_cub->is_wrong = 0;
	map_cub->data_count = 0;
	map_cub->height = 0;
	fill_map_height(filename, map_cub);
}

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

int	is_valid_map(char **bnd_map)
{
	int	i;
	int	j;

	i = 1;
	while (bnd_map[i])
	{
		j = 1;
		while (bnd_map[i][j])
		{
			if ((bnd_map[i][j + 1] == '#') || (bnd_map[i][j - 1] == '#') || (bnd_map[i - 1][j] == '#') || (bnd_map[i + 1][j] == '#'))
			{
				if (bnd_map[i][j] == '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*map_cub;
	char	**map;
	char	*line;
	char	**bnd_map;
	int	i;

	if (ac != 2)
		error();

	i = 0;
	line = malloc(sizeof(char));
	map_cub = malloc(sizeof(t_data));
	check_file_format(av);
	init_data(map_cub, "map.cub");
	map = ft_get_map("map.cub", map_cub);
	bound_map(map_cub->height);
	bnd_map = ft_join_map(map, map_cub);
	set_parsed_items(map_cub);
	check_direct_count(bnd_map);
	ft_printfmap(bnd_map);
	printf("\n%d\n",is_valid_map(bnd_map));
}

	//printf("%s\n", map_cub->south);
	//printf("%s\n", map_cub->north);
	//printf("%s\n", map_cub->west);
	//printf("%s\n", map_cub->east);
	//printf("-----------------------------------------\n");
	//printf("%d\n", map_cub->f_rgb->red);
	//printf("%d\n", map_cub->f_rgb->green);
	//printf("%d\n", map_cub->f_rgb->blue);
	//printf("-----------------------------------------\n");
	//printf("%d\n", map_cub->c_rgb->red);
	//printf("%d\n", map_cub->c_rgb->green);
	//printf("%d\n", map_cub->c_rgb->blue);
