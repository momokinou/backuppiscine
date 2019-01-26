/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_hexa_octal.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:12:27 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:09:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_x(uintmax_t n)
{
	if (n >= 16)
		return (ft_printf_x(n / 16) + ft_printf_x(n % 16));
	else
		return (ft_printf_c(HEX[n]));
}

int		ft_printf_xm(uintmax_t n)
{
	if (n >= 16)
		return (ft_printf_xm(n / 16) + ft_printf_xm(n % 16));
	else
		return (ft_printf_c(HEXM[n]));
}

int		ft_printf_octal(uintmax_t n)
{
	if (n >= 8)
		return (ft_printf_octal(n / 8) + ft_printf_x(n % 8));
	else
		return (ft_printf_c(48 + n));
}
