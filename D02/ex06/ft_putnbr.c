/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelapo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:00:01 by madelapo          #+#    #+#             */
/*   Updated: 2017/09/08 15:13:48 by madelapo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr (int nb)
{
	char dernier_chiffre;
	int inverse;

	if (nb < 0)
			{
				ft_putchar('-');
				dernier_chiffre = (char)('0' - (nb % 10));
				nb /= -10;
			}
	else
	{
		dernier_chiffre = (char)((nb % 10) + '0');
		nb /= 10;
	}
	 inverse = 0;
	while (nb > 0)
	{
		inverse = inverse * 10 + (nb % 10);
		nb /= 10;
	}	
	while (inverse >0)
	{
		char c = (char)((inverse % 10) + '0');
		ft_putchar(c);
		inverse /= 10;
	}
	ft_putchar(dernier_chiffre);	
}
int main(void)
{
	ft_putnbr(1450);
	return(0);
}
