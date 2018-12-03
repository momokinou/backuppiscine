/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flags.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:14:20 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:15:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_plusnbr(intmax_t n)
{
	uintmax_t x;

	x = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		x = -n;
	}
	if (x >= 10)
	{
		ft_printf_plusnbr(x / 10);
		ft_printf_plusnbr(x % 10);
	}
	else
		ft_putchar_fd(x + '0', 1);
}
