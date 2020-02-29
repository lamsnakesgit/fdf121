/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:16:41 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 18:56:52 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_word(char const *s, char c)
{
	int i;
	int	word;

	i = 0;
	while (s[i] && s[i] == c)
		++i;
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

int			ft_len(char *s, char c)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (s[i] && s[i] != c)
	{
		++cnt;
		++i;
	}
	return (cnt);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		m;
	char	**spt;
	int		ff;

	if (!s)
		return (0);
	i = 0;
	m = 0;
	if (!(spt = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (0);
	while (s[m])
	{
		while (s[m] && s[m] == c)
			++m;
		ff = m;
		while (s[m] && s[m] != c)
			++m;
		if (ff < m)
			if (!(spt[i++] = ft_strndup(s + ff, m - ff)))
				return (ft_cleanmem(spt));
	}
	spt[i] = 0;
	return (spt);
}
