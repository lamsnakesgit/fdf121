/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:36:02 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/07 21:38:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_blank(void *img, int szline)
{
	int i;
	int *mg;

	i = 0;
	mg = (int *)img;
	while (i < szline)
	{
		if (mg[i])
			mg[i] = 0;
		++i;
	}
	return (0);
}
/*
void        ft_modify()
{
	x_rotate(fdf, &x, &y, );
}*/