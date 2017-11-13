/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:40:09 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 15:26:03 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s2[size])
		size++;
	while (s1[i] && i < n)
	{
		s2[size] = s1[i];
		size++;
		i++;
	}
	s2[size] = '\0';
	return (s2);
}
