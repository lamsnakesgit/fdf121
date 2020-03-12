/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:23:56 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/11 23:23:58 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_w(char  *s, char c)
{
	int i;
	int	word;

	i = 0;
	//printf("=%s=\n", s);
	while (s[i] && s[i] == c)
    {
        ++i;
    }
	word = 0;
    while (s[i])
	{
		if (s[i] != c)
			++word;
        while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
	}
	return (word);
}
