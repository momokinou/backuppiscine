/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_minus_int_hexa_octal.c              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:38:59 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:11:18 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagsminushexa(const char *format, va_list ap, int i, int width)
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
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (width >= 0)
		all += ft_printf_x(nbr) + width;
	else
		all += ft_printf_x(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminushexam(const char *format, va_list ap, int i, int width)
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
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (width >= 0)
		all += ft_printf_xm(nbr) + width;
	else
		all += ft_printf_xm(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminusoctal(const char *format, va_list ap, int i, int width)
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
	if (width >= 0)
		all += ft_printf_octal(nbr) + width;
	else
		all += ft_printf_octal(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminusuint(const char *format, va_list ap, int i, int width)
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
	if (width >= 0)
		all += ft_putunbr(nbr) + width;
	else
		all += ft_putunbr(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminusint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

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
	else if (format[i] == 'd' || format[i] == 'i')
		nbr = va_arg(ap, int);
	width = width - ft_intlen(nbr);
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	writewidth(width, ' ');
	return (all);
}
