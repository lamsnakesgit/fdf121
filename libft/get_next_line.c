/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:05:22 by ddratini          #+#    #+#             */
/*   Updated: 2019/11/21 13:40:40 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "libft.h"

static int			ft_strchrdup(char **copyhfd, char **line)
{
	char *sav;

	if (ft_strchr(*copyhfd, '\n'))
	{
		*line = ft_strsub(*copyhfd, 0, ft_strchr(*copyhfd, '\n') - *copyhfd);
		sav = ft_strdup(ft_strchr(*copyhfd, '\n') + 1);
		ft_strdel(copyhfd);
		*copyhfd = sav;
		return (1);
	}
	else if (*copyhfd[0])
	{
		*line = ft_strdup(*copyhfd);
		ft_strdel(copyhfd);
		return (1);
	}
	else
	{
		ft_strdel(copyhfd);
		return (0);
	}
}

int					get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*copy_here[MAX_FD];
	int			rdretby;
	char		*save;

	if (BUFF_SIZE < 1 || fd < 0 || !line || fd >= MAX_FD)
		return (-1);
	if (copy_here[fd] == NULL)
		copy_here[fd] = ft_strnew(0);
	while ((rdretby = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rdretby] = '\0';
		save = ft_strjoin(copy_here[fd], buff);
		free(copy_here[fd]);
		copy_here[fd] = save;
		if (ft_strchr(copy_here[fd], '\n'))
			break ;
	}
	if (rdretby < 0)
		return (-1);
	if (rdretby == 0 && copy_here[fd] == NULL)
		return (0);
	return (ft_strchrdup(&copy_here[fd], &(*line)));
}
