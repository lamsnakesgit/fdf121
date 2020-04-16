/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:50:37 by ddratini          #+#    #+#             */
/*   Updated: 2020/03/13 16:19:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			**lines(char *buf, t_fdf *fdf)
{
	int		i;
	int		s;
	char	**ls;

	i = -1;
	s = 0;
	ls = 0;
	while (buf[++i])
		if (buf[i] == '\n')
			++s;
	if (!s)
		return (0);
	fdf->h = s;
	if (fdf->h < 1)
		return (0);
	if (!(ls = (char **)malloc(sizeof(char *) * (s + 2))))
		return (0);
	return (ls);
}

int				free_map(char **line)
{
	free(line[0]);
	free(line);
	return (0);
}

int				checkmap(char **ls, char *buf, int i, int j)
{
	int s;

	i = -1;
	ls[0] = buf;
	s = -1;
	while (buf[++i])
		if (buf[i] == '\n')
		{
			if (i - s < 2)
				return (free_map(ls));
			s = i;
			buf[i] = 0;
			if (buf[i + 1] == 0)
			{
				ls[++j] = 0;
				return (1);
			}
			if (buf[i + 1] == '\n' || !i)
				return (free_map(ls));
			ls[++j] = &(buf[i + 1]);
		}
	ls[++j] = 0;
	return (1);
}

char			**processmap(int fd, t_fdf *fdf)
{
	char	buf[BS + 1];
	int		ret;
	char	*cp;
	char	*sv;
	char	**ls;

	cp = ft_strnew(0);
	while ((ret = read(fd, buf, BS)) > 0)
	{
		buf[ret] = 0;
		sv = ft_strjoin(cp, buf);
		free(cp);
		cp = sv;
	}
	if (!cp || ret < 0 || !(ls = lines(cp, fdf)))
	{
		free(cp);
		return (0);
	}
	if (!(checkmap(ls, cp, -1, 0)))
		return (0);
	return (ls);
}
