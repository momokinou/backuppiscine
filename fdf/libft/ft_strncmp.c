/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:40:29 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/16 13:52:17 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	while (len > 0 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
