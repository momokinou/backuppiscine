/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:03:00 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/19 17:48:24 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	i = power;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i > 1)
	{
		result = (result * nb);
		i--;
	}
	return (result);
}
