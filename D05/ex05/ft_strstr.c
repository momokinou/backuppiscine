/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:39:16 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/14 17:47:17 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (to_find[size])
		size++;
	if (size == 0)
		return (0);
	while (str[i])
	{
		while (to_find[j] == str[i +j])
		{
			if (j == size -1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
