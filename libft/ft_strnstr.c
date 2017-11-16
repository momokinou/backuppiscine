/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:57:41 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/16 12:23:23 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	char	*j;
	char	*k;

	if (!*find)
		return ((char *)str);
	while (len-- && *str)
	{
		if (*str == *find)
		{
			i = len;
			j = (char *)str + 1;
			k = (char *)find + 1;
			while (i-- && *j && *k && *j == *k)
			{
				++j;
				++k;
			}
			if (!*k)
				return ((char *)str);
		}
		++str;
	}
	return (NULL);
}
