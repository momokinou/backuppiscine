/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printflagszero.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 08:30:18 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 08:34:03 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_flagszero(const char *format, va_list ap, int i)
{
	int n;
	int m;
	int modif;

	n = 0;
	i++;
	while (format[i])
	{
		while (format[i] <= '9' && format[i] > '0')
		{
			i++;
		}
		i++;
	}
	i--;
	if (format[i] == 'd' || format[i] == 'i')
	{
		n = ft_atoi(format);
		m = va_arg(ap, int);
		n = n - ft_intlen(m);
		if (m < 0)
			ft_putchar('-');
		writewidth(n, '0');
		checkwidthspec(format, i, m);
	}
	if (format[i] == 'u')
	{
		n = ft_atoi(format);
		m = va_arg(ap, unsigned int);
		n = n - ft_intlen(m);
		writewidth(n, '0');
		checkwidthspec(format, i, m);
	}
	if (format[i] == 'o')
	{
		n = ft_atoi(format);
		modif = (unsigned int)va_arg(ap, int);
		m = modif;
		while (m >= 8)
		{
			m = m / 8;
			n--;
		}
		n--;
		writewidth(n, '0');
		checkwidthspec(format, i, modif);
	}
	if (format[i] == 'x' || format[i] == 'X')
	{
		n = ft_atoi(format);
		modif = (va_arg(ap, unsigned int));
		m = modif;
		while (m >= 16)
		{
			m = m / 16;
			n--;
		}
		n--;
		writewidth(n, '0');
		checkwidthspec(format, i, modif);
	}
}
