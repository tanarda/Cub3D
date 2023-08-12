#include "mlx/mlx.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

typedef struct	s_data {
	void *mlx;
	void *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

float px = 300 , py = 300, pdy, pdx, pa = 1, rayY, rayX;
const int	mapWidth = 10;
const int mapHeight = 10;
int maptotal = 100;

int map[mapWidth][mapHeight]=
{
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,0,0,0,1,1,0,0,1},
{1,0,1,0,0,0,0,0,0,1},
{1,0,1,0,0,0,0,0,0,1},
{1,0,1,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

t_data img;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_Dda()
{
	int	step;
	float	xinc;
	float	yinc;
	float	i;
	float	dx;
	float	dy;
	float	x;
	float	y;

	dx = (px + pdx * 5) - px;
	dy = (py + pdy * 5) - py;
	if (fabsf(dx) > fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	xinc = dx/step;
	yinc = dy/step;

	i = 1;
	x = px + 7.5;
	y = py + 7.5;
	while (i <= step)
	{
		my_mlx_pixel_put(&img , x, y, 0xFFFF00);
		x += xinc;
		y += yinc;
		i++;
	}
}

//void drawLine()
//{
//	int	x;
//	int a;

//	a = 1;
//	x = px;
//	while ()
//	{

//	}
//}

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
			my_mlx_pixel_put(&img, j, i, 0xFFFFFF);
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
	while (a < 100 - 1)
	{
		b = 0;
		while (b < 100 - 1)
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

	a = px + 15;
	b = py + 15;
	i = px;
	while (i < a)
	{
		j = py;
		while (j < b)
		{
			my_mlx_pixel_put(&img, i, j, 0xFFFF00);
			j++;
		}
		i++;
	}
}

int	move(int key)
{
	printf("%d\n", key);
	if (key == 0)
	{
		px += pdy;
		py -= pdx;
	}
	if (key == 1)
	{
		px -= pdx;
		py -= pdy;
	}
	if (key == 2)
	{
		px -= pdy;
		py += pdx;
	}
	if (key == 13)
	{
		px += pdx;
		py += pdy;
	}
	if (key == 123)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * PI;
		pdx = cos(pa) * 10;
		pdy = sin(pa) * 10;
	}
	if (key == 124)
	{
		pa += 0.1;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		pdx = cos(pa) * 10;
		pdy = sin(pa) * 10;
	}
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
	ft_grey_image(1000,1000);
	finaldraw();
	drawPlayer();
	my_Dda();
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	return 0;
}

int close_window(void)
{
	exit(0);
}

void init()
{

	pdx = cos(pa) * 10;
	pdy = sin(pa) * 10;
}

int	main()
{
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1000, 1000, "WINDOW");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	init();
	mlx_hook(img.win, 2, 0, move, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_loop_hook(img.mlx, &loop_hook, &img);

	mlx_loop(img.mlx);
	return 0;
}
