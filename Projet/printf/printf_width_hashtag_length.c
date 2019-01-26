/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_hashtag_length.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:33:09 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 10:25:06 by qmoricea    ###    #+. /#+    ###.fr     */
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
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagshashthh_octal(format, ap, i, width);
	return (all);
}
