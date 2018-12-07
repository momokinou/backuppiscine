/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_hashtag_length.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:33:09 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 12:24:27 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagshashtl(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int		flagshashtll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int		flagshasht_h(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagshashthexam(format, ap, i, width);
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
	if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(nbr);
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(nbr);
	}
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
	if (format[i] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal(nbr);
	}
	return (all);
}

int		flagshashthh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'x'
				|| format[i + 2] == 'X'))
		all += flagshashthh_hexa(format, ap, i, width);
	return (all);
}
