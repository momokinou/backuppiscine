/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specjz.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:30:16 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:30:47 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_specjz(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'j' && (format[i] == 'd' || format[i] == 'i'))
		{
			ft_putnbr(va_arg(ap, intmax_t));
			break ;
		}
		else if (format[i] == 'j' && (format[i] == 'u' || format[i] == 'o'
					|| format[i] == 'x' || format[i] == 'X'))
		{
			ft_putunbr((uintmax_t)va_arg(ap, intmax_t));
			break ;
		}
		if (format[i] == 'z')
		{
			ft_putnbr(va_arg(ap, size_t));
			break ;
		}
	}
}
