/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/04 22:03:31 by ddratini         ###   ########.fr       */
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
	while (get_next_line(fd, &line) > 0)
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
	if (fd < 0)
		return(ft_err());
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
		printf("zline[i]=%4d | i=%d line=%s\n", z_line[i], i, line);
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
	while (get_next_line(fd, &line) > 0)
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

int			deal_key(int key, t_fdf *fdf)//void *data)
{
	int	r;

	if (key != 53 && key != 123 && key != 125 && key != 124 && key != 126 && key != 12 && key != 13)
	printf("key=%d\n", key);
	r = 0;
	if (key == 53)//ESC
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);//close(0);//?????
		exit(0);//return (0);
	}
	if (key == 126)
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
	else if (key == 12)//q w12 13)
		fdf->zoom += 1;//-10;
	else if (key == 13)
		fdf->zoom -= 1;
//	else
//	{
//		printf("NOKEY|");
	//	mlx_loop(fdf->mlx_ptr);
	//	mlx_mouse_hook(fdf->win_ptr, deal_mouse, fdf);
//	}
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

void		findpb(t_coord crd, float x1, float y1, t_fdf *fdf)
{
	float	x_st;
	float	y_st;
//	int		x_st;
//	int		y_st;
	int		max;
	int		z;//float
	int		z1;

	z = fdf->z_matrix[(int)crd.y][(int)crd.x];
	z1 = fdf->z_matrix[(int)y1][(int)x1];
//	====ZOOM!!!!!!!!!=========
	crd.x *= fdf->zoom;
	crd.y *= fdf->zoom;
	x1 *= fdf->zoom;
	y1 *= fdf->zoom;
//	z *= fdf->zoom; z1 *= fdf->zoom;//
	//=========color==============
	fdf->color = (z || z1) ? RED : WHITE;
	//==========3D==========ISO
	if (fdf->projection == ISO)
	{
//		z += fdf->z_sh;//SHIFT Z ZOOM
//		z1 += fdf->z_sh;
		isometric(&crd.x, &crd.y, z);
		isometric(&x1, &y1, z1);
	}
	//			SHIFT==========
	crd.x += fdf->shift_x; //150;
	crd.y += fdf->shift_y;//150;
	x1 += fdf->shift_x;//150;//05;
	y1 += fdf->shift_y;//150;
//==ROTATION x
//	y = y * cos(angle) + z * sin(ANGLE);
//	z = -y * sin(angle) + z cos(ANGLE);
//ROTY
//	x = x * cos(angle) + z * sin(angle);
//	z = -x * cos(angle) + z * cos(angle);
//ROTZ
//	x = x * cos(angle) - y * sin(angle);
//	y = x * sin(angle) + y * cos(angle);
	x_st = x1 - crd.x;
	y_st = y1 - crd.y;
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
	while ((int)(crd.x - x1)  || (int)(crd.y - y1)  )//? lol no>0 ||//////bresenham
	{
		i = (int)(fdf->w * (int)crd.y + (int)crd.x);
//		printf("i=%d \n", i);
	//	if (i == fdf->w)
	//		break;
	//	printf("i=%d fdfimgi=%d\n", i, fdf->color);//fdf->img[0]);
//		fdf->img[i] = fdf->color;
//		if (i - 1 >= 0)
	//		printf("WHYimgi=%d\n", fdf->img[i-1]);
//		++i;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, crd.x, crd.y, fdf->color);//0xffffff);
	//	printf("MPPUT=%d y=%d x-x1=%d y-y1=%d\n", x ,y, (int)(x-x1), (int)(y-y1));
		crd.x += x_st;
		crd.y += y_st;
	}
}

void		draw_line(t_fdf *fdf)
{
	t_coord	crd;
	int x;
	int y;

	crd.y = 0;
//	printf("fdf-h=%d fdf->w=%d \n", fdf->h, fdf->w);
	while (crd.y < fdf->h )//-2 )
	{
		crd.x = 0;
	//	printf("ASDF=y=%f x=%f y+1 x + 1\n", crd.y, crd.x);
		while (crd.x < fdf->w )//-2 )
		{
			if (crd.x < fdf->w - 1)
				findpb(crd, crd.x + 1, crd.y, fdf);
	//		printf("WER=%f crdy=%f\n", crd.x, crd.y);
			if (crd.y < fdf->h - 1)
				findpb(crd, crd.x, crd.y + 1, fdf);
			++crd.x;
		}
		++crd.y;
	}
//	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

int			mouse_press(int press, int x, int y, void *param)
{
	printf("MOUSE=%d x=%d y=%d\n", press, x, y);
	return (0);
}

int			data_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W_X, WIN_H_Y, "OPENWIN");
	fdf->bpp = 32;
	fdf->color = 0;//SEG?
	fdf->endian = 0;
	fdf->img = NULL;
//	fdf->img = (int *)malloc(sizeof(int) * fdf->w);
//	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
//	fdf->img = (int *)	mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->w, &fdf->endian);
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->projection = PRL;// 1;
	fdf->zoom = 10;
	fdf->shift_x = 50;
	fdf->shift_y = 50;
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
	data_init(fdf);
	printf("FDFcolor=%d \n", fdf->color);
//	while (i < fdf->w)
//		printf("IMGI=%d ", fdf->img[i]);
	draw_line(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//3
//	mlx_hook(fdf->win_ptr, 17, 0, deal_key, fdf);
//	mlx_key_hook(fdf->win_ptr, deal_key, fdf);//NULL);
//	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
	mlx_loop(fdf->mlx_ptr);
//	mlx_loop(fdf->mlx_ptr);
	//bresenham(10, 10, 600, 300, fdf);
    return (0);
}

int		ft_err()
{
	write(1, "usage: ./fdf map_file\n", 22);
	return (0);
}
