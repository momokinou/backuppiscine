/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecorne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:57:26 by alecorne          #+#    #+#             */
/*   Updated: 2017/09/10 16:14:36 by alecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_putchar(char c);

void	ft_pl(int x)
{
	int i;

	i = 0;
	if (x != 1)
	{
		ft_putchar('A');
		while (i < x - 2)
		{
			ft_putchar('B');
			i++;
		}
	}
	ft_putchar('A');
	ft_putchar('\n');
}

void	ft_hl(int x, int y)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < y - 2)
	{
		ft_putchar('B');
		if (x != 1)
		{
			while (k < x - 2)
			{
				ft_putchar(' ');
				k++;
			}
			ft_putchar('B');
			k = 0;
		}
		i++;
		ft_putchar('\n');
	}
}

void	ft_dl(int x, int y)
{
	int i;

	i = 0;
	if (y != 1)
	{
		if (x != 1)
		{
			ft_putchar('C');
			while (i < x - 2)
			{
				ft_putchar('B');
				i++;
			}
		}
		ft_putchar('C');
		ft_putchar('\n');
	}
}

void	rush02(int x, int y)
{
	int i;

	i = 0;
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
	}
	else
	{
		ft_pl(x);
		ft_hl(x, y);
		ft_dl(x, y);
	}
}
