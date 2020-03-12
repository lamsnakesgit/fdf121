/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:24:07 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/12 21:09:03 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(int *x, int *y, int z)
{
	float	prev_x;
	float	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}

void		x_rotate(t_fdf *fdf, int *y, int *z)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(fdf->angle_x) + *z * sin(fdf->angle_x);
	*z = -prev_y * sin(fdf->angle_x) + *z * cos(fdf->angle_x);
}

void		y_rotate(t_fdf *fdf, int *x, int *z)
{
	int prev_x;

	prev_x = *x;
	*x = prev_x * cos(fdf->angle_y) + *z * sin(fdf->angle_y);
	*z = -prev_x * sin(fdf->angle_y) + *z * cos(fdf->angle_y);
}

void		z_rotate(t_fdf *fdf, int *x, int *y)
{
	int prv_x;
	int prv_y;

	prv_x = *x;
	prv_y = *y;
	*x = prv_x * cos(fdf->angle_z) - prv_y * sin(fdf->angle_z);
	*y = prv_x * sin(fdf->angle_z) + prv_y * cos(fdf->angle_z);
}
