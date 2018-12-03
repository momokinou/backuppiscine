/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flagzero_int_octal.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:22:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:24:11 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagszerooctal(const char *format, va_list ap, int i,int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	writewidth(width, '0');
	if (format[i] == 'o')
		all += ft_printf_octal(nbr);
	return (all);
}

int		flagszerouint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
	writewidth(width, '0');
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (width > 0)
		all += ft_putunbr(nbr);
	else
		all += ft_putunbr(nbr);
	return (all);
}

int		flagszeroint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	nbr = va_arg(ap, int);
	width = width - ft_intlen(nbr);
	if (nbr < 0)
		all += 1;
	nbr = negnbr(nbr);
	writewidth(width, '0');
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)nbr;
	if (width > 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}
