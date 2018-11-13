/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printlong.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:54:01 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:55:28 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putnbr_ld(long n)
{
	if (n == -9223372036854775807)
		ft_putstr("-9223372036854775807");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr_ld(n / 10);
		ft_putnbr_ld(n % 10);
	}
	else
		ft_putchar('0' + n);
}
