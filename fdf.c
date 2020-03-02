/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/02 22:25:53 by ddratini         ###   ########.fr       */
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
	}
}
# define UP_Z 4
# define UP_Y 44
# define UP_X 444
# define DOWN_Z 4444
# define DOWN_Y 44444
# define DOWN_X 4444444

int			deal_key(int key, t_fdf *fdf)//void *data)
{
	int	r;

	printf("key=%d\n", key);
	r = 0;
	if (key == 53)//ESC
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);//close(0);//?????
		exit(0);//return (0);
	}
	else if (key == 126)
		fdf->shift_y -= 10;
	else if (key == 125)
		fdf->shift_y += 10;
	else if (key == 123)
		fdf->shift_x -= 10;
	else if (key == 124)
		fdf->shift_x += 10;
	else if (key == 6)//z
		fdf->projection = 1;
	else if (key == 7)//x
		fdf->projection = 3;
	else if (key == 0)//8) A-0
		fdf->z_sh += 10;
	else if (key == 1)//S-1
		fdf->z_sh -= 10;
	else if (key == UP_Z)
		fdf->rot_z += 10;
	else if (key == DOWN_Z)
		fdf->rot_z -= 10;
	else if (key == UP_X)
		fdf->rot_x += 10;
	else if (key == DOWN_X)
		fdf->rot_x -= 10;
	else if (key == UP_Y)
		fdf->rot_y += 10;
	else if (key == DOWN_Y)
		fdf->rot_y -= 10;
	else
	{
		printf("NOKEY|");
	//	mlx_loop(fdf->mlx_ptr);
	//	mlx_mouse_hook(fdf->win_ptr, deal_mouse, fdf);
	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_line(fdf);
	return (1);
}

int			deal_mouse(int m, t_fdf *fdf)
{
	printf("MOUSE=%d\n", m);
	return (0);
}

float		mod(float a)
{
	return (a >= 0 ? a : -a);
}

void		isometric(float *x, float *y, int z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);//(0.8);
	*y = (prev_x + prev_y) * sin(0.523599) -z ;//(0.8) - z;
}

void		findpb(float x, float y, float x1, float y1, t_fdf *fdf)
{
	float	x_st;
	float	y_st;
	int		max;
	int		z;//float
	int		z1;

	z = fdf->z_matrix[(int)y][(int)x];
	z1 = fdf->z_matrix[(int)y1][(int)x1];
//	====ZOOM!!!!!!!!!=========
	x *= fdf->zoom;
	y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
//	z *= fdf->zoom; z1 *= fdf->zoom;//
	//=========color==============
	fdf->color = (z || z1) ? RED : WHITE;
	//==========3D==========
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//3d iso
	//			SHIFT==========
	x += fdf->shift_x; //150;
	y += fdf->shift_y;//150;
	x1+= fdf->shift_x;//150;//05;
	y1+= fdf->shift_y;//150;
	z += fdf->z_sh;//SHIFT Z ZOOM
	x_st = x1 - x;
	y_st = y1 - y;
	if (mod(x_st) > mod(y_st))
		max = mod(x_st);
	else
		max = mod(y_st);
	max = mod(x_st) > mod(y_st) ? mod(x_st) : mod(y_st);
	x_st /= max;
	y_st /= max;
	int i;
	i = 0;
//	printf("x_st=%f y_st=%f x=%f y=%f fdcolor=%d\n", x_st, y_st, x, y, fdf->color);
	while ((int)(x - x1)  || (int)(y - y1)  )//? lol no>0 ||//////bresenham
	{
	//	i = (int)(fdf->w * (int)y + (int)x);
	//	if (i == fdf->w)
	//		break;
	//	printf("i=%d fdfimgi=%d\n", i, fdf->color);//fdf->img[0]);
		fdf->img[i] = fdf->color;
		if (i - 1 >= 0)
	//		printf("WHYimgi=%d\n", fdf->img[i-1]);
		++i;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);//0xffffff);
	//	printf("MPPUT=%d y=%d x-x1=%d y-y1=%d\n", x ,y, (int)(x-x1), (int)(y-y1));
		x += x_st;
		y += y_st;
	}
}

void		draw_line(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	printf("fdf-h=%d fdf->w=%d ", fdf->h, fdf->w);
	while (y < fdf->h )//-2 )
	{
		x = 0;
	//	printf("ASDF=y=%d x=%d y+1 x + 1\n", y, x);
		while (x < fdf->w )//-2 )
		{
			if (x < fdf->w - 1)
				findpb(x, y, x + 1, y, fdf);
			if (y < fdf->h - 1)
				findpb(x, y, x, y + 1, fdf);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);//i guess put image?
}

int			mouse_press(int press, int x, int y, void *param)
{
	printf("MOUSE=%d x=%d y=%d\n", press, x, y);
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf *fdf;
	int i;
	int j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (ac != 2)
		ft_err();
	read_file(fdf, av[1]);//(data, fname);
///	fdf->zoom = 40;
	fdf->zoom = 20;//500;
	fdf->mlx_ptr = mlx_init();
//	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 999999, 99999, "TR");
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 2000, 1300, "OPENW");//9999, 9999, "TR");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
	fdf->bpp = 32;
	fdf->end = 0;
	printf("FDFcolor=%d ", fdf->color);
	fdf->img = (int *)malloc(sizeof(int) * fdf->w);
	fdf->img = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->w, &fdf->end);
//	while (i < fdf->w)
//		printf("IMGI=%d ", fdf->img[i]);
	draw_line(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//3
//	mlx_hook(fdf->win_ptr, 17, 0, deal_key, fdf);
//	mlx_key_hook(fdf->win_ptr, deal_key, fdf);//NULL);
	mlx_loop(fdf->mlx_ptr);
//	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
//	mlx_loop(fdf->mlx_ptr);
	//bresenham(10, 10, 600, 300, fdf);
	//mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, )
    return (0);
}

int		ft_err()
{
	write(1, "usage: ./fdf map_file\n", 22);
	return (0);
}
