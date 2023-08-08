#include "cub3d.h"

void	organise_data(char *data, t_data *map_cub)
{
	int	i;

	i = 0;
	while (data[i] == ' ')
		i++;
	if (data[i] == '\t')
		error();

}

//char	*is_valid_map(char **map)
//{
//	int	i;
//	int	j;
//	int	border;
//	char *border_line = malloc(sizeof(char) * MAP_SIZE);
//	border = 0;
//	i = 0;
//	while (map[i])
//	{
//		j = 0;
//		while (map[i][j])
//		{
//			if((map[i][j - 1] != ' ') || (map[i][j + 1] == '\0'))
//			{
//				printf("%c-",map[i][j]);
//				border_line[border] = map[i][j];
//				border++;
//			}
//			j++;
//		}
//		i++;
//	}
//	return (border_line);
//}
