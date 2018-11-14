/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specxo.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:31:04 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:31:27 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_specxo(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'x')
		{
			ft_printf_x(va_arg(ap, unsigned int));
			break ;
		}
		else if (format[i] == 'X')
		{
			ft_printf_xm(va_arg(ap, unsigned int));
			break ;
		}
		else if (format[i] == 'o')
		{
			ft_printf_octal((unsigned int)va_arg(ap, int));
			break ;
		}
	}
}
