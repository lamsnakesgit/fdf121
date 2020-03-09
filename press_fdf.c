/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:24:51 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/05 19:24:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key(int key, t_fdf *fdf)
{
	int	r;

//	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);//??
//	ft_bzero(fdf->img, WIN_W_X);//fdf->not_my_bus);
//	ft_bzero(fdf->img_ptr, WIN_W_X);//fdf->not_my_bus);
	if (key != 53 && key != 123 && key != 125 && key != 124 && key != 126 && key != 12 && key != 13)
		printf("key=%d\n", key);
	r = 0;
	if (key == 53)//ESC
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);//close(0);//?????
	//	sleep(20);
		exit(0);//return (0);
	}
	if (key == 126)
		fdf->shift_y -= 10;
	if (key == 125)
		fdf->shift_y += 10;
	if (key == 123)
		fdf->shift_x -= 10;
	if (key == 124)
		fdf->shift_x += 10;
	if (key == 6)//z
		fdf->projection = 1;
	if (key == 7)//x
		fdf->projection = 3;
	if (key == 0)//8) A-0
		fdf->z_sh += 1;
	if (key == 1)//S-1
		fdf->z_sh -= 1;
	if (key == UP_Z)
		fdf->rot_z += 10;
	if (key == DOWN_Z)
		fdf->rot_z -= 10;
	if (key == UP_X)
		fdf->rot_x += 10;
	if (key == DOWN_X)
		fdf->rot_x -= 10;
	if (key == UP_Y)
		fdf->rot_y += 10;
	if (key == DOWN_Y)
		fdf->rot_y -= 10;
	if (key == 12)//q w12 13)
		fdf->zoom += 1;//-10;
	if (key == 13)
		fdf->zoom -= 1;
//	else
//	{
//		printf("NOKEY|");
	//	mlx_loop(fdf->mlx_ptr);
	//	mlx_mouse_hook(fdf->win_ptr, deal_mouse, fdf);
//	}
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);//putimage?
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
