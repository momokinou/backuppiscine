/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:30:27 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/07 17:03:21 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int a;
	int *tab;

	a = 0;
	tab = 0;
	if (min >= max)
		return (tab);
	tab = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		tab[a] = min;
		a++;
		min++;
	}
	return (tab);
}
