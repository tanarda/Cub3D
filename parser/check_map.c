#include "../cub3d.h"

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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				letter_count++;
			j++;
		}
		i++;
	}
	if (letter_count != 1)
		error();
}

void	is_valid_map(char **bnd_map)
{
	int	i;
	int	j;

	i = 1;
	while (bnd_map[i])
	{
		j = 1;
		while (bnd_map[i][j])
		{
			if ((bnd_map[i][j + 1] == '#') || (bnd_map[i][j - 1] == '#')
				|| (bnd_map[i - 1][j] == '#') || (bnd_map[i + 1][j] == '#'))
			{
				if (bnd_map[i][j] == '0')
					error();
			}
			j++;
		}
		i++;
	}
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
