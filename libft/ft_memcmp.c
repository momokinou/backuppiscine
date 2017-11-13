/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:31:27 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 11:37:05 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*oct1;
	unsigned char	*oct2;
	int i;

	i = 0;
	oct1 = (unsigned char *)s1;
	oct2 = (unsigned char *)s2;
	while (oct1[i] && oct2[i] && n)
		{
			if (oct1 != oct2)
				return (s1 - s2);
			oct1++;
			oct2++;
		}
	return (0);
}
