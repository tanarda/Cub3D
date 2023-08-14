/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehtan <mehtan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 00:08:53 by mehtan            #+#    #+#             */
/*   Updated: 2023/08/14 08:32:17 by mehtan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "fcntl.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "math.h"
# include "mlx/mlx.h"
# include <stdio.h>

# define ESC 53
# define KW 13
# define KA 0
# define KS 1
# define KD 2
# define LEFT 123
# define RIGHT 124
# define M 46

# define S 35
# define W 39
# define E 21
# define N 30

# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_key
{
	int					w_key;
	int					s_key;
	int					d_key;
	int					a_key;
	int					esc_key;
	int					cam_left;
	int					cam_right;
	int					map_key;
}						t_key;

typedef struct s_rgb
{
	unsigned long long	r;
	unsigned long long	g;
	unsigned long long	b;
	unsigned long long	t;
}						t_rgb;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*addr;
	int					bpp;
	int					sl;
	int					end;
	int					m_w;
	int					m_h;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				raydirx;
	double				raydiry;
	double				old;
	double				old2;
	double				rotate_speed;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	double				wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				wall_y;
	double				wallx;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					mx;
	int					my;
	double				pixel_cal;
	double				pixel_nbr;
	double				move_speed;
	int					colour;
	char				player_direction;
	double				x_loc_p;
	double				y_loc_p;
}						t_game;

typedef struct s_map
{
	int					map_l;
	int					map_w;
	int					**i_map;
	char				**map;
	char				*we;
	char				*ea;
	char				*so;
	char				*no;
	int					*i_we;
	int					*i_ea;
	int					*i_so;
	int					*i_no;
	void				*n_o;
	void				*s_o;
	void				*w_e;
	void				*e_a;
	char				*f;
	char				*c;
}						t_map;


typedef struct s_data{
	t_map				map_data;
	t_game				game;
	t_key				key;
	t_rgb				floor;
	t_rgb				sky;
	int					fd;
	char				*tmp_line;
	int					counter;
	int					i;
	int					j;
	char				**tmpf;
	char				**tmpc;
}		t_data;

//utils
void	check_cub(char **ag);
int		ft_wmaplen(char *tmp);
void	check_tmp(char *tmp);
void	trim_nline(char *tmp);
void	error(void);

//map_utils
int		get_map_size(char **av);


//check
void	check_arg(t_data *program, char *str);
int		check_wall(char *tmp);
void	check_map(t_data *program);
int		check_var(char *tmp);
void	map_checker(t_data *program);

//get_file
void	filecheck(t_data *program, char **av);
int		set_arg(t_data *program, char *str);
void	set_check_args(t_data *program, int flag);

//map
void	int_map_set(t_data *program);
void	map_convert(t_data *program);
void	find_loc_player(t_data *program);
void	check_wall_player(t_data *program);

//xpm_set
void	path_check(t_data *program);
void	location_path_check(t_data *program);
char	*path_ret(char *tmp);
void	check_xpm(t_data *program);

//color
void	color_val_check(t_data *program);
void	comma_check(t_data *program);
void	color_extra_check(t_data *program);
int		color_max_min(int i);
void	color_set(t_data *program);

//draw
void	get_color(t_data *program);


//game
void start_game(t_data *program);
void	start_val(t_data *program);

//key
int	move_1(int key, t_data *program);
int	move_2(int key, t_data *program);
int	close_window(t_data *program);

#endif
