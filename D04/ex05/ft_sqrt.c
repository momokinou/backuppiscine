/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:04:51 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/19 17:50:56 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;
	int		result;

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
