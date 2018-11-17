/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_width.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/17 12:34:29 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 13:13:09 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_width(const char *format, va_list ap, int i)
{
	int n;
	int m;
	int modif;
	int minus;
	char *str;

	n = 0;
	minus = 0;
	if (format[i - 1] == '-')
		minus = 1;
	if (format[i] == '#')
		minus = -1;
	if (format[i] == ' ')
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
		n = widthatoi(format);
		m = va_arg(ap, int);
		n = n - ft_intlen(m);
		if (minus == 1)
		{
			checkwidthspec(format, i, m);
			writewidth(n , ' ');
		}
		else
		{
			writewidth(n, ' ');
			checkwidthspec(format, i, m);
		}
	}
	if (format[i] == 'u')
	{
		n = widthatoi(format);
		m = va_arg(ap, unsigned int);
		n = n - ft_intlen(m);
		writewidth(n, ' ');
		checkwidthspec(format, i, m);
	}
	if (format[i] == 'o')
	{
		n = widthatoi(format);
		modif = (unsigned int)va_arg(ap, int);
		m = modif;
		while (m >= 8)
		{
			m = m / 8;
			n--;
		}
		n--;
		if (minus == -1)
		{
			n--;
			writewidth(n, ' ');
			write(1, "0", 1);
		}
		else
			writewidth(n, ' ');
		checkwidthspec(format, i, modif);
	}
	if (format[i] == 'x' || format[i] == 'X')
	{
		n = widthatoi(format);
		modif = (va_arg(ap, unsigned int));
		m = modif;
		while (m >= 16)
		{
			m = m / 16;
			n--;
		}
		n--;
		if (minus == -1)
		{
			n--;
			writewidth(n, ' ');
			if (format[i] == 'x')
				write(1, "0x", 2);
			if (format[i] == 'X')
				write(1, "0X", 2);
		}
		else
			writewidth(n, ' ');
		checkwidthspec(format, i, modif);
	}
	if (format[i] == 'c')
	{
		n = widthatoi(format);
		n = n - 1;
		writewidth(n, ' ');
		ft_printf_c((wchar_t)va_arg(ap, wint_t));
	}
	if (format[i] == 's')
	{
		n = widthatoi(format);
		str = va_arg(ap, char *);
		m = ft_strlen(str);
		n = n - m;
		writewidth(n, ' ');
		checkwidthspec2(format, i, str);
	}
	if (format[i] == 'p')
	{
		n = widthatoi(format);
		n = n - 11;
		writewidth(n, ' ');
		checkspec3(format, ap, i);
	}
}
