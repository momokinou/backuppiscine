/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:46:23 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 10:22:43 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while(n)
	{
		str[n] = (unsigned char)c;
		n--;
	}
	b = (void *)str;
	return(b);
}
