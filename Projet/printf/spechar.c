/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   spechar.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:28:56 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:29:46 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_spechar(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		else if (format[i] == 'c')
		{
			ft_printf_c((wchar_t)va_arg(ap, wint_t));
			break ;
		}
		else if (format[i] == 's')
		{
			ft_printf_str(va_arg(ap, char *));
			break ;
		}
	}
}
