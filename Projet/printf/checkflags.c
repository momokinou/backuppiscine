/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 07:46:27 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:03:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		checkflags(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '-')
		{
			ft_printf_flagsminus(format, ap, i);
			break ;
		}
		if (format[i] == '+')
		{
			ft_printf_flagsplus(format, ap, i);
			break ;
		}
		if (format[i] == ' ')
		{
			ft_printf_flagsspace(format, ap, i);
			break ;
		}
		checkflags2(format, ap, i);
		break ;
	}
}

void		checkflags2(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '#')
		{
			ft_printf_flagshashtag(format, ap, i);
			break ;
		}
		if (format[i] == '0')
		{
			ft_printf_flagszero(format, ap, i);
			break ;
		}
		checkspec(format, ap, i);
		break ;
	}
}
