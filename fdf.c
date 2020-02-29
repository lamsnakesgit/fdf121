/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/29 22:23:12 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_high(t_fdf *data, char *fname)
{
	char	*line;
	int		fd;
	int		h;

	fd = open(fname, O_RDONLY);
	h = 0;
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

int         get_width(char *fname)//t_fdf *data, )
{
	int		fd;
	int		w;
	char	*line;

	fd = open(fname, O_RDONLY);
	get_next_line(fd, &line);
	w = ft_count_w(line, ' ');//ft_strsplit(line, ' ');//ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (w);
}
void		fill_matrix(int *z_line, char *line)//t_fdf *data, char *line)
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
//		printf("zline[i]=%4d | i=%d\n", z_line[i], i);
		free(nums[i]);
		++i;
	}
	free(nums);
}

void		read_file(t_fdf *fdf, char *fname)
{
	int		fd;
	char	*line;
	int		i;

	fdf->h = get_high(fdf, fname);
	fdf->w = get_width(fname);
	fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->h + 1));
	i = 0;
	while (i <= fdf->h)
		fdf->z_matrix[i++] = (int *)malloc(sizeof(int) * (fdf->w + 1));
	fd = open(fname, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(fdf->z_matrix[i], line);
		free(line);
		++i;
	}
	close(fd);
	fdf->z_matrix[i] = NULL;//0;
	i = 0;
	int y = 0;
	while (i < fdf->h)//(i <= fdf->h)
	{
		y = -1;
		while (++y < fdf->w - 1)
			printf("%3d ", fdf->z_matrix[i][y]);
		++i;
		printf("\nPPPP");
	}printf("SEG\n");
	
}

int			deal_key(int key, void *data)
{
	printf("key=%d\n", key);
//	if (key == )
	return (0);
}

float		mod(float a)
{
	return (a >= 0 ? a : -a);
}

void		isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void		bresenham(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float	x_st;
	float	y_st;
	int		max;
	float	z;
	int		z1;
	//zoom
/*	while (fdf->z_matrix[(int)y])
	{
		while (fdf->z_matrix)
	}
*/	//printf("z = fdf->z_matrix[(int)y]=%d\n\n", fdf->z_matrix[(int)y]);
	printf("z = fdf->z_matrix[(int)y][(int)x]=%d\n\n", fdf->z_matrix[(int)y][(int)x]);
	z = fdf->z_matrix[(int)y][(int)x];
	z1 = fdf->z_matrix[(int)y1][(int)x1];
//				ZOOM!!!!!!!!!
	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
	//zoom
	//iso
	printf("SEG?\n");

	//iso
//	z *= fdf->zoom; z1 *= fdf->zoom;//
	//					color
	fdf->color = 0;
	fdf->color = (z || z1) ? RED : WHITE;
	//					3D
		isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//3d iso
	//shift
	//			SHIFT
	x += 150;
	y += 150;
	x1+= 150;//05;
	y1+= 150;

	x_st = x1 - x;
	y_st = y1 - y;
	max = mod(x_st) > mod(y_st) ? x_st : y_st;
	x_st /= max;
	y_st /= max;
	while ((int)(x - x1) || (int)(y - y1))//?
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);//0xffffff);
		x += x_st;
		y += y_st;
	}
}

void		draw_line(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->h -2 )
	{
		x = 0;
		printf("ASDF=y=%d x=%d y+1 x + 1\n", y, x);
		while (x < fdf->w -2 )
		{
			if (x < fdf->w - 1)
				bresenham(x, y, x + 1, y, fdf);
			if (y < fdf->h - 1)
				bresenham(x, y, x, y + 1, fdf);
			++x;
		}
		++y;
	}
}
int			main(int ac, char **av)
{
	t_fdf *fdf;
	int i;
	int j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(fdf, av[1]);//(data, fname);
	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
		//	printf("%2d ", fdf->z_matrix[i][j]);
			++j;
		}
	//	printf("\n");
		++i;
	}
	fdf->zoom = 50;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "TR");
	draw_line(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, NULL);
	mlx_loop(fdf->mlx_ptr);
	//bresenham(10, 10, 600, 300, fdf);
	//mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, )
    return (0);
}
