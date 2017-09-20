/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recrusive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:27:08 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/19 17:51:16 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int		i;

	i = power;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (i > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (0);
}
