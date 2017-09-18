/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:38:27 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/13 14:20:08 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_if(int i, int j, int k, int l)
{
	if (i + j < k + l && k >= i && l >= j)
	{
		ft_putchar('0' + i);
		ft_putchar('0' + j);
		ft_putchar(' ');
		ft_putchar('0' + k);
		ft_putchar('0' + l);
		if (i + j != 17)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_while(int i, int j, int k, int l)
{
	while (i <= 9)
	{
		while (j <= 9)
		{
			while (k <= 9)
			{
				while (l <= 9)
				{
					ft_if(i, j, k, l);
					l++;
				}
				k++;
				l = 0;
			}
			j++;
			k = 0;
		}
		i++;
		j = 0;
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 1;
	ft_while(i, j, k, l);
}
