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

int			get_high(t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		h;

	close(fd);
	fd = open(fdf->fname, O_RDONLY);
	if (fd < 0)
		return (0);
	h = 0;
	while (get_next_line(fd, &line) > 0)
	{
		h++;
		free(line);
	}
	close(fd);
	fdf->h = h;
	return (h);
}

int         get_width(t_fdf *fdf)
{
	int		fd;
	int		w;
	char	*line;
	int 	ret;

	fd = open(fdf->fname, O_RDONLY);
	if (fd < 0)
		return(0);//ft_err());
	ret = get_next_line(fd, &line);
	if (ret < 0)//1 ???line?
		return (0);
	w = ft_count_w(line, ' ');//ft_strsplit(line, ' ');//ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	fdf->w = w;
	return (w);
}

void		fill_matrix(int *z_line, char *line)//t_fdf *data, char *line)
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
	//	printf("zline[i]=%4d | i=%d line=%s\n", z_line[i], i, line);
		free(nums[i]);
		++i;
	}
	free(nums);
}
int 		calc_high(t_fdf *fdf, char **map)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (map[i])
	{
		++i;
		++h;
	}
	fdf->h = h;
	return (h);
}
int			read_file(t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;
	char 	**map;

	if (!get_high(fdf))
		return (0);
	if (!get_width(fdf))
		return (0);
	fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->h + 1));
	i = 0;
	while (i <= fdf->h)
		fdf->z_matrix[i++] = (int *)malloc(sizeof(int) * (fdf->w + 1));
	fd = open(fdf->fname, O_RDONLY);
	i = 0;
	if (!(map = processmap(fd)))
		return (0);
//	fdf->h = calc_high(fdf, map);
//	fdf->w = ft_count_w(map[0], ' ');//''char
//	if (fdf->w < 0 || fdf->h < 0)//point??????
//		return(0);
//	fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->h + 1));
	i = 0;
//	while (i <= fdf->h)
//		fdf->z_matrix[i++] = (int *)malloc(sizeof(int) * (fdf->w + 1));
	while (map[i])//(get_next_line(fd, &line) > 0)
	{
		fill_matrix(fdf->z_matrix[i], map[i]);//line);
		//free(line);
		++i;
	}
/*	while (get_next_line(fd, &line) > 0)
	{
		fill_matrix(fdf->z_matrix[i], line);//map[i]);//line);
		free(line);
		++i;
	}
*/	close(fd);
	fdf->z_matrix[i] = NULL;//0;
	i = 0;
	int y = 0;
/*	while (i < fdf->h)//(i <= fdf->h)
	{
		y = -1;
		while (++y < fdf->w - 2)
		{
            printf("%3d ", fdf->z_matrix[i][y]);//printf("%3d ", fdf->z_matrix[i][y]);
        }
		++i;
		printf("\nPPPP");
	}*/
	return (1);
}

int			data_init(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W_X, WIN_H_Y, "ГОРИ В АДУ");//"OPENWIN");
	fdf->bpp = 32;
	fdf->color = 0;//SEG?
	fdf->endian = 0;
	fdf->img = NULL;
//	fdf->img = (int )malloc(sizeof(int) * fdf->w);
//	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1300);
//	fdf->img = (int *)	mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->w, &fdf->endian);
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->projection = PRL;// 1;
	fdf->zoom = 10;
	fdf->shift_x = 50;
	fdf->shift_y = 50;
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
	read_file(fdf);//(data, fname);x
	data_init(fdf);
	printf("FDFcolor=%d \n", fdf->color);
	draw_line(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);//3
//	mlx_hook(fdf->win_ptr, 17, 0, deal_key, fdf);
//	mlx_key_hook(fdf->win_ptr, deal_key, fdf);//NULL);
//	mlx_mouse_hook(fdf->win_ptr, mouse_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	//bresenham(10, 10, 600, 300, fdf);
    return (0);
}


int		ft_err()
{
	write(1, "usage: ./fdf map_file\n", 22);
	return (0);
}
