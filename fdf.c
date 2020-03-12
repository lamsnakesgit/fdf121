

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/12 22:30:16 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** read map; calc high; alloc zmatptr; cnt number in each line && cmp;
** if even fillmatrix if not free mpa + zptr + zarr
*/

int			check_fill(t_fdf *fdf, char **map, int fd)
{
	int i;

	fdf->w = ft_count_w(map[0], ' ');
	i = 1;
	while (map[i])
	{
		if (ft_count_w(map[i], ' ') != fdf->w)
			return (free_map(map) && free_z(fdf, 0));
		++i;
	}
	i = 0;
	while (map[i])
	{
		fdf->z_matrix[i] = (int *)malloc(sizeof(int) * fdf->w);
		if (!fdf->z_matrix[i])
			return (free_z(fdf, i) && free_map(map));
		fill_matrix(fdf->z_matrix[i], map[i]);
		++i;
	}
	close(fd);
	free_map(map);
	return (1);
}

int			read_file(t_fdf *fdf)
{
	int		fd;
	char	**map;

	fd = open(fdf->fname, O_RDONLY);
	if (!(map = processmap(fd, fdf)))
		return (0);
	fdf->z_matrix = (int **)malloc(sizeof(int *) * fdf->h);
	if (!fdf->z_matrix)
		return (free_map(map));
	if (!check_fill(fdf, map, fd))
		return (0);
	return (1);
}

int			data_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W_X, WIN_W_X,
			"FdF");
	fdf->bpp = 32;
	fdf->color = 0;
	fdf->endian = 0;
	fdf->img = NULL;
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
	fdf->img = (int *)
		mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->sl, &fdf->endian);
	fdf->angle_y = 0;
	fdf->angle_x = 0;
	fdf->angle_z = 0;
	fdf->projection = PRL;
	fdf->zoom = 10;
	fdf->shift_x = 50;
	fdf->shift_y = 50;
	fdf->z_sh = 1;
	return (0);
}

int			isvalid(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (fd);
}

int			main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;

	if ((fd = isvalid(ac, av) <= 0))
		return (ft_err());
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->fname = av[1];
	if (!read_file(fdf))
	{
		ft_err();
	//	sleep(8);
		exit(0);
	}
	data_init(fdf);
	draw_line(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
