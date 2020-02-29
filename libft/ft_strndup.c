/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:40:10 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/17 19:43:25 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(char const *s, size_t n)
{
	char		*dups;
	size_t		i;

	i = 0;
	dups = (char *)malloc(sizeof(char) * (n + 1));
	if (!dups)
		return (NULL);
	while (s[i] && i < n)
	{
		dups[i] = s[i];
		i++;
	}
	dups[i] = '\0';
	return (dups);
}
