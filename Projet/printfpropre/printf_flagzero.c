/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flagzero.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:20:26 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:22:43 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_flagszero(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	while (format[i] && format[i] != '%')
	{
		if (ft_isdigit(format[i]))
			i++;
		i++;
	}
	i--;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagszerol(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagszeroll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagszeroh(format, ap, i, width);
	else if (format[i] == 'h' && format[i] == 'h')
		all += flagszerohh(format, ap, i, width);
	else
		all += printf_flagszero2(format, ap, i, width);
	return (all);
}

int		printf_flagszero2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int		negnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	return (nbr);
}

int		flagszerohexa(const char *format, va_list ap, int i, int width)
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
	writewidth(width, '0');
	if (format[i] == 'x')
		all += ft_printf_x(nbr);
	return (all);
}

int		flagszerohexam(const char *format, va_list ap, int i, int width)
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
	writewidth(width, '0');
	if (format[i] == 'X')
		all += ft_printf_xm(nbr);
	return (all);
}
