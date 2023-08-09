#include "../cub3d.h"

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
		free(line);
	}
	close(fd);
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
	{
		free(line);
		length++;
	}
	close(fd);
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

void	error()
{
	printf("Error\n");
	exit(0);
}

void free_array(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
