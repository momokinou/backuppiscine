/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 20:51:34 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/15 21:25:21 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_min(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] >= 'k')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		i++;
	}
	return (str);
}

char	*ft_maj(char *str)
{
	int i;

	i= 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str [i] >= 'K')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		i++;
	}
	return (str);
}

char	*ft_rot42(char *str)
{
	ft_min(str);
	ft_maj(str);
	return (str);
}
