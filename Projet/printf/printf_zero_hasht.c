/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_zero_hasht.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:05:03 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:15:51 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		printf_zero_hasht(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += zero_hashtl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += zero_hashtll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += zero_hasht_h(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		all += zero_hashthh(format, ap, i, width);
	else
		all += printf_zero_hasht2(format, ap, i, width);
	return (all);
}

int		printf_zero_hasht2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hasht_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	ft_putstr("0x");
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_x(nbr) + 2 + width;
	else
		all += ft_printf_x(nbr) + 2;
	return (all);
}

int		zero_hasht_hexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	if (format[i] =='l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	ft_putstr("0X");
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_xm(nbr) + 2 + width;
	else
		all += ft_printf_xm(nbr) + 2;
	return (all);
}

int		zero_hasht_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr) - 1;
	ft_putchar('0');
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_octal(nbr) + 1 + width;
	else
		all += ft_printf_octal(nbr) + 1;
	return (all);
}

