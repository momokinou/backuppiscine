/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specifiersxo_lengthjz.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:17:19 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 09:47:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_specxo(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'x')
		all += ft_printf_x(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		all += ft_printf_xm(va_arg(ap, unsigned int));
	else if (format[i] == 'o')
		all += ft_printf_octal((unsigned int)va_arg(ap, int));
	return (all);
}

int		ft_printf_specz(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'z' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_printf_nbr(va_arg(ap, size_t));
	else if (format[i] == 'z' && format[i + 1] == 'u')
		all += ft_printf_unbr(va_arg(ap, size_t));
	else if (format[i] == 'z' && format[i + 1] == 'o')
		all += ft_printf_octal(va_arg(ap, size_t));
	else if (format[i] == 'z' && format[i + 1] == 'x')
		all += ft_printf_x(va_arg(ap, size_t));
	else if (format[i] == 'z' && format[i + 1] == 'X')
		all += ft_printf_xm(va_arg(ap, size_t));
	return (all);
}

int		ft_printf_specjz(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'j' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_printf_nbr(va_arg(ap, uintmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'u')
		all += ft_printf_unbr(va_arg(ap, uintmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'o')
		all += ft_printf_octal(va_arg(ap, uintmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'x')
		all += ft_printf_x(va_arg(ap, uintmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'X')
		all += ft_printf_xm(va_arg(ap, uintmax_t));
	else if (format[i] == 'z')
		all += ft_printf_specz(format, ap, i);
	return (all);
}
