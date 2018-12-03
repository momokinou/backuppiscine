/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestion_length.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 09:59:09 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:20:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int		ft_intlenc(unsigned int n, int i)
{
	if (n >= 10)
		return (ft_intlenc (n / 10, i + 1));
	else
		return (i + 1);
	return (0);
}

int		ft_intlen(int n)
{
	int				len;
	unsigned int	i;

	if (n < 0)
		i = n * -1;
	else
		i = n;
	len = ft_intlenc(i, 0);
	if (n < 0)
		len = len + 1;
	else
		len = len + 0;
	return (len);
}

int		octallength(int nbr)
{
	int len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len = 10;
	}
	else while (nbr >= 8)
	{
		nbr = nbr / 8;
		len++;
	}
	len++;
	return (len);
}

int		hexalength(int nbr)
{
	int len;

	len = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	len++;
	return (len);
}
