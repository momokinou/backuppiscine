/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_spacezero.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 09:52:03 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:14:05 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	spacezeroprint(int nbr)
{
	if (nbr > 0)
		ft_putchar(' ');
}

int		spacezeroint2(const char *format, va_list ap, int i)
{
	int nbr;

	nbr = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else if (format[i] == 'i' || format[i] == 'd')
		nbr = va_arg(ap, int);
	return (nbr);
}

int		spacezeroint(const char *format, va_list ap, int i, int width)
{
	int			all;
	intmax_t	nbr;

	all = 0;
	nbr = spacezeroint2(format, ap, i);
	if (nbr < 0)
		all += 1;
	width = width - ft_intlen(nbr);
	spacezeroprint(nbr);
	nbr = negnbr(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}

int		printf_space_zero(const char *format, va_list ap, int i)
{
	int width;
	int all;
	int j;

	all = 0;
	j = i;
	width = ft_atoi(format, j);
	while (format[j] && ft_isdigit(format[j]))
		j++;
	if (format[j] == 'd' || format[j] == 'i')
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'l' && (format[j + 1] == 'd' || format[j + 1] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'l' && format[j + 1] == 'l' && (format[j + 2] == 'd'
				|| format[j + 2] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'h' && (format[j + 1] == 'd' || format[j + 1] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'h' && format[j + 1] == 'h' && (format[j + 2] == 'd'
				|| format[j + 2] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else
		all += ft_printf_flagszero(format, ap, i);
	return (all);
}
