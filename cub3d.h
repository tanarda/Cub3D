# ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct s_rgbcolor{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}		t_rgbcolor;

typedef struct s_cubData{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*f_color;
	char		*c_color;
	int			data_count;
	int			is_wrong;
	int			height;
	t_rgbcolor	*c_rgb;
	t_rgbcolor	*f_rgb;
}		t_data;



void	free_array(char **arr);
char	**ft_get_map(char *filename, t_data *map_cub);
int		ft_get_data(t_data *map_cub, int fd, char *line);
void	ft_printfmap(char **map);
int		is_valid_map(char **bnd_map);
void	init_data(t_data *map_cub, char *filename);
char	**bound_map(int longest_line);

int		get_longest_line(char *filename);
int		choose_size(int width, int height);
int		get_height(char *filename);
void	fill_map_height(char *filename, t_data *map_cub);

char	*ft_color_trim(char *str);
int		assign_color_values(char *str, t_rgbcolor *color);
char	*ft_texture_trim(char *str);
int		assign_texture_paths(char *str, char **direction);

void	set_parsed_items(t_data *map_cub);

void	error();
void	check_file_format(char **av);
void	check_direct_count(char **map);
#endif
