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

void		findpb(t_coord crd, int x1, int y1, t_fdf *fdf)
{
	float	x_st;
	float	y_st;//	int		x_st;//	int		y_st;
	int		max;
	int		z;//float
	int		z1;
//	float		z;//float
//	float		z1;

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
		isometric(&crd.x, &crd.y, z,fdf);
		isometric(&x1, &y1, z1,fdf);
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
	x_st /= max;
	y_st /= max;
	int i;
	i = 0;
//	printf("x_st=%f y_st=%f x=%f y=%f fdcolor=%d\n", x_st, y_st, x, y, fdf->color);
//	printf("CLR=%d\n", CLR);//65280
	while ((int)(crd.x - x1)  || (int)(crd.y - y1)  )//? lol no>0 ||//////bresenham
	{
	//	i = (int)(fdf->w * (int)crd.y + (int)crd.x);
	//	printf("i=%d fdf->color=%d\n", i, fdf->color);
		//	printf("i=%d fdfimgi=%d\n", i, fdf->color);//fdf->img[0]);
	//	fdf->img[i] = fdf->color;
//		if (i - 1 >= 0)
//				printf("WHYimgi=%d\n, fdf->color=%d\n", fdf->img[i-1], fdf->color);
//		++i;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, crd.x, crd.y, fdf->color);//0xffffff);
		//	printf("MPPUT=%d y=%d x-x1=%d y-y1=%d\n", x ,y, (int)(x-x1), (int)(y-y1));
		crd.x += x_st;//1;//x_st;
		crd.y += y_st;
	}
}
void 		brs(t_coord crd, int x1, int y1, t_fdf *fdf)
{
	int dy;
	int dx;
	int er;
	int er2;
	int sy;
	int sx;
	int nx;
	int ny;
	int i;
	float z;
	float z1;
	printf(" ZSH=%d\n", fdf->z_sh);
	////=================OLD
    z = fdf->z_matrix[(int)crd.y][(int)crd.x];
    z1 = fdf->z_matrix[(int)y1][(int)x1];
//	====ZOOM!!!!!!!!!=========
    crd.x *= fdf->zoom;
    crd.y *= fdf->zoom;
    x1 *= fdf->zoom;
    y1 *= fdf->zoom;
    //=====ZSH
//    z += fdf->z_sh;
    ////===Z_SH
//	z *= fdf->zoom; z1 *= fdf->zoom;//
    //=========color==============
	fdf->color = (z || z1) ? RED : WHITE;
    //==========3D==========ISO
    if (fdf->projection == ISO)
    {
//		z += fdf->z_sh;//SHIFT Z ZOOM
//		z1 += fdf->z_sh;
        isometric(&crd.x, &crd.y, z, fdf);
        isometric(&x1, &y1, z1, fdf);
    }
    //			SHIFT==========
    crd.x += fdf->shift_x; //150;
    crd.y += fdf->shift_y;//150;
    x1 += fdf->shift_x;//150;//05;
    y1 += fdf->shift_y;//150;
    ///=======================NEW
//	er = 0;
	dy = mod(y1 - crd.y);
	dx = mod(x1 - crd.x);
	sy = crd.y < y1 ? 1 : -1;
	sx = crd.x < x1 ? 1 : -1;
	er = dx - dy;//!!
//	er2 = dy + 1;
//	nx = crd.x;
//	ny = crd.y;
	//fdf->color = RED;//WHITE;//
	i = 0;
	while (crd.x != x1 || crd.y != y1)
    {
		printf("ZOOM=%d\n\n\n", fdf->zoom);
	    er2 = er * 2;
	//    if (crd.y >= 0 && crd.y < fdf->h && crd.x >= 0 && crd.x <= fdf->w)
	    if (crd.y >= 0 && crd.y < fdf->not_my_bus && crd.x >= 0 && crd.x <= fdf->not_my_bus)//WIN_W_X)
	    {
        //    i = fdf->w * crd.y + crd.x;
		//    i = fdf->not_my_bus * crd.y + crd.x;
		    i = WIN_W_X * 4 *  crd.y + crd.x;
            printf("i=%d w=%d h=%d y=%d x=%d y2=%d x2=%d\n", i,fdf->w,fdf->h,crd.y,crd.x,y1,x1);
            fdf->img[i] = fdf->color;
            //if (i % 2)
           //     fdf->img[i] = REVWHITE;//WHITE;
        }
     //   printf("i=%d w=%d h=%d y=%d x=%d y2=%d x2=%d\n", i,fdf->w,fdf->h,crd.y,crd.x,y1,x1);
	 //   printf("AFTER");
	    if (er2 > -dy)
	    {
	        er -= dy;
            crd.x += sx;
        }
	    if (er2 < dx)
	    {
            er += dx;
            crd.y += sy;
        }
//	    er = er + er2;
//	    if (er >= dx + 1)
//        {
//	        ny += sy;
//	        er = er - (dx + 1);
//        }
//	    nx += sx;
    }
}
//
//    setPixel(x2, y2);
//    while(x1 != x2 || y1 != y2)
//    {
//        setPixel(x1, y1);
//        const int error2 = error * 2;
//        //
//        if(error2 > -deltaY)
//        {
//            error -= deltaY;
//            x1 += signX;
//        }
//        if(error2 < deltaX)
//        {
//            error += deltaX;
//            y1 += signY;
//        }
//    }

void		draw_line(t_fdf *fdf)
{
	t_coord	crd;
	int x;
	int y;
	printf("33asdsdfgsfgsdfg\n");

//	ft_blank(fdf->img, fdf->not_my_bus);
//	printf("asdsdfgsfgsdfg\n");
//	//ft_bzero(fdf->img, fdf->not_my_bus);
//	printf("asdsdfgsfgsdfg\n");
//	//ft_bzero(fdf->img, WIN_W_X);
//	printf("asdsdfgsfgsdfg\n");
	int q = 0;
	int *ar;
	ar = fdf->img;
//	while (q < WIN_W_X * WIN_W_X * 4)
//	{
//		ar[q] = 0x00;//0x00ffff;
//		++q;
//	}
	crd.y = 0;
//	printf("fdf-h=%d fdf->w=%d \n", fdf->h, fdf->w);
	while (crd.y < fdf->h )//-2 )
	{
		crd.x = 0;
		//	printf("ASDF=y=%f x=%f y+1 x + 1\n", crd.y, crd.x);
		while (crd.x < fdf->w )//-2 )
		{
			if (crd.x < fdf->w - 1)
				//brs(crd, crd.x + 1, crd.y, fdf);
				findpb(crd, crd.x + 1, crd.y, fdf);
			//		printf("WER=%f crdy=%f\n", crd.x, crd.y);
			if (crd.y < fdf->h - 1)
				//brs(crd, crd.x, crd.y + 1, fdf);
				findpb(crd, crd.x, crd.y + 1, fdf);
			++crd.x;
		}
		++crd.y;
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 50, WHITE, "HERE");
//        break ;///
	}
//	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
