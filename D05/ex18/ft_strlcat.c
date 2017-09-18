/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:20:59 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/15 17:36:12 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	size = 0;
	while (dest[size])
		size++;
	while (src[i])
	{
		i++;
		size++;
	}
	return (size);
}
