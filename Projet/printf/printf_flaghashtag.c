/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flaghashtag.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:43:44 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:00:34 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_flagshashtag(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	i++;
	if (format[i] == 'o')
	{
		write(1, "0", 1);
		all += ft_printf_octal(va_arg(ap, unsigned int)) + 1;
	}
	else if (format[i] == 'h' && format[i] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned short)va_arg(ap, int)) + 1;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned char)va_arg(ap, int)) + 1;
	}
	else
		all += ft_printf_flagshashtag2(format, ap, i);
	return (all);
}

int		ft_printf_flagshashtag2(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal(va_arg(ap, unsigned long));
	}
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal(va_arg(ap, unsigned long long)) + 1;
	}
	else if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(va_arg(ap, unsigned int)) + 2;
	}
	else
		all += ft_printf_flagshashtag3(format, ap, i);
	return (all);
}

int		ft_printf_flagshashtag3(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned short)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned char)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(va_arg(ap, long)) + 2;
	}
	else
		all += ft_printf_flagshashtag4(format, ap, i);
	return (all);
}

int		ft_printf_flagshashtag4(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(va_arg(ap, unsigned long long)) + 2;
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(va_arg(ap, unsigned int)) + 2;
	}
	else if (format[i] == 'h' && format[i + 1] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned short)va_arg(ap, int)) + 2;
	}
	else
		all += ft_printf_flagshashtag5(format, ap, i);
	return (all);
}

int		ft_printf_flagshashtag5(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned char)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(va_arg(ap, unsigned long long)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(va_arg(ap, unsigned long long)) + 2;
	}
	return (all);
}
