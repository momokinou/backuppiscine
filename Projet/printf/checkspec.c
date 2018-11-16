/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkspec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:20:53 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:08:32 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		checkspec3(const char *format, va_list ap, int i)
{
	int n;
	int m;

	while (format[i])
	{
		if (format[i] == 'f')
		{
			ft_putnbr((float)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'p')
		{
			ft_putstr("0x10");
			n = va_arg(ap, int);
			m = n;
			ft_printf_p(n);
			break ;
		}
		checkflags(format, ap, i);
		break ;
	}
}

void		checkspec2(const char *format, va_list ap, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] == 'x' || format[i] == 'X' || format[i] == 'o')
		{
			ft_printf_specxo(format, ap, i);
			break ;
		}
		if (format[i] == 'l' || format[i] == 'h')
		{
			ft_printf_speint(format, ap, i);
			break ;
		}
		if (format[i] == 'j' || format[i] == 'z')
		{
			ft_printf_specjz(format, ap, i);
			break ;
		}
		checkspec3(format, ap, i);
		break ;
	}
}

void		checkspec(const char *format, va_list ap, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		if (format[i] == 'c' || format[i] == 's')
		{
			ft_printf_spechar(format, ap, i);
			break ;
		}
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		{
			ft_printf_speint(format, ap, i);
			break ;
		}
		checkspec2(format, ap, i);
		break ;
	}
}

void		checknoopt(const char *format, va_list ap, int i)
{
	if (format[i++] != '%')
		printno_opt(format);
	else
		checkflags(format, ap, i);
}
