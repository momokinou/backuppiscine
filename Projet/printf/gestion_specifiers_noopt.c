/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestion_specifiers_noopt.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 12:05:17 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 12:11:27 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		checkall2(const char *format, va_list ap, int i, int all)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		all += ft_printf_speint(format, ap, i);
	else if (format[i] == 'h' || format[i] == 'l')
		all += ft_printf_speintlh(format, ap, i);
	else if (format[i] == 'o' || format[i] == 'x' || format[i] == 'X')
		all += ft_printf_specxo(format, ap, i);
	else if (format[i] == 'j' || format[i] == 'z')
		all += ft_printf_specjz(format, ap, i);
	return (all);
}

int		checkall(const char *format, va_list ap, int i, int all)
{
	if (format[i] == '%')
	{
		putchar('%');
		i += 2;
		all++;
	}
	if (format[i] == 'c' || format[i] == 's')
		all += ft_printf_spechar(format, ap, i);
	else if (format[i] == 'p')
	{
		ft_putstr("0x10");
		ft_printf_p(va_arg(ap, int));
		all += 11;
	}
	else
		all = checkall2(format, ap, i, all);
	return (all);
}

int		printno_opt(const char *format, va_list ap, int i)
{
	int print;

	print = 0;
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
		print++;
	}
	if (format[i] == '%')
		return (checkflags(format, ap, i + 1, print));
	return (print);
}

int		checknoopt(const char *format, va_list ap, int i, int all)
{
	if (format[i] != '%')
		all += printno_opt(format, ap, i);
	else if (format[i] == '%')
		all += checkflags(format, ap, i + 1, all);
	return (all);
}
