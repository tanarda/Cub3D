#include "../cub3d.h"

void ft_init_and_check(t_data *map_cub, char **av, char **map)
{
	char	**bnd_map;

	init_data(map_cub, av[1]);
	check_file_format(av);
	fill_map_height(av[1], map_cub);
	map = ft_get_map(av[1], map_cub);
	ft_check_struct(map_cub);
	bnd_map = ft_join_map(map, map_cub);
	is_valid_map(bnd_map);
	check_direct_count(bnd_map);
	set_parsed_items(map_cub);
	ft_printfmap(bnd_map);
	free_array(bnd_map);
}

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
	map_cub->map = NULL;
	map_cub->is_wrong = 0;
	map_cub->data_count = 0;
	map_cub->height = 0;
}

int	main(int ac, char **av)
{
	t_data	*map_cub;

	if (ac != 2)
		error();
	map_cub = malloc(sizeof(t_data));
	ft_init_and_check(map_cub, av, map_cub->map);
	free(map_cub->c_rgb);
	free(map_cub->f_rgb);
	free(map_cub->north);
	free(map_cub->south);
	free(map_cub->east);
	free(map_cub->west);
	free(map_cub);
	return (0);
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
