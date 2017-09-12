/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:59:40 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/12 14:41:27 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else
	{
		if (index == 1 || index == 0)
			return (1);
	}
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
