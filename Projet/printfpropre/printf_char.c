/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:07:00 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:14:03 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_c(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int		ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(null)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int		ft_printf_p(unsigned int n)
{
	if (n >= 16)
		return ((ft_printf_p(n / 16) + ft_printf_p(n % 16)));
	else
		return (ft_printf_c(HEX[n]));
}

int		ft_printf_spechar(const char *format, va_list ap, int i)
{
	if (format[i] == 'c')
		return (ft_printf_c((wchar_t)va_arg(ap, wint_t)));
	else if (format[i] == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	return (0);
}
