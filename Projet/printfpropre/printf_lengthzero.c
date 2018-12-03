/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_length.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:24:52 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 12:20:47 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		flagszerol(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int		flagszeroll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int		flagszeroh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int		flagszerohh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}
