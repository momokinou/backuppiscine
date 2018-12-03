/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_minus.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:38:07 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 11:38:39 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_widthminus(const char *format, va_list ap, int i)
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
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagsminusl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagsminusll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagsminush(format, ap, i, width);
	else if (format[i] == 'h' && format[i] == 'h')
		all += flagsminushh(format, ap, i, width);
	else
		all += printf_widthminus2(format, ap, i, width);
	return (all);
}

int		printf_widthminus2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}
