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

void 		brs(t_coord crd, int x1, int y1, t_fdf *fdf)
{

	int i;
//	float z;
//	float z1;
	int z;
	int z1;
//	t_coord crd;
//	printf(" ZSH=%d\n", fdf->z_sh);
	////=================OLD
//	crd = c;
	crd.y2 = y1;
	crd.x2 = x1;
	z = fdf->z_matrix[(int)crd.y][(int)crd.x] * fdf->z_sh;
	z1 = fdf->z_matrix[(int)crd.y2][(int)crd.x2] * fdf->z_sh;
    crd.x *= (int)(fdf->zoom);
    crd.y *= (int)(fdf->zoom);
    crd.x2 *= fdf->zoom;
    crd.y2 *= fdf->zoom;
//	z *= fdf->zoom; z1 *= fdf->zoom;//
	fdf->color = (z || z1) > 0 ? RED : WHITE;
//	z += fdf->z_sh;
//	z1 += fdf->z_sh;
//	fdf->color = (z || z1) > 5 && (z || z1) < 9 ? YELLOW : RED;
	x_rotate(fdf, &crd.y, &z);
	x_rotate(fdf, &crd.y2, &z1);
	y_rotate(fdf, &crd.x, &z);
	y_rotate(fdf, &crd.x2, &z1);//z;
	z_rotate(fdf, &crd.x, &crd.y);
	z_rotate(fdf, &crd.x2, &crd.y2);
    if (fdf->projection == ISO)
    {
        isometric(&crd.x, &crd.y, z, fdf);
        isometric(&crd.x2, &crd.y2, z1, fdf);
    }
    crd.x += fdf->shift_x; //150;
    crd.y += fdf->shift_y;//150;
    crd.x2 += fdf->shift_x;//150;//05;
    crd.y2 += fdf->shift_y;//150;
	fdf->dy = mod(crd.y2 - crd.y);
	fdf->dx = mod(crd.x2 - crd.x);
	fdf->sy = crd.y < crd.y2 ? 1 : -1;
	fdf->sx = crd.x < crd.x2 ? 1 : -1;
	fdf->er = fdf->dx - fdf->dy;//!!
//	er2 = dy + 1;
	i = 0;
	while (crd.x != crd.x2 || crd.y != crd.y2)
    {
	    fdf->er2 = fdf->er * 2;
	//    if (crd.y >= 0 && crd.y < fdf->h && crd.x >= 0 && crd.x <= fdf->w)
	    if (crd.y >= 0 && crd.y < fdf->not_my_bus && crd.x >= 0 && crd.x <= fdf->not_my_bus)//WIN_W_X)
	    {
        //    i = fdf->w * crd.y + crd.x;
		//    i = fdf->not_my_bus * crd.y + crd.x;
        //    if (WIN_W_X * 4 * crd.y + crd.x > 2147483647)//< 0)
        //    if (WIN_W_X * 4  < 0 || WIN_W_X * 4 > 2147483647)//< 0)
    //        if (crd.x > fdf->w * 4/*+ 1*/|| crd.x > 2147483647)//< 0)
        /*    if (crd.x > WIN_W_X - 1 || crd.y > WIN_W_X)
            {
		        fdf->color = YELLOW;//+=1;//0;
		     //   printf("WEFQWRFARGAERGAFGADFGAF\n\n\n\n\n\n\n\n\n\n\n\n\n");
            }*/
            if (crd.x < WIN_W_X && crd.y < WIN_W_X && crd.x >= 0 && crd.y >= 0)
            {
                i = WIN_W_X * 4 * crd.y + crd.x;
                //    printf("i=%d w=%d h=%d y=%d x=%d y2=%d x2=%d WIN=%d\n", i,fdf->w,fdf->h,crd.y,crd.x,y1,x1
                //    , WIN_W_X);
                fdf->img[i] = fdf->color;
            }
        }
     //   printf("i=%d w=%d h=%d y=%d x=%d y2=%d x2=%d\n", i,fdf->w,fdf->h,crd.y,crd.x,y1,x1);
	 //   printf("AFTER");
	    if (fdf->er2 > -fdf->dy)
	    {
	        fdf->er -= fdf->dy;
            crd.x += fdf->sx;
        }
	    if (fdf->er2 < fdf->dx)
	    {
            fdf->er += fdf->dx;
            crd.y += fdf->sy;
        }
    }
}

void        go_blank(t_fdf *fdf)
{
    int q;

    q = 0;
    while (q < WIN_W_X * WIN_W_X * 4)
    {
        fdf->img[q] = 0x00;
        ++q;
    }
}
void		draw_line(t_fdf *fdf)
{
	t_coord	crd;
	int x;
	int y;

	crd.y = 0;
	go_blank(fdf);
//	printf("fdf-h=%d fdf->w=%d \n", fdf->h, fdf->w);
    printf("ZEZOOM=%d\n", fdf->zoom);
    while (crd.y < fdf->h )//-2 )
	{
		crd.x = 0;
		//	printf("ASDF=y=%f x=%f y+1 x + 1\n", crd.y, crd.x);
		while (crd.x < fdf->w )//-2 )
		{
			if (crd.x < fdf->w - 1)
				brs(crd, crd.x + 1, crd.y, fdf);
			//		printf("WER=%f crdy=%f\n", crd.x, crd.y);
			if (crd.y < fdf->h - 1)
				brs(crd, crd.x, crd.y + 1, fdf);
			++crd.x;
		}
		++crd.y;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 50, WHITE, "P - parallel I - ISO\nnumpad - rotate\n");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 61, 61, WHITE, "numpad - rotate\n");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 72, 72, WHITE, "\nd");
}
