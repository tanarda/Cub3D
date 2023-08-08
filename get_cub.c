#include "cub3d.h"

int	ft_get_data(t_data *map_cub, int fd, char *line)
{
	char **split_result;
	split_result = ft_split(line, '\n');

	while(*line == ' ' && map_cub->data_count != 6)
		line++;
	if (line[0] == '\n')
		return(free_array(split_result), 0);
	else if(!ft_strncmp(line, "NO", 2))
	{
		map_cub->data_count++;
		map_cub->north = ft_strdup(split_result[0]);
	}
	else if(!ft_strncmp(line, "SO", 2))
	{
		map_cub->data_count++;
		map_cub->south = ft_strdup(split_result[0]);
	}
	else if(!ft_strncmp(line, "WE", 2))
	{
		map_cub->data_count++;
		map_cub->west = ft_strdup(split_result[0]);
	}
	else if(!ft_strncmp(line, "EA", 2))
	{
		map_cub->data_count++;
		map_cub->east = ft_strdup(split_result[0]);
	}
	else if(!ft_strncmp(line, "F", 1))
	{
		map_cub->data_count++;
		map_cub->f_color = ft_strdup(split_result[0]);
	}
	else if(!ft_strncmp(line, "C", 1))
	{
		map_cub->data_count++;
		map_cub->c_color = ft_strdup(split_result[0]);
	}
	else if(map_cub->data_count == 6)
		return (free_array(split_result), 1);
	return (0);
}

char	**ft_get_map(char *filename, t_data *map_cub)
{
	int 	fd;
	int		i;
	char	*line;
	char	**map;
	char	**splitted;
	int		size;

	i = 0;
	fd = open(filename , O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("An error occured", 1);
	map = (char **)malloc((map_cub->height + 1) * sizeof(char *));
	while ((line = get_next_line(fd)))
	{
		if (ft_get_data(map_cub, fd, line) == 1)
			break ;
	}
	splitted = ft_split(line, '\n');
	map[i++] = ft_strdup(splitted[0]);
	while ((line = get_next_line(fd)) && *line != '\n')
	{
		splitted = ft_split(line, '\n');
		map[i++] = ft_strdup(splitted[0]);
	}
	free_array(splitted);
	free(line);
	close(fd);
	return(map);
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

void	ft_printfmap(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	set_cub_data(t_data *map_cub, char *str)
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
