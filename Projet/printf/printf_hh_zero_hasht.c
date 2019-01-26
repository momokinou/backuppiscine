/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_hh_zero_hasht.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:11:12 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:28:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		zero_hashthh_hexa2(const char *format, unsigned char nbr, int i)
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

int		print_zero_hh_hexa(int width, unsigned char nbr)
{
	int all;

	all = 0;
	ft_putstr("0x");
	writewidth(width, '0');
	all += ft_printf_x(nbr) + 2 + width;
	return (all);
}

int		zero_hashthh_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'x' || format[i] == 'X')
		width = width - hexalength(nbr) - 2;
	if (width >= 0)
	{
		if (format[i] == 'x')
			all += print_zero_hh_hexa(width, nbr);
		else if (format[i] == 'X')
		{
			ft_putstr("0X");
			writewidth(width, '0');
			all += ft_printf_xm(nbr) + 2 + width;
		}
	}
	else
		all += zero_hashthh_hexa2(format, nbr, i);
	return (all);
}

int		zero_hashthh_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'o')
		width = width - octallength(nbr) - 1;
	if (width >= 0)
	{
		if (format[i] == 'o')
		{
			ft_putchar('0');
			writewidth(width, '0');
			all += ft_printf_octal(nbr) + 1 + width;
		}
	}
	else
	{
		ft_putchar('0');
		writewidth(width, '0');
		all += ft_printf_octal(nbr) + 1;
	}
	return (all);
}
