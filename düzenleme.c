#include "cub3d.h"

void ft_init_and_check(t_data *map_cub, char **av, char **map)
{
	char	**bnd_map;

	init_data(map_cub, av[1]);
	check_file_format(av);
	fill_map_height(av[1], map_cub);
	map_cub->map = ft_get_map(av[1], map_cub);
	bound_map(map_cub->height);
	bnd_map = bound_map(map_cub->height);
	bnd_map = ft_join_map(map_cub->map, map_cub);
	set_parsed_items(map_cub);
	check_direct_count(bnd_map);
	ft_printfmap(bnd_map);
}

void	ft_get_cub_data(char *filename, t_data *map_cub)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;
	char	**splitted;

	i = 0;
	fd = open(filename, O_RDONLY)
	if (fd == -1)
		error();
	while ((line = get_next_line(fd)))
	{
		if (ft_get_data(map_cub, fd, line) == 1)
			break ;
	}
}

void	ft_get_cub_map()
{

}
