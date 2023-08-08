#include "cub3d.h"

void ft_init_and_check(t_data *map_cub, char **av, char **map)
{
	char	**bnd_map;

	init_data(map_cub, av[1]);
	check_file_format(av);
	fill_map_height(av[1], map_cub);
	map = ft_get_map(av[1], map_cub);
	ft_check_struct(map_cub);
	bound_map(map_cub->height);
	bnd_map = bound_map(map_cub->height);
	bnd_map = ft_join_map(map, map_cub);
	is_valid_map(bnd_map);
	check_direct_count(bnd_map);
	set_parsed_items(map_cub);
	ft_printfmap(bnd_map);
}

int	ft_set_cub_data(t_data *map_cub, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!ft_strncmp(&str[i], "WE ", 3))
		map_cub->west = str;
	else if (!ft_strncmp(&str[i], "EA ", 3))
		map_cub->east = str;
	else if (!ft_strncmp(&str[i], "SO ", 3))
		map_cub->south = str;
	else if (!ft_strncmp(&str[i], "NO ", 3))
		map_cub->north = str;
	else if (!ft_strncmp(&str[i], "F ", 2))
		map_cub->f_color = str;
	else if (!ft_strncmp(&str[i], "C ", 2))
		map_cub->c_color = str;
	else
		return (1);
	return (0);
}

void ft_any_illegal_char(char **map)
{
	int	i;
	int	j;
	int	letter_count;

	letter_count = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j = 0;
			if (!((map[i][j] == '1') || (map[i][j] == '0') || (map[i][j] == ' ')))
				error();
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				letter_count++;
			j++;
		}
		i++;
	}
	if (letter_count != 1)
		error();
}
