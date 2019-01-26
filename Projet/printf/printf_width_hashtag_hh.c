/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_hashtag_hh.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:20:44 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:15:06 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagshashthh_hexa2(const char *format, unsigned char nbr, int i)
{
	int all;

	all = 0;
	if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(nbr) + 2;
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(nbr) + 2;
	}
	return (all);
}

int		flagshashthh_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'x' || format[i] == 'X')
		width = width - hexalength(nbr) - 2;
	writewidth(width, ' ');
	if (width >= 0)
	{
		if (format[i] == 'x')
		{
			ft_putstr("0x");
			all += ft_printf_x(nbr) + 2 + width;
		}
		else if (format[i] == 'X')
		{
			ft_putstr("0X");
			all += ft_printf_xm(nbr) + 2 + width;
		}
	}
	else
		all += flagshashthh_hexa2(format, nbr, i);
	return (all);
}

int		flagshashthh_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'o')
		width = width - octallength(nbr) - 1;
	writewidth(width, ' ');
	if (width >= 0)
	{
		if (format[i] == 'o')
		{
			ft_putchar('0');
			all += ft_printf_octal(nbr) + 1 + width;
		}
	}
	else
	{
		ft_putchar('0');
		all += ft_printf_octal(nbr) + 1;
	}
	return (all);
}
