/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_minus_int_hexa_octal.c              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:38:59 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 11:40:39 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagsminushexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (format[i] == 'x')
		all += ft_printf_x(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminushexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (format[i] == 'X')
		all += ft_printf_xm(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminusoctal(const char *format, va_list ap, int i, int width)
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
	if (format[i] == 'o')
		all += ft_printf_octal(nbr);
	writewidth(width, ' ');
	return (all);
}

int		flagsminusuint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
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
	writewidth(width, ' ');
	return (all);
}

int		flagsminusint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	nbr = va_arg(ap, int);
	width = width - ft_intlen(nbr);
	if (nbr < 0)
		all += 1;
	nbr = negnbr(nbr);
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
	writewidth(width, ' ');
	return (all);
}
