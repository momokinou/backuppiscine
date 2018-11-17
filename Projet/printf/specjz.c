/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specjz.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:30:16 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 10:59:22 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_specjz(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'j' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr(va_arg(ap, intmax_t));
			break ;
		}
		else if (format[i] == 'j' && format[i + 1] == 'u')
		{
			ft_putunbr((uintmax_t)va_arg(ap, intmax_t));
			break ;
		}
		else if (format[i] == 'j' && format[i + 1] == 'o')
		{
			ft_printf_octal((uintmax_t)va_arg(ap, int));
			break ;
		}
		ft_printf_specjz2(format, ap, i);
		break ;
	}
}

void		ft_printf_specjz2(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'j' && format[i + 1] == 'x')
		{
			ft_printf_x((uintmax_t)va_arg(ap, int));
			break ;
		}
		else if (format[i] == 'j' && format[i + 1] == 'X')
		{
			ft_printf_xm((uintmax_t)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'z')
		{
			ft_putnbr(va_arg(ap, size_t));
			break ;
		}
	}
}
