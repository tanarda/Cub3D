#include "cub3d.h"

//Find and returns length of longest line in the "map.cub" file("\n" included).
int	get_longest_line(char *filename)
{
	char	*line;
	int		length;
	int		i;
	int		fd;

	fd = open(filename , O_RDONLY);
	if (fd == -1)
		error();
	length = 0;
	while ((line = get_next_line(fd)))
	{
		i = -1;
		while (line[++i])
		{
			if (i > length)
				length = i;
		}
	}
	close(fd);
	free(line);
	return (length + 1);
}

int	get_height(char *filename)
{
	char	*line;
	int		length;
	int		i;
	int		fd;

	fd = open(filename , O_RDONLY);
	if (fd == -1)
		error();
	length =0;
	while ((line = get_next_line(fd)))
		length++;
	close(fd);
	free(line);
	return (length);
}

int choose_size(int width, int height)
{
	return(width > height ? width : height);
}

void fill_map_height(char *filename, t_data *map_cub)
{
	map_cub->height = choose_size(get_height(filename), get_longest_line(filename));
}

void	check_file_format(char **av)
{
	int	i;

	i = ft_strlen(av[1]);
	if (i <= 4)
		error();
	if (ft_strncmp(&av[1][i - 4], ".cub", 4))
		error();
}

void	check_direct_count(char **map)
{
	int	i;
	int	j;
	int	letter_count;

	letter_count = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				letter_count++;
			j++;
		}
		i++;
	}
	if (letter_count != 1)
		error();
}

void	error()
{
	printf("Error\n");
	exit(0);
}
