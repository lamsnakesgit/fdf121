/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:28:55 by ddratini          #+#    #+#             */
/*   Updated: 2020/04/16 07:05:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		mod(float a)
{
	return (a >= 0 ? a : -a);
}

void		brs(t_coord crd, int x1, int y1, t_fdf *fdf)
{
	int i;

	crd.y2 = y1;
	crd.x2 = x1;
	ft_modify(fdf, &crd);
	while (crd.x != crd.x2 || crd.y != crd.y2)
	{
		fdf->er2 = fdf->er * 2;
		//printf("sl=%d\nWIN=%d\nBPP=%d\n", fdf->sl, WIN_W_X,fdf->bpp);//8000, 800
		if (crd.x < WIN_W_X && crd.y < WIN_W_X && crd.x >= 0 && crd.y >= 0)
		{
			i = WIN_W_X * 4 * crd.y + crd.x;
        //    i = WIN_W_X  * crd.y + crd.x;
            //i =fdf->sl * crd.y + crd.x;
            fdf->img[i] = fdf->color;
		}
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

void		go_blank(t_fdf *fdf)
{
	int q;

	q = 0;
	while (q < WIN_W_X * WIN_W_X * 4)
	{
		fdf->img[q] = 0x00;
		++q;
	}
}

void		print_menu(t_fdf *fdf)
{
	int y;

	y = 15;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
			0, 0, WHITE, "P - parallel I - ISO");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
			0, 20, WHITE, "numpad - rotate");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
			0, 40, WHITE, "altitude A-S");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
			0, 60, WHITE, "zoom Q W");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
			0, 80, WHITE, "shift - ARROWS");
}

void		draw_line(t_fdf *fdf)
{
	t_coord	crd;

	crd.y = 0;
	go_blank(fdf);
	while (crd.y < fdf->h)
	{
		crd.x = 0;
		while (crd.x < fdf->w)
		{
			if (crd.x < fdf->w - 1)
				brs(crd, crd.x + 1, crd.y, fdf);
			if (crd.y < fdf->h - 1)
				brs(crd, crd.x, crd.y + 1, fdf);
			++crd.x;
		}
		++crd.y;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	print_menu(fdf);
}
