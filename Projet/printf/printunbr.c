/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printunbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:00:57 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:04:53 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putunbr_fd(intmax_t n, int fd)
{
	uintmax_t x;
	uintmax_t negret;

	x = n;
	negret = n;
	if (n < 0)
	{
		x = 4294967296 + n;
		negret = 4294967296 + n;
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
	return (ft_intlenc(negret, 0));
}

int		ft_putunbr(intmax_t n)
{
	return (ft_putunbr_fd(n, 1));

}

int		ft_putunbr_ld(long long n)
{
	int negret;

	negret = n;
	if (n == -9223372036854775807)
		ft_putstr("9223372036854775809");
	else if (n < 0)
		n = 9223372036854775807 + n;
	else if (n >= 10)
	{
		ft_putnbr_ld(n / 10);
		ft_putnbr_ld(n % 10);
	}
	else
		ft_putchar('0' + n);
	if (negret < 0)
		return (19);
	return (ft_intlen(negret));
}

int		ft_putunbr_hd(short n)
{
	int stock;
	int x;

	stock = n;
	x = n;
	if (n == -32767)
		ft_putstr("-32767");
	else if (n < 0)
	{
		x = 65536 + n;
		stock = 65536 + n;
	}
	if (x >= 10)
	{
		ft_putunbr_hd(x / 10);
		ft_putunbr_hd(x % 10);
	}
	else
		ft_putnbr(x);
	return (ft_intlen(stock));
}
