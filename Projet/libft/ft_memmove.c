/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:32:35 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/10 12:07:39 by qmoricea         ###   ########.fr       */
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
		oct1++;
		oct2++;
	}
	return (dst);
}
