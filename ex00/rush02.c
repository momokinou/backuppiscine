/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:22:28 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/10 21:01:11 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_putchar(char c);

void	ft_begin(int countx, int x)
{
	if (countx == 1)
		ft_putchar('A');
		countx++;
	while (countx < x)
	{
		ft_putchar('B');
		countx++;
		if (countx == x)
			ft_putchar('A');
	}
	ft_putchar('\n');
}

void	ft_middle(int countx, int x, int y, int county)
{
	while (countx <= x)
	{
		if ((countx == 1) || (countx == x))
			ft_putchar('B');
		else
			ft_putchar(' ');
			countx++;
	}
	ft_putchar('\n');
}

void	ft_end(int countx, int x)
{
	if (countx == 1)
		ft_putchar('C');
		countx++;
	while (countx < x)
	{
			ft_putchar('B');
			countx++;
			if (countx == x)
				ft_putchar('C');
	}
}

void	rush(int x, int y)
{
	int countx;
	int county;

	countx = 1;
	county = 1;
	if (y == 0)
	{
		y = 1;
	}
	if (x == 0)
	{
		x = 1;
	}
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


