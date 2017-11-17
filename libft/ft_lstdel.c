/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:32:51 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/17 16:28:44 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nextlist;

	list = *alst;
	while (list != NULL)
	{
		nextlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nextlist;
	}
	*alst = NULL;
}
