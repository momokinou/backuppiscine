/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:12:27 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/11 20:42:25 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	res = nb;
	if (nb >= 12 || nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (nb >= 2)
	{
		res = (nb - 1) * res;
		nb--;
	}
	return (res);
}
