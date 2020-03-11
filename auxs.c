/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:36:02 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/07 21:38:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_blank(void *img, int szline)
{
	int i;
	int *mg;

	i = 0;
	mg = (int *)img;
	while (i < szline)
	{
		if (mg[i])
			mg[i] = 0;
		++i;
	}
	return (0);
}

void        ft_color(t_fdf *fdf)
{
//	float z;
//	float z1;
    int z;
    int z1;

    ////=================OLD
    z = fdf->z_matrix[(int)crd.y][(int)crd.x] * fdf->z_sh;
    z1 = fdf->z_matrix[(int)y1][(int)x1] * fdf->z_sh;

}

void        ft_modify(t_fdf *fdf, t_coord crd)
{
    crd.x *= (int)(fdf->zoom);
    crd.y *= (int)(fdf->zoom);
    x1 *= fdf->zoom;
    y1 *= fdf->zoom;
    fdf->color = (z || z1) > 0 ? RED : WHITE;
//	fdf->color = (z || z1) > 5 && (z || z1) < 9 ? YELLOW : RED;
    x_rotate(fdf, &crd.y, &z);
    x_rotate(fdf, &y1, &z1);
    y_rotate(fdf, &crd.x, &z);
    y_rotate(fdf, &x1, &z1);
    z_rotate(fdf, &crd.x, &crd.y);
    z_rotate(fdf, &x1, &y1);
    if (fdf->projection == ISO)
    {
        isometric(&crd.x, &crd.y, z, fdf);
        isometric(&x1, &y1, z1, fdf);
    }
    crd.x += fdf->shift_x;
    crd.y += fdf->shift_y;
    x1 += fdf->shift_x;
    y1 += fdf->shift_y;
    ///=======================NEW
    fdf->dy = mod(y1 - crd.y);
    fdf->dx = mod(x1 - crd.x);
    fdf->signy = crd.y < y1 ? 1 : -1;
    fdf->signx = crd.x < x1 ? 1 : -1;
    fdf->er = fdf->dx - fdf->dy;//!!
//	x_rotate(fdf, &x, &y, );
}
