#include "cub3d.h"

int	ft_get_data(t_data *map_cub, char *line)
{
	char **split_result;

	split_result = ft_split(line, '\n');
	while(*line == ' ')
		line++;
	if (line[0] == '\n')
		return(free_array(split_result), 0);
	else if(!ft_strncmp(line, "NO ", 3))
		map_cub->north = split_result[0];
	else if(!ft_strncmp(line, "SO ", 3))
		map_cub->south = split_result[0];
	else if(!ft_strncmp(line, "WE ", 3))
		map_cub->west = split_result[0];
	else if(!ft_strncmp(line, "EA ", 3))
		map_cub->east = split_result[0];
	else if(!ft_strncmp(line, "F ", 2))
		map_cub->f_color = split_result[0];
	else if(!ft_strncmp(line, "C ", 2))
		map_cub->c_color = split_result[0];
	else
		return (1);
	return (0);
}

void ft_check_data(t_data *map_cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_strncmp(&line[i], "WE ", 3) && map_cub->west != NULL)
		error();
	else if (!ft_strncmp(&line[i], "EA ", 3) && map_cub->east != NULL)
		error();
	else if (!ft_strncmp(&line[i], "SO ", 3) && map_cub->south != NULL)
		error();
	else if (!ft_strncmp(&line[i], "NO ", 3) && map_cub->north != NULL)
		error();
	else if (!ft_strncmp(&line[i], "F ", 2) && map_cub->f_color != NULL)
		error();
	else if (!ft_strncmp(&line[i], "C ", 2) && map_cub->c_color != NULL)
		error();
}

void ft_check_struct(t_data *map_cub)
{
	if (map_cub->c_color == NULL || map_cub->f_color == NULL || map_cub->east == NULL
		|| map_cub->north == NULL || map_cub->south == NULL || map_cub->west == NULL)
		error();
}

int	ft_is_map_line(char *tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S'
				|| tmp[i] == 'W' || tmp[i] == 'E')
				return (1);
			i++;
		}
	}
	return (0);
}

char	**ft_get_map(char *filename, t_data *map_cub)
{
	int 	fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	fd = open(filename , O_RDONLY);
	if (fd == -1)
		error();
	map = (char **)malloc((map_cub->height + 1) * sizeof(char *));
	while ((line = get_next_line(fd)))
	{
		ft_check_data(map_cub, line);
		if (ft_get_data(map_cub, line) == 1)
			break ;
	}
	if (!(ft_strchr(line, '1') || ft_strchr(line, '0') || ft_strchr(line, ' ')))
			error();
	map[i++] = line;
	while ((line = get_next_line(fd)) && *line != '\n')
	{
		if (!(ft_strchr(line, '1') || ft_strchr(line, '0') || ft_strchr(line, ' ')))
			error();
		map[i++] = line;
	}
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
