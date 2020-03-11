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

	i = 0;
	crd.y2 = y1;
	crd.x2 = x1;
	ft_modify(fdf, &crd);
	WIN_W_X > fdf->not_my_bus ? printf("WINWX=%d\n") : printf("nnbsz=%d\nW=%d", fdf->not_my_bus, WIN_W_X);
	while (crd.x != x1 || crd.y != y1)
    {
	    fdf->er2 = fdf->er * 2;
        if (crd.x < WIN_W_X && crd.y < WIN_W_X)
        {
            i = WIN_W_X * 4 * crd.y + crd.x;
            fdf->img[i] = fdf->color;
        }
	    if (fdf->er2 > -fdf->dy)
	    {
	        fdf->er -= fdf->dy;
            crd.x += fdf->signx;
        }
	    if (fdf->er2 < fdf->dx)
	    {
            fdf->er += fdf->dx;
            crd.y += fdf->signy;
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

	go_blank(fdf);
	crd.y = 0;
    printf("ZEZOOM=%d\n", fdf->zoom);
    while (crd.y < fdf->h )//-2 )
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
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 50, WHITE, "P - parallel I - ISO\nnumpad - rotate\n");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 61, 61, WHITE, "numpad - rotate\n");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 72, 72, WHITE, "\nd");
}
