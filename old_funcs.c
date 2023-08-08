int find_map_line(char *line)
{
	int	i;
	int zero_or_one;

	zero_or_one = 0;
	i = -1;
	while (line[++i])
	{
		if (!ft_strncmp(&line[i], "1", 1) || !ft_strncmp(&line[i], "0", 1) || !ft_strncmp(&line[i], " ", 1))
		{
			while (line[i])
			{
				if (ft_strncmp(&line[i],"1", 1) && ft_strncmp(&line[i], "0", 1) && ft_strncmp(&line[i], " ", 1))
					return (0);
				if (!ft_strncmp(&line[i], "1", 1) || !ft_strncmp(&line[i], "0", 1))
					zero_or_one = 1;
				i++;
			}
			if (zero_or_one == 1)
				return (1);
		}
	}
	return (0);
}
