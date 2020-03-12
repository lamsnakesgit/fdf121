/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:39:56 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/11 23:40:46 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int  		free_z(t_fdf *fdf, int i)
{
    int c;

    c = 0;
    while(c < i)
    {
        free(fdf->z_matrix[c]);
        ++c;
    }
    free(fdf->z_matrix);
    return (0);
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
