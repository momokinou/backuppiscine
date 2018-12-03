/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_minus_length.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:40:51 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 12:23:29 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagsminusl(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int		flagsminusll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int		flagsminush(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int		flagsminushh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}
