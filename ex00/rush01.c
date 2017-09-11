/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:02:04 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/11 11:31:20 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_begin(int countx, int x)
{
	if (countx == 1)
		ft_putchar(47);
	countx++;
	while (countx < x)
	{
		ft_putchar('*');
		countx++;
		if (countx == x)
			ft_putchar('\\');
	}
	ft_putchar('\n');
}

void	ft_middle(int countx, int x, int y, int county)
{
	while (countx <= x)
	{
		if ((countx == 1) || (countx == x))
			ft_putchar('*');
		else
			ft_putchar(' ');
		countx++;
	}
	ft_putchar('\n');
}

void	ft_end(int countx, int x)
{
	if (countx == 1)
		ft_putchar('\\');
	countx++;
	while (countx < x)
	{
		ft_putchar('B');
		countx++;
		if (countx == x)
			ft_putchar(47);
	}
}

void	rush(int x, int y)
{
	int countx;
	int county;

	countx = 1;
	county = 1;
	if (x >= 0 || y >= 0)
	{
		if (county == 1)
		{
			ft_begin(countx, x);
			county++;
		}
		countx = 1;
		while (county > 0 && county < y)
		{
			ft_middle(countx, x, y, county);
			county++;
		}
		countx = 1;
		if (county == y)
			ft_end(countx, x);
	}
}
