/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:21 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/04 22:03:31 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;
	char 	**map;

	printf("BP1.2\n");
	if (!calc_size(fdf))
		return(0);
	printf("BP1.3\n");
	fd = open(fdf->fname, O_RDONLY);
	i = 0;
	if (!(map = processmap(fd)))
	{
		free_z(fdf, fdf->h);
		return (0);
	}
	i = 0;
	while (map[i])
	{
		fill_matrix(fdf->z_matrix[i], map[i]);
		++i;
	}
	close(fd);
	fdf->z_matrix[i] = NULL;//0;
	free_map(map);
	return (1);
}

int			data_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W_X, WIN_W_X,
	        "BURN IN HELLУ");//"OPENWIN");
	fdf->bpp = 32;
	fdf->color = 0;//SEG?
	fdf->endian = 0;
	fdf->img = NULL;
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
///fdf->img=(int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->w, &fdf->endian);
    fdf->img = (int *)
        mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->not_my_bus, &fdf->endian);
	fdf->angle_y = 0;
	fdf->angle_x = 0;
	fdf->angle_z = 0;
	fdf->zmv = 1;
	fdf->xmv = WIN_W_X / 2;
	fdf->ymv = WIN_W_X / 2;
	fdf->projection = PRL;// 1;
	fdf->zoom = 10;
	fdf->shift_x = 50;
	fdf->shift_y = 50;
	fdf->z_sh = 1;
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf	*fdf;
	int		i;
	int		j;

	if (ac != 2)
		ft_err();
	printf("av1=%s\n", av[1]);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->fname = av[1];
	int fd = open(av[1], O_RDONLY);//open twice
	if (fd < 0)
        return (ft_err());
	close(fd);//i closed it??
	printf("BP1\n");
	if (!read_file(fdf))//(data, fname);x
	    exit(0);
	ft_printf("BP2\n");
	//free_map();
	data_init(fdf);
	printf("FDFcolor=%d w=%d h=%d\n", fdf->color, fdf->w, fdf->h);
	draw_line(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//3
//	mlx_hook(fdf->win_ptr, 17, 0, deal_key, fdf);
//	mlx_key_hook(fdf->win_ptr, deal_key, fdf);//NULL);
//	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
	mlx_loop(fdf->mlx_ptr);
    return (0);
}

int		ft_err()
{
	write(1, "usage: ./fdf map_file\n", 22);
	return (0);
}
