#include "mlx/mlx.h"
#include "stdio.h"
#include "stdlib.h"

const int	mapWidth = 10;
const int mapHeight = 10;
const int maptotal= 100;

typedef struct	s_data {
	void *mlx;
	void *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int map[mapWidth][mapHeight]=
{
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

t_data img;
float px = 300 , py = 300;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_grey_image(int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(&img, j, i, 0x808080);
			j++;
		}
		i++;
	}
}

void	drawmap(int	kind, int i, int j)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = 0;
		while (b < 100)
		{
			if (kind == 1)
				my_mlx_pixel_put(&img, a + (i * 100), b + (j * 100), 0x444444);
			else if(kind == 0)
				my_mlx_pixel_put(&img, a + (i * 100), b + (j * 100), 0x111111);
			b++;
		}
		a++;
	}
}

void finaldraw()
{
	int	i;
	int	j;

	i = 0;
	while (i < mapWidth)
	{
		j = 0;
		while (j < mapHeight)
		{
			drawmap(map[i][j], i, j);
			j++;
		}
		i++;
	}
}


void drawPlayer()
{
	int	i;
	int	j;
	int	a;
	int	b;

	a = px + 50;
	b = py + 50;
	i = px;
	while (i < a)
	{
		j = py;
		while (j < b)
		{
			my_mlx_pixel_put(&img, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	move(int key)
{
	printf("%d\n", key);
	if (key == 0)
		px -= 15;
	if (key == 1)
		py += 15;
	if (key == 2)
		px += 15;
	if (key == 13)
		py -= 15;
	if (key == 53)
	{
		mlx_destroy_image(img.mlx, img.img);
		exit(0);
	}
	return(0);
}

int loop_hook(void)
{
	mlx_clear_window(img.mlx, img.win);
	finaldraw();
	drawPlayer();
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	return 0;
}

int close_window(void)
{
	exit(0);
}

int	main()
{
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1000, 1000, "WINDOW");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_hook(img.win, 2, 0, move, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop_hook(img.mlx, &loop_hook, &img);
	mlx_loop(img.mlx);
	return 0;
}
