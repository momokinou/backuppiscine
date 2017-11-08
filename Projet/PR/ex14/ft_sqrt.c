/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:18:11 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/07 13:26:59 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (result != nb)
	{
		result = i * i;
		if (result == nb)
			break ;
		else if (result > nb)
			return (0);
		else
			i++;
	}
	return (i);
}
