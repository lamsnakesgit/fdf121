

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:24:51 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/12 23:04:07 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_projection(t_fdf *fdf, int key)
{
	if (key == PRL)
	{
		fdf->projection = PRL;
		fdf->angle_x = 0;
		fdf->angle_z = 0;
		fdf->angle_y = 0;
	}
	if (key == ISO)
	{
		fdf->angle_x = 0;
		fdf->angle_z = 0;
		fdf->angle_y = 0;
		fdf->projection = ISO;
	}
}

void		change_view(t_fdf *fdf, int key)
{
	change_projection(fdf, key);
	if (key == 126)
		fdf->shift_y -= 10;
	if (key == 125)
		fdf->shift_y += 10;
	if (key == 123)
		fdf->shift_x -= 10;
	if (key == 124)
		fdf->shift_x += 10;
	if (key == UP_Z)
		fdf->angle_z += 0.1;
	if (key == DOWN_Z)
		fdf->angle_z -= 0.1;
	if (key == UP_X)
		fdf->angle_x += 0.1;
	if (key == DOWN_X)
		fdf->angle_x -= 0.1;
	if (key == UP_Y)
		fdf->angle_y += 0.1;
	if (key == DOWN_Y)
		fdf->angle_y -= 0.1;
}

void		change_zoom(t_fdf *fdf, int key)
{
	if (key == 0)
		fdf->z_sh += 0.5;
	if (key == 1)
		fdf->z_sh -= 0.5;
	if (fdf->z_sh >= 20)
		fdf->z_sh = 20;
	if (fdf->z_sh <= -20)
		fdf->z_sh = -20;
	if (key == 12)
		fdf->zoom += 1;
	if (key == 13)
		fdf->zoom -= 1;
}

int			deal_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	change_view(fdf, key);
	change_zoom(fdf, key);
	draw_line(fdf);
	return (1);
}
