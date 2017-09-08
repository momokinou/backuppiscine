/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:38:27 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/08 12:28:55 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2(void)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 1;
	while(i <= 9)
	{
		while(j <= 9)
		{
			while(k <= 9)
			{
				while(l <= 9)
				{
					if(i + j < k + l && k >= i && l >= j)
					{
						ft_putchar('0' + i);
						ft_putchar('0' + j);
						ft_putchar(' ');
						ft_putchar('0' + k);
						ft_putchar('0' + l);
						ft_putchar(',');
						ft_putchar(' ');
					}
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

int main()
{
	ft_print_comb2();
	return(0);
}
