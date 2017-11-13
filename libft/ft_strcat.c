/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:41:37 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/13 15:41:55 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s2[size])
		size++;
	while (s1[i])
	{
		s2[size] = s1[i];
		size++;
		i++;
	}
	s2[size] = '\0';
	return (s2);
}
