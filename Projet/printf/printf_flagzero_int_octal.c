/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flagzero_int_octal.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:22:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:08:15 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagszerooctal(const char *format, va_list ap, int i, int width)
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
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_octal(nbr) + width;
	else
		all += ft_printf_octal(nbr);
	return (all);
}

int		flagszerouint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'u')
		nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_putunbr(nbr) + width;
	else
		all += ft_putunbr(nbr);
	return (all);
}

int		flagszeroint(const char *format, va_list ap, int i, int width)
{
	int			all;
	intmax_t	nbr;

	all = 0;
	nbr = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else if (format[i] == 'i' || format[i] == 'd')
		nbr = va_arg(ap, int);
	if (nbr < 0)
		all += 1;
	width = width - ft_intlen(nbr);
	nbr = negnbr(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}
