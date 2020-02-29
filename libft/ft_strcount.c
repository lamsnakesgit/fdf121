/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:28:19 by gusujio           #+#    #+#             */
/*   Updated: 2020/01/17 21:43:54 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char *s1, char *s2)
{
	int			i;
	long int	j;
	char		*s3;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if ((s3 = ft_strstr(&s1[j], s2)))
		{
			j = s3 - (s1 + j);
			s1 = s3;
			i++;
		}
		j++;
	}
	return (i);
}