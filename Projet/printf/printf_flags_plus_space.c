/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_flags_plus_space.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 11:00:54 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:01:23 by qmoricea    ###    #+. /#+    ###.fr     */
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
