/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:22:28 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 14:03:17 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;
	int i;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] != c)
			i++;
	}
	return (&str[i]);
}
