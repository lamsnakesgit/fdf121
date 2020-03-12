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

/*
** read map; calc high; alloc zmatptr; cnt number in each line && cmp;
** if even fillmatrix if not free mpa + zptr + zarr
*/

int			read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;
	char 	**map;
	size_t  slen;

	printf("BP1.2\n");
//	if (!calc_size(fdf))
//		return(0);
	printf("BP1.3\n");
	fd = open(fdf->fname, O_RDONLY);
	printf("FD-readfile=%d\n", fd);
	i = 0;
	if (!(map = processmap(fd, fdf)))
	{
	//	free_z(fdf, fdf->h);
		return (0);
	}
	fdf->z_matrix = (int **)malloc(sizeof(int *) * fdf->h);//?-1?
	if (!fdf->z_matrix)
        return (free_map(map));
	fdf->w = ft_count_w(map[0], ' ');
	//slen = ft_strlen(map[0]);
	i = 1;
	while (map[i])//cmp len/cnt of params numbs
    {
	    if (ft_count_w(map[i], ' ') != fdf->w)//if (ft_strlen(map[i]) != slen)
            return (free_map(map) && free_z(fdf, 0));
	    ++i;
    }
	i = 0;
	printf("NOWFILL\n");
	while (map[i])
	{
	    fdf->z_matrix[i] = (int *)malloc(sizeof(int) * fdf->w);
	    if (!fdf->z_matrix[i])
	        free_z(fdf, i);
		fill_matrix(fdf->z_matrix[i], map[i]);
		++i;
	}
	close(fd);
	printf("ZMATRIXI=%d\nfdf-h=%d\nfdf-w=%d\n", i, fdf->h, fdf->w);
	//df->z_matrix[i] = NULL;//0;
	printf("ZOK\n");
	free_map(map);
	return (1);
}

int			data_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W_X, WIN_W_X,
	        "uwu");//"OPENWIN");
	fdf->bpp = 32;
	fdf->color = 0;//SEG?
	fdf->endian = 0;
	fdf->img = NULL;
	printf("DATAINIT\n");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
///fdf->img=(int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->w, &fdf->endian);
    fdf->img = (int *)
    mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->not_my_bus, &fdf->endian);
	fdf->angle_y = 0;
	fdf->angle_x = 0;
	fdf->angle_z = 0;
	fdf->zmv = 1;
	printf("NEXTINIT\n");
	fdf->xmv = WIN_W_X / 2;
	fdf->ymv = WIN_W_X / 2;
	fdf->projection = PRL;// 1;
	fdf->zoom = 10;
	fdf->shift_x = 50;
	fdf->shift_y = 50;
	fdf->z_sh = 1;
	return (0);
}

int         isvalid(int ac, char **av)
{
    int fd;

    if (ac != 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    printf("FDOPEN=%d\n", fd);
//    close(fd);
//    printf("FDCLOSE=%d\n", fd);
    if (fd < 0)
        return (0);
    close(fd);
    printf("FDCLOSE=%d\n", fd);
    return (fd);
}
int			main(int ac, char **av)
{
	t_fdf	*fdf;
	int		i;
	int		j;
	int     fd;

	if ((fd = isvalid(ac, av) <= 0))
	    return (ft_err());
	printf("av1=%s\n", av[1]);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->fname = av[1];	//fd = open(av[1], O_RDONLY);//open twice
//	close(fd);//i closed it??
	printf("BP1\n");
	if (!read_file(fdf))//(data, fname);x
    {
	    sleep(8);
	    exit(0);
    }
    printf("BP2\n");
    ft_printf("BP2--=2\n");
    write(1, "BP2==32\n", 8);
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
