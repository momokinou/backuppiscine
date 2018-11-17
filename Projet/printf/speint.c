/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   speint.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:31:51 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 11:32:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_speintl(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr_ld(va_arg(ap, long));
			break ;
		}
		else if (format[i] == 'l' && format[i + 1] == 'l' &&
				(format[i + 2] == 'd' || format[i + 2] == 'i'))
		{
			ft_putnbr_ld(va_arg(ap, long long));
			break ;
		}
		break ;
	}
}

void		ft_printf_speinth(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr_hd((short)va_arg(ap, int));
			break ;
		}
		else if (format[i] == 'h' && format[i + 1] == 'u')
		{
			ft_putunbr_hd((short)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
					|| format[i + 2] == 'i'))
		{
			ft_putnbr((signed char)va_arg(ap, int));
			break ;
		}
		ft_printf_speinth2(format, ap, i);
		break ;
	}
}

void		ft_printf_speinth2(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'h' && format[i + 1] == 'o')
		{
			ft_printf_octal((short)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'h' && format[i + 1] == 'x')
		{
			ft_printf_x((short)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'h' && format[i + 1] == 'X')
		{
			ft_printf_xm((short)va_arg(ap, int));
			break ;
		}
		break ;
	}
}

void		ft_printf_speint(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			ft_printf_nbr(va_arg(ap, int));
			break ;
		}
		else if (format[i] == 'u')
		{
			ft_printf_unbr(va_arg(ap, unsigned int));
			break ;
		}
		else if (format[i] == 'l')
		{
			ft_printf_speintl(format, ap, i);
			break ;
		}
		ft_printf_speinth(format, ap, i);
		break ;
	}
}
