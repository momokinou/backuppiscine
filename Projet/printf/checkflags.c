/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 07:46:27 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 10:17:00 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_printf_plusnbr(intmax_t n)
{
	uintmax_t x;

	x = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		x = -n;
	}
	if (x >= 10)
	{
		ft_printf_plusnbr(x / 10);
		ft_printf_plusnbr(x % 10);
	}
	else
		ft_putchar_fd(x + '0', 1);
}

void		ft_printf_flagsminus(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		i++;
		checkspec(format, ap, i);
		break ;
	}
}

void		ft_printf_flagsplus(const char *format, va_list ap, int i)
{
	int n;

	while (format[i])
	{
		if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			n = va_arg(ap, int);
			if (n > 0)
				ft_putchar('+');
			ft_printf_plusnbr(n);
			break ;
		}
		break ;
	}
}

void		ft_printf_flagsspace(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == ' ')
		{
			write(1, " ", 1);
			i++;
			checkspec(format, ap, i);
			break ;
		}
	}
}

void		ft_printf_flagshashtag(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i + 1] == 'o')
		{
			write(1, "0", 1);
			ft_printf_octal((unsigned int)va_arg(ap, int));
			break ;
		}
		if (format[i + 1] == 'x')
		{
			write(1, "0x", 2);
			ft_printf_x(va_arg(ap, unsigned int));
			break ;
		}
		if (format[i + 1] == 'X')
		{
			write(1, "0X", 2);
			ft_printf_xm(va_arg(ap, unsigned int));
			break ;
		}
		break ;
	}
}

void		ft_printf_flagszero(const char *format, va_list ap, int i)
{
	char *tmp;
	int n;

	n = 0;
	tmp = NULL;
	while (format[i])
	{
		while (format[i] <= '9' && format[i] > '0')
		{
			tmp[n] = format[i];
			i++;
			n++;
		}
		break ;
	}
	if (format[i] == 'd' || format[i] == 'i' || format[i] =='x'
			|| format[i] == 'X' || format[i] == 'o')
	{
		n = atoi(tmp);
		n = n - ft_intlen(va_arg(ap, int));
	}
	while (n != 0 && n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

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