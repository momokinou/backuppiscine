/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specifiers_int.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:15:34 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:16:49 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_speint(const char *format, va_list ap, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (ft_printf_unbr(va_arg(ap, unsigned int)));
	return (0);
}

int		ft_printf_speintlh(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_putnbr_ld(va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += ft_putunbr_ld((unsigned long)va_arg(ap, long));
	else if (format[i] =='l' && format[i + 1] == 'o')
		all += ft_printf_octal((unsigned long)va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += ft_printf_x((unsigned long)va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += ft_printf_xm((unsigned long)va_arg(ap, long));
	else
		all += ft_printf_speintll(format, ap, i);
	return (all);
}

int		ft_printf_speintll(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' &&
			(format[i + 2] == 'd' || format[i + 2] == 'i'))
		all += ft_printf_nbr(va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format [i + 2] == 'u')
		all += ft_printf_unbr((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i] == 'o')
		all += ft_printf_octal((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += ft_printf_x((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += ft_printf_xm((unsigned long long)va_arg(ap, long long));
	else
		all += ft_printf_speinth(format, ap, i);
	return (all);
}

int		ft_printf_speinth(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_putnbr_hd((short)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += ft_putunbr_hd((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += ft_printf_octal((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += ft_printf_x((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += ft_printf_xm((unsigned short)va_arg(ap, unsigned int));
	else
		all += ft_printf_speinthh(format, ap, i);
	return (all);
}

int		ft_printf_speinthh(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' &&(format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += ft_printf_nbr((signed char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += ft_printf_unbr((unsigned char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += ft_printf_octal((unsigned char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += ft_printf_x((unsigned char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += ft_printf_xm((unsigned char)va_arg(ap, int));
	return (all);
}
