/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printshort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:55:37 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:57:45 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

/*    Lenght h pour d/i    */

void		ft_putnbr_hd(short n)
{
	if (n == -32767)
		ft_putstr("-32767");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr_hd(n / 10);
		ft_putnbr_hd(n % 10);
	}
	else
		ft_putchar('0' + n);
}
