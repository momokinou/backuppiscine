/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 09:11:15 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/08 11:33:03 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while(i <= 9)
	{
		while(j <= 9)
		{
			while(k <= 9)
			{
				if(i < j && j < k)
				{
					ft_putchar('0' + i);
					ft_putchar('0' + j);
					ft_putchar('0' + k);
					if(i != 7)
						{
							ft_putchar(',');
							ft_putchar(' ');
						}
				}
				k++;
			}
			k=0;
			j++;
		}
		j=0;
		i++;
	}
}

int main()
{
	ft_print_comb();
	return(0);
}

