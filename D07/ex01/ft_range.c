/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:06:31 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/19 14:14:17 by qmoricea         ###   ########.fr       */
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
