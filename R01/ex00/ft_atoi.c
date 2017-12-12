/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoginet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 08:37:18 by yoginet           #+#    #+#             */
/*   Updated: 2017/09/17 16:55:29 by yoginet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_atoi(char *str)
{
	int bn;
	int nb;

	bn = 1;
	nb = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
	*str == ' ' || *str == '\f')
		str++;
	if (*str == '-')
	{
		bn = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb *= 10;
		nb += (*str - 48);
		str++;
	}
	return (nb * bn);
}