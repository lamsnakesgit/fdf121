/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:52:33 by ddratini          #+#    #+#             */
/*   Updated: 2020/02/09 18:24:49 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (0);
	if (content == NULL)
	{
		lstnew->content_size = 0;
		lstnew->content = NULL;
	}
	else
	{
		lstnew->content_size = content_size;
		lstnew->content = (void*)content;
	}
	lstnew->next = NULL;
	return (lstnew);
}
