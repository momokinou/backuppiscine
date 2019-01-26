/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_length_zero_hasht.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:07:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:29:02 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		zero_hashtl(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	nbr = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hashtll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hasht_h(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hashthh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'x'
				|| format[i + 2] == 'X'))
		all += zero_hashthh_hexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += zero_hashthh_octal(format, ap, i, width);
	return (all);
}
