/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestwidth.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 08:05:24 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 08:58:03 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		writewidth(int width, char type)
{
	while (width > 0)
	{
		ft_putchar(type);
		width--;
	}
}

void		checkwidthspec(const char *format, int i, intmax_t nbr)
{
	if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(nbr);
	if (format[i] == 'u')
		ft_putunbr(nbr);
	if (format[i] == 'o')
		ft_printf_octal(nbr);
	if (format[i] == 'x')
		ft_printf_x(nbr);
	if (format[i] == 'X')
		ft_printf_xm(nbr);
}
