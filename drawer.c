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
	int i;//	printf(" ZSH=%d\n", fdf->z_sh);
	crd.y2 = y1;
	crd.x2 = x1;
	ft_modify(fdf, &crd);
	i = 0;
	while (crd.x != crd.x2 || crd.y != crd.y2)
    {
	    fdf->er2 = fdf->er * 2;	//    if (crd.y >= 0 && crd.y < fdf->h && crd.x >= 0 && crd.x <= fdf->w)
	    if (crd.y >= 0 && crd.y < fdf->not_my_bus && crd.x >= 0 && crd.x <= fdf->not_my_bus)//WIN_W_X)
	    {
            if (crd.x < WIN_W_X && crd.y < WIN_W_X && crd.x >= 0 && crd.y >= 0)
            {
                i = WIN_W_X * 4 * crd.y + crd.x;
                fdf->img[i] = fdf->color;
            }
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
    printf("ZEZOOM=%d\n", fdf->zoom);
    while (crd.y < fdf->h )//-2 )
	{
		crd.x = 0;
		while (crd.x < fdf->w )//-2 )
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
