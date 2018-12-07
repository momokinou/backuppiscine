/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_hashtag.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:31:20 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 09:34:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_widthhasht(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagshashtl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagshashtll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagshasht_h(format, ap, i, width);
	else if (format[i] == 'h' && format[i] == 'h')
		all += flagshashthh(format, ap, i, width);
	else
		all += printf_widthhasht2(format, ap, i, width);
	return (all);
}

int		printf_widthhasht2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int		flagshashthexa(const char *format,va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	writewidth(width, ' ');
	ft_putstr("0x");
	if (format[i] == 'x')
		all += ft_printf_x(nbr) + 2;
	return (all);
}

int		flagshashthexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	writewidth(width, ' ');
	ft_putstr("0X");
	if (format[i] == 'X')
		all += ft_printf_xm(nbr) + 2;
	return (all);
}

int		flagshashtoctal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr) - 1;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	writewidth(width, ' ');
	ft_putchar('0');
	if (format[i] == 'o')
		all += ft_printf_octal(nbr) + 1;
	return (all);
}
