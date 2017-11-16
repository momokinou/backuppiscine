/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:13:36 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/16 13:08:19 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *i;

	i = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			i = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (i);
}
