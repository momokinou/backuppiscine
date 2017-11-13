/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:32:35 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 12:22:21 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, void const *src, size_t n)
{
	int i;
	unsigned char *tmp;
	unsigned char *tmp2;

	i = 0;
	tmp = (unsigned char*)src;
	tmp2 = (unsigned char*)dest;
	while (n)
	{
		tmp2[i] = tmp[i];
		i++;
	}
	dest = (void *)tmp2;
	return (dest);
}
