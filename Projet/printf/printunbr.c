/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printunbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:48:00 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:53:49 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putunbr_fd(intmax_t n, int fd)
{
	uintmax_t x;

	x = n;
	if (n < 0)
		x = 4139320750;
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}

void		ft_putunbr(intmax_t n)
{
	ft_putunbr_fd(n, 1);
}

/*    Printf Int + Unsigned Int    */

int			ft_printf_nbr(int nbr)
{
	ft_putnbr(nbr);
	return (ft_intlen(nbr));
}

int			ft_printf_unbr(int nbr)
{
	ft_putunbr(nbr);
	return (ft_intlen(nbr));
}
