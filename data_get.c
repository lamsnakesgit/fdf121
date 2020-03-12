/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:26:38 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/11 23:26:47 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_high(t_fdf *fdf)
{
    char	*line;
    int		fd;
    int		h;

//	close(fd);//INTI??
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
    printf("BP1.1.1.1gw\nret=%d\nline=%%s", ret);//line);
    if (ret > 0)
        free(line);
    if (ret < 0)//1 ???line?
        return (0);
    w = ft_count_w(line, ' ');//ft_strsplit(line, ' ');//ft_wdcounter(line, ' ');
    printf("BP1.1.1.2gw\n");
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
        printf("FILLMi=%d\n%s", i, nums[i]);
        z_line[i] = ft_atoi(nums[i]);
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

int 		calc_size(t_fdf *fdf)
{
    int i;

    printf("BP1.1.1\n");
    if (!get_high(fdf))
        return (0);
    printf("BP1.1.2\n");
    if (!get_width(fdf))
        return (0);
    printf("BP1.1.3\n");
//    if (!calc_high(fdf, ))
    fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->h));// + 1));
//    if (!(fdf->z_matrix = (int **)malloc(sizeof(int*) * (fdf->h + 1))))
    if (!fdf->z_matrix)
        return (0);
    i = 0;
    while (i < fdf->h)
    {
        fdf->z_matrix[i] = (int *)malloc(sizeof(int) * (fdf->w));
        if (!fdf->z_matrix[i])
            free_z(fdf, i);
        ++i;
    }
    return (1);
}
