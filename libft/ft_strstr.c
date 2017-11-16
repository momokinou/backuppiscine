/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:42:01 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/16 13:50:30 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *s1, const char *s2)
{
	const char *s1_it;
	const char *s2_it;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		s1_it = s1;
		s2_it = s2;
		while (*s2_it != '\0' && *s1_it == *s2_it)
		{
			s1_it++;
			s2_it++;
		}
		if (*s2_it == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
