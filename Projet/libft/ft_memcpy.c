/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:03:26 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/10 12:03:42 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *oct1;
	unsigned char *oct2;

	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	while (n--)
	{
		*oct1 = *oct2;
		if (*oct1 == (unsigned char)c)
			return (oct1 + 1);
		oct1++;
		oct2++;
	}
	return (NULL);
}
