/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:24:16 by qmoricea          #+#    #+#             */
/*   Updated: 2017/09/19 17:55:57 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_neg(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_neg();
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar('0' + nb);
	}
}
