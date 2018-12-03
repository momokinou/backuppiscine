/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestion_flags.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 11:54:27 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 13:16:02 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_flagsplus(const char *format, va_list ap, int i)
{
	int n;

	if (format[i + 1] == 'd' || format[i + 1] == 'i')
	{
		n  = va_arg(ap, int);
		if (n > 0)
			ft_putchar('+');
		ft_printf_plusnbr(n);
		return (ft_intlen(n));
	}
	return (0);
}

int		ft_printf_flagsspace(const char *format, va_list ap, int i)
{
	int count;

	count = 0;
	while (format[i] == ' ')
	{
		write(1, " ", 1);
		i++;
		count++;
	}
	count = checkall(format, ap, i, count);
	return (count);
}

int		checkflags(const char *format, va_list ap, int i, int all)
{
	while (format[i])
	{
		if (format[i] == ' ' && format[i + 1] <= '9' && format[i + 1] >= '0')
		{
			all += ft_printf_widthspace(format, ap, i);
			i++;
		}
		else if (format[i] == '#' && format[i + 1] <= '9' && format[i + 1] >= '0')
		{
			all += ft_printf_widthhasht(format, ap, i);
			i++;
		}
		else if (format[i] == '-' && format[i +1] <= '9' && format[i + 1] >= '0')
		{
			all +=ft_printf_widthminus(format, ap, i);
			i++;
		}
		else
			all = checkflags2(format, ap, i, all);
		i = counti(format, i);
		if (i == 0)
			return (all);
	}
	return (all);
}

int		checkflags2(const char *format, va_list ap, int i, int all)
{
	if (format[i] == '-')
	{
		i++;
		all = checkall(format, ap, i, all);
	}
	else if (format[i] == '+')
	{
		all += ft_printf_flagsplus(format, ap, i);
		i++;
	}
	else if (format[i] == ' ')
	{
		all += ft_printf_flagsspace(format, ap, i);
		i++;
	}
	else if (format[i] == '#')
	{
		all += ft_printf_flagshashtag(format, ap, i);
		i++;
	}
	else
		all = checkflags3(format, ap, i, all);
	return (all);
}

int		checkflags3(const char *format, va_list ap, int i, int all)
{
	if (format[i] == '0')
	{
		all += ft_printf_flagszero(format, ap, i);
		i++;
	}
	else if (format[i] == '.')
	{
		all += ft_printf_flagszero(format, ap, i);
		i++;
	}
	else if (format[i] <= '9' && format[i] >= '0')
	{
		all += ft_printf_widthspace(format, ap, i);
		i++;
	}
	else
		all = checkall(format, ap, i, all);
	return (all);
}
