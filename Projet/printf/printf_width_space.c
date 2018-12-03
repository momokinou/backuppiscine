/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width_space.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:34:36 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 11:35:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_widthspace(const char *format, va_list ap, int i)
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
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagsspacel(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagsspacell(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagsspaceh(format, ap, i, width);
	else if (format[i] == 'h' && format[i] == 'h')
		all += flagsspacehh(format, ap, i, width);
	else
		all += printf_widthspace2(format, ap, i, width);
	return (all);
}

int		printf_widthspace2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}
