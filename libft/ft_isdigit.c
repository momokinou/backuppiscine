/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:26:02 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 15:43:11 by qmoricea         ###   ########.fr       */
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
int		isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
