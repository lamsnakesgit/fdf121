/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:28:55 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/05 19:28:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


float		mod(float a)
{
	return (a >= 0 ? a : -a);
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
