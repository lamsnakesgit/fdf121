/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:24:51 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/11 22:06:55 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void        change_view(t_fdf *fdf, int key)
{
    if (key == PRL)//6)//z
        fdf->projection = PRL;//1;
    if (key == ISO)//7)//x
        fdf->projection = ISO;//3;
    if (key == 126)
        fdf->shift_y -= 10;
    if (key == 125)
        fdf->shift_y += 10;
    if (key == 123)
        fdf->shift_x -= 10;
    if (key == 124)
        fdf->shift_x += 10;
    if (key == UP_Z)//7
        fdf->angle_z += 0.1;
    if (key == DOWN_Z)//9
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

void        change_zoom(t_fdf *fdf, int key)
{
    if (key == 0)//8) A-0
        fdf->z_sh += 0.5;
    if (key == 1)// && fdf->z_sh > 0)//S-1
        fdf->z_sh -= 0.5;
    if (fdf->z_sh >= 20)// || fdf->z_sh == -20)
        fdf->z_sh = 20;
    if (fdf->z_sh <= -20)
        fdf->z_sh = -20;
    if (key == 12)//q w12 13)
        fdf->zoom += 1;
    if (key == 13)
        fdf->zoom -= 1;
}

int			deal_key(int key, t_fdf *fdf)
{
//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);//??
	if (key != 53 && key != 123 && key != 125 && key != 124 && key != 126 && key != 12 && key != 13)
		printf("key=%d\n", key);
	if (key == 53)//ESC
	{
	    mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);//close(0);//?????
//		sleep(20);
		exit(0);//return (0);
	}
	change_view(fdf, key);
	change_zoom(fdf, key);
	draw_line(fdf);
	return (1);
}

int			deal_mouse(int m, t_fdf *fdf)
{
	printf("MOUSE=%d\n", m);
	return (0);
}

int			mouse_press(int press, int x, int y, void *param)
{
	printf("MOUSE=%d x=%d y=%d\n", press, x, y);
	return (0);
}
