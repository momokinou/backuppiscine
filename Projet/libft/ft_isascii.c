/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:09:07 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/09 15:25:49 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isascii(int c)
{
	if (c >= 0 && c <= 177)
		return (1);
	return (0);
}