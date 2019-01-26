/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printftest.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 10:31:29 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:34:36 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>
#define HEX "0123456789abcdef"
#define HEXM "0123456789ABCDEF"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void		ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void		ft_putnbr_fd(intmax_t n, int fd)
{
	uintmax_t x;

	x = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x = -n;
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}

void		ft_putnbr(intmax_t n)
{
	ft_putnbr_fd(n, 1);
}

int			ft_putsignedchar(signed char n)
{
	signed char x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -n;
	}
	if (x >= 10)
	{
		ft_putsignedchar(x / 10);
		ft_putsignedchar(x % 10);
	}
	else
		ft_putchar(x + '0');
	return (ft_intlen(n));
}

int			ft_putunsignedchar(unsigned char n)
{
	unsigned char x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -n;
	}
	if (x >= 10)
	{
		ft_putunsignedchar(x / 10);
		ft_putunsignedchar(x % 10);
	}
	else
		ft_putchar(x + '0');
	return (ft_intlen(n));
}

int			ft_putunbr_fd(intmax_t n, int fd)
{
	uintmax_t x;
	uintmax_t negret;

	x = n;
	negret = n;
	if (n < 0)
	{
		x = 4294967296 + n;
		negret = 4294967296 + n;
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
	return (ft_intlenc(negret, 0));
}

int			ft_putunbr(intmax_t n)
{
	return (ft_putunbr_fd(n, 1));

}

int			ft_intlenc(unsigned int n, int i)
{
	if (n >= 10)
		return (ft_intlenc(n / 10, i + 1));
	else
		return (i + 1);
	return (0);
}

int			ft_intlen(int n)
{
	int				len;
	unsigned int	i;

	if (n < 0)
		i = n * -1;
	else
		i = n;
	len = ft_intlenc(i, 0);
	if (n < 0)
		len = len + 1;
	else
		len = len + 0;
	return (len);
}

int			ft_putnbr_ld(long n)
{
	int stock;

	stock = n;
	if (n == -9223372036854775807)
		ft_putstr("-9223372036854775807");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr_ld(n / 10);
		ft_putnbr_ld(n % 10);
	}
	else
		ft_putchar('0' + n);
	return (ft_intlen(stock));
}

int			ft_putunbr_ld(long long n)
{
	int negret;

	negret = n;
	if (n == -9223372036854775807)
		ft_putstr("9223372036854775809");
	else if (n < 0)
		n = 9223372036854775807 + n;
	else if (n >= 10)
	{
		ft_putnbr_ld(n / 10);
		ft_putnbr_ld(n % 10);
	}
	else
		ft_putchar('0' + n);
	if (negret < 0)
		return (19);
	return (ft_intlen(negret));
}

int			ft_putnbr_hd(short n)
{
	int stock;

	stock = n;
	if (n == -32767)
		ft_putstr("-32767");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr_hd(n / 10);
		ft_putnbr_hd(n % 10);
	}
	else
		ft_putchar('0' + n);
	return (ft_intlen(stock));
}

int			ft_putunbr_hd(short n)
{
	int stock;
	int x;

	stock = n;
	x = n;
	if (n == -32767)
		ft_putstr("-32767");
	else if (n < 0)
	{
		x = 65536 + n;
		stock = 65536 + n;
	}
	if (x >= 10)
	{
		ft_putunbr_hd(x / 10);
		ft_putunbr_hd(x % 10);
	}
	else
		ft_putnbr(x);
	return (ft_intlen(stock));
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int			ft_atoi(const char *format, int i)
{
	int n;
	int isneg;

	isneg = 0;
	n = 0;
	while ((format[i] >= 9 && format[i] <= 13) || format[i] == 32)
		i++;
	while (format[i] == '+' || format[i] == '%' || format[i] == '0'
			|| format[i] == '.' || format[i] == '-' || format[i] == '#')
		i++;
	if (format[i] == '-')
	{
		isneg = 1;
		i++;
	}
	while (format[i] && format[i] >= '0' && format[i] <= '9')
	{
		n = n * 10 + (format[i++] - '0');
	}
	if (isneg)
		return (-n);
	else
		return (n);
}

/*----------------------------------------------------------------------------*/

int			ft_printf_c(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int			ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(null)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int			ft_printf_nbr(int nbr)
{
	ft_putnbr(nbr);
	return (ft_intlen(nbr));
}

int			ft_printf_unbr(int nbr)
{
	return (ft_putunbr(nbr));
}

int			is_valid(char c)
{
	return (c != 'c' && c != 's' && c !='p' && c != 'd' && c != 'i' && c != 'u'
			&& c != 'o' && c != 'x' && c != 'X');
}

int			counti(const char *format, int i)
{
	while (format[i] && is_valid(format[i]) && format[i] != '%')
		ft_putchar(format[i++]);
	i++;
	while (format[i] && format[i] != '%')
		ft_putchar(format[i++]);
	if (format[i] == '%')
		return (i + 1);
	else if (!format[i])
		return (0);
	return (0);
}

int			countall(const char *format, int i, int all)
{
	if (format[i] != '%')
	{
		while (format[i] && is_valid(format[i]))
			i++;
		i++;
	}
	else
	{
		ft_putchar(format[i++]);
		all++;
	}
	while (format[i] && format[i] != '%')
	{
		i++;
		all++;
	}
	return (all);
}

int			ft_printf_p(uintmax_t n)
{
	if (n >= 16)
		return ((ft_printf_p(n / 16) + ft_printf_p(n % 16)));
	else
		return (ft_printf_c(HEX[n]));
}

int			ft_printf_x(uintmax_t n)
{
	if (n >= 16)
		return (ft_printf_x(n / 16) + ft_printf_x(n % 16));
	else
		return (ft_printf_c(HEX[n]));
}

int			ft_printf_xm(uintmax_t n)
{
	if (n >= 16)
		return (ft_printf_xm(n / 16) + ft_printf_xm(n % 16));
	else
		return (ft_printf_c(HEXM[n]));
}

int			ft_printf_octal(uintmax_t n)
{
	if (n >= 8)
		return (ft_printf_octal(n / 8) + ft_printf_x(n % 8));
	else
		return (ft_printf_c(48 + n));
}

int			ft_printf_spechar(const char *format, va_list ap, int i)
{
	if (format[i] == 'c')
		return (ft_printf_c((wchar_t)va_arg(ap, wint_t)));
	else if (format[i] == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	return (0);
}

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

int			ft_printf_speint(const char *format, va_list ap, int i)
{
	if (format[i] == 'd' || format[i] == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (ft_printf_unbr(va_arg(ap, unsigned int)));
	return (0);
}

int			ft_printf_speintlh(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_putnbr_ld(va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += ft_putunbr_ld((unsigned long)va_arg(ap, long));
	else if (format[i] =='l' && format[i + 1] == 'o')
		all += ft_printf_octal((unsigned long)va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += ft_printf_x((unsigned long)va_arg(ap, long));
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += ft_printf_xm((unsigned long)va_arg(ap, long));
	else
		all += ft_printf_speintll(format, ap, i);
	return (all);
}

int			ft_printf_speintll(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' &&
			(format[i + 2] == 'd' || format[i + 2] == 'i'))
		all += ft_printf_nbr(va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format [i + 2] == 'u')
		all += ft_printf_unbr((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i] == 'o')
		all += ft_printf_octal((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += ft_printf_x((unsigned long long)va_arg(ap, long long));
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += ft_printf_xm((unsigned long long)va_arg(ap, long long));
	else
		all += ft_printf_speinth(format, ap, i);
	return (all);
}

int			ft_printf_speinth(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_putnbr_hd((short)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += ft_putunbr_hd((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += ft_printf_octal((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += ft_printf_x((unsigned short)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += ft_printf_xm((unsigned short)va_arg(ap, unsigned int));
	else
		all += ft_printf_speinthh(format, ap, i);
	return (all);
}

int			ft_printf_speinthh(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' &&(format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += ft_putsignedchar((signed char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += ft_putunsignedchar((unsigned char)va_arg(ap, unsigned int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += ft_printf_octal((unsigned char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += ft_printf_x((unsigned char)va_arg(ap, int));
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += ft_printf_xm((unsigned char)va_arg(ap, int));
	return (all);
}

int			ft_printf_specxo(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'x')
		all += ft_printf_x(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		all += ft_printf_xm(va_arg(ap, unsigned int));
	else if (format[i] == 'o')
		all += ft_printf_octal((unsigned int)va_arg(ap, int));
	return (all);
}

int			ft_printf_specz(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'z' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_printf_nbr((size_t)va_arg(ap, intmax_t));
	else if (format[i] == 'z' && format[i + 1] == 'u')
		all += ft_printf_unbr((size_t)va_arg(ap, uintmax_t));
	else if (format[i] == 'z' && format[i + 1] == 'o')
		all += ft_printf_octal((size_t)va_arg(ap, intmax_t));
	else if (format[i] == 'z' && format[i + 1] == 'x')
		all += ft_printf_x((size_t)va_arg(ap, intmax_t));
	else if (format[i] == 'z' && format[i + 1] == 'X')
		all += ft_printf_xm((size_t)va_arg(ap, intmax_t));
	return (all);
}

int			ft_printf_specjz(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'j' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += ft_printf_nbr(va_arg(ap, intmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'u')
		all += ft_printf_unbr((uintmax_t)va_arg(ap, intmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'o')
		all += ft_printf_octal((uintmax_t)va_arg(ap, intmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'x')
		all += ft_printf_x((uintmax_t)va_arg(ap, intmax_t));
	else if (format[i] == 'j' && format[i + 1] == 'X')
		all += ft_printf_xm((uintmax_t)va_arg(ap, intmax_t));
	else if (format[i] == 'z')
		all += ft_printf_specz(format, ap, i);
	return (all);
}

/*---------------------------Gestion Width------------------------------------*/

void		writewidth(int width, char type)
{
	while (width > 0)
	{
		ft_putchar(type);
		width--;
	}
}

/*----------------------------------------------------------------------------*/

int		spacezeroint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else if (format[i] == 'i' || format[i] == 'd')
		nbr = va_arg(ap, int);
	if (nbr < 0)
		all += 1;
	width = width - ft_intlen(nbr);
	if (nbr > 0)
		ft_putchar(' ');
	nbr = negnbr(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}


int		printf_space_zero(const char *format, va_list ap, int i)
{
	int width;
	int all;
	int j;

	all = 0;
	j = i;
	width = ft_atoi(format, j);
	while (format[j] && ft_isdigit(format[j]))
		j++;
	if (format[j] == 'd' || format[j] == 'i')
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'l' && (format[j + 1] == 'd' || format[j + 1] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'l' && format[j + 1] == 'l' && (format[j + 2] == 'd'
				|| format[j + 2] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'h' && (format[j + 1] == 'd' || format[j + 1] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else if (format[j] == 'h' && format[j + 1] == 'h' && (format[j + 2] == 'd'
				|| format[j + 2] == 'i'))
		all += spacezeroint(format, ap, j, width);
	else
		all += ft_printf_flagszero(format, ap, i);
	return (all);
}

int			ft_printf_flagszero(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagszerol(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagszeroll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagszeroh(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		all += flagszerohh(format, ap, i, width);
	else
		all += printf_flagszero2(format, ap, i, width);
	return (all);
}

int			printf_flagszero2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int			octallength(int nbr)
{
	int len;

	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len = 10;
	}
	else while (nbr >= 8)
	{
		nbr = nbr / 8;
		len++;
	}
	len++;
	return (len);
}

int			hexalength(int nbr)
{
	int len;

	len = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		len++;
	}
	len++;
	return (len);
}

int			negnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	return (nbr);
}

int			flagszerohexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all+= ft_printf_x(nbr) + width;
	else
		all += ft_printf_x(nbr);
	return (all);
}

int			flagszerohexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_xm(nbr) + width;
	else
		all += ft_printf_xm(nbr);
	return (all);
}

int			flagszerooctal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_octal(nbr) + width;
	else
		all += ft_printf_octal(nbr);
	return (all);
}

int			flagszerouint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'u')
		nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_putunbr(nbr) + width;
	else
		all += ft_putunbr(nbr);
	return (all);
}

int			flagszeroint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else if (format[i] == 'i' || format[i] == 'd')
		nbr = va_arg(ap, int);
	if (nbr < 0)
		all += 1;
	width = width - ft_intlen(nbr);
	nbr = negnbr(nbr);
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}

int			flagszerol(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int			flagszeroll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int			flagszeroh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

int			flagszerohh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagszerooctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += flagszerohexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += flagszerohexam(format, ap, i, width);
	return (all);
}

/*-----------------------PRINTF WIDTH ZERO HASHT------------------------------*/

int		printf_zero_hasht(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += zero_hashtl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += zero_hashtll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += zero_hasht_h(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		all += zero_hashthh(format, ap, i, width);
	else
		all += printf_zero_hasht2(format, ap, i, width);
	return (all);
}

int		printf_zero_hasht2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hasht_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	ft_putstr("0x");
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_x(nbr) + 2 + width;
	else
		all += ft_printf_x(nbr) + 2;
	return (all);
}

int		zero_hasht_hexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	ft_putstr("0X");
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_xm(nbr) + 2 + width;
	else
		all += ft_printf_xm(nbr) + 2;
	return (all);
}

int		zero_hasht_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr) - 1;
	ft_putchar('0');
	writewidth(width, '0');
	if (width >= 0)
		all += ft_printf_octal(nbr) + 1 + width;
	else
		all += ft_printf_octal(nbr) + 1;
	return (all);
}

int		zero_hashtl(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hashtll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hasht_h(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += zero_hasht_octal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += zero_hasht_hexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += zero_hasht_hexam(format, ap, i, width);
	return (all);
}

int		zero_hashthh_hexa2(const char *format, unsigned char nbr, int i)
{
	int all;

	all = 0;
	if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(nbr) + 2;
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(nbr) + 2;
	}
	return (all);
}

int		zero_hashthh_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'x' || format[i] == 'X')
		width = width - hexalength(nbr) - 2;
	if (width >= 0)
	{
		if (format[i] == 'x')
		{
			ft_putstr("0x");
			writewidth(width, '0');
			all += ft_printf_x(nbr) + 2 + width;
		}
		else if (format[i] == 'X')
		{
			ft_putstr("0X");
			writewidth(width, '0');
			all += ft_printf_xm(nbr) + 2 + width;
		}
	}
	else
		all += zero_hashthh_hexa2(format, nbr, i);
	return (all);
}

int		zero_hashthh_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap,	 int);
	if (format[i] == 'o')
		width = width - octallength(nbr) - 1;
	if (width >= 0)
	{
		if (format[i] == 'o')
		{
			ft_putchar('0');
			writewidth(width, '0');
			all += ft_printf_octal(nbr) + 1 + width;
		}
	}
	else
	{
		ft_putchar('0');
		writewidth(width, '0');
		all += ft_printf_octal(nbr) + 1;
	}
	return (all);
}

int			zero_hashthh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagszeroint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagszerouint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'x'
				|| format[i + 2] == 'X'))
		all += zero_hashthh_hexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += zero_hashthh_octal(format, ap, i, width);
	return (all);
}

/*--------------------------PRINTF WIDTH HASHT--------------------------------*/

int			ft_printf_widthhasht(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagshashtl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagshashtll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagshasht_h(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		all += flagshashthh(format, ap, i, width);
	else
		all += printf_widthhasht2(format, ap, i, width);
	return (all);
}

int			printf_widthhasht2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int			flagshashthexa(const char *format,va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	writewidth(width, ' ');
	ft_putstr("0x");
	if (width >= 0)
		all += ft_printf_x(nbr) + 2 + width;
	else
		all += ft_printf_x(nbr) + 2;
	return (all);
}

int			flagshashthexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, int);
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr) - 2;
	writewidth(width, ' ');
	ft_putstr("0X");
	if (width >= 0)
		all += ft_printf_xm(nbr) + 2 + width;
	else
		all += ft_printf_xm(nbr) + 2;
	return (all);
}

int			flagshashtoctal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr) - 1;
	writewidth(width, ' ');
	ft_putchar('0');
	if (width >= 0)
		all += ft_printf_octal(nbr) + 1 + width;
	else
		all += ft_printf_octal(nbr) + 1;
	return (all);
}

int			flagshashtl(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int			flagshashtll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int			flagshasht_h(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagshashtoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagshashthexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagshashthexam(format, ap, i, width);
	return (all);
}

int			flagshashthh_hexa2(const char *format, unsigned char nbr, int i)
{
	int all;

	all = 0;
	if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(nbr) + 2;
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm(nbr) + 2;
	}
	return (all);
}

int			flagshashthh_hexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'x' || format[i] == 'X')
		width = width - hexalength(nbr) - 2;
	writewidth(width, ' ');
	if (width >= 0)
	{
		if (format[i] == 'x')
		{
			ft_putstr("0x");
			all += ft_printf_x(nbr) + 2 + width;
		}
		else if (format[i] == 'X')
		{
			ft_putstr("0X");
			all += ft_printf_xm(nbr) + 2 + width;
		}
	}
	else
		all += flagshashthh_hexa2(format, nbr, i);
	return (all);
}

int			flagshashthh_octal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	i += 2;
	nbr = (unsigned char)va_arg(ap, int);
	if (format[i] == 'o')
		width = width - octallength(nbr) - 1;
	writewidth(width, ' ');
	if (width >= 0)
	{
		if (format[i] == 'o')
		{
			ft_putchar('0');
			all += ft_printf_octal(nbr) + 1 + width;
		}
	}
	else
	{
		ft_putchar('0');
		all += ft_printf_octal(nbr) + 1;
	}
	return (all);
}

int			flagshashthh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'x'
				|| format[i + 2] == 'X'))
		all += flagshashthh_hexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagshashthh_octal(format, ap, i, width);
	return (all);
}

/*--------------------------PRINTF WIDTH SPACE--------------------------------*/

int			ft_printf_widthspace(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	i++;
	while (format[i] && ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagsspacel(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagsspacell(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagsspaceh(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		all += flagsspacehh(format, ap, i, width);
	else
		all += printf_widthspace2(format, ap, i, width);
	return (all);
}

int			printf_widthspace2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}

int			flagsspacehexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'x')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	writewidth(width, ' ');
	if (width >= 0)
		all += ft_printf_x(nbr) + width;
	else
		all += ft_printf_x(nbr);
	return (all);
}

int			flagsspacehexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'X')
		nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	writewidth(width, ' ');
	if (width >= 0)
		all += ft_printf_xm(nbr) + width;
	else
		all += ft_printf_xm(nbr);
	return (all);
}

int			flagsspaceoctal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'o')
		nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr);
	writewidth(width, ' ');
	if (width >= 0)
		all += ft_printf_octal(nbr) + width;
	else
		all += ft_printf_octal(nbr);
	return (all);
}

int			flagsspaceuint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, unsigned long);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, unsigned long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (format[i] == 'u')
		nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
	writewidth(width, ' ');
	if (width >= 0)
		all += ft_putunbr(nbr) + width;
	else
		all += ft_putunbr(nbr);
	return (all);
}

int			flagsspaceint(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else if (format[i] == 'd' || format[i] == 'i')
		nbr = va_arg(ap, int);
	width = width - ft_intlen(nbr);
	writewidth(width, ' ');
	if (width >= 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	return (all);
}

int			flagsspacel(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}

int			flagsspacell(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}

int			flagsspaceh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}

int			flagsspacehh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsspaceint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagsspaceuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagsspaceoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += flagsspacehexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += flagsspacehexam(format, ap, i, width);
	return (all);
}

/*---------------------------PRINTF WIDTH MINUS-------------------------------*/

int			ft_printf_widthminus(const char *format, va_list ap, int i)
{
	int width;
	int all;

	all = 0;
	width = ft_atoi(format, i);
	while (format[i] && format[i] != '%')
	{
		if (ft_isdigit(format[i]))
			i++;
		i++;
	}
	i--;
	if (format[i] == 'd' || format[i] == 'i')
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		all += flagsminusl(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		all += flagsminusll(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		all += flagsminush(format, ap, i, width);
	else if (format[i] == 'h' && format[i] == 'h')
		all += flagsminushh(format, ap, i, width);
	else
		all += printf_widthminus2(format, ap, i, width);
	return (all);
}

int			printf_widthminus2(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int			flagsminushexa(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (format[i] == 'x')
		all += ft_printf_x(nbr);
	writewidth(width, ' ');
	return (all);
}

int			flagsminushexam(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - hexalength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (format[i] == 'X')
		all += ft_printf_xm(nbr);
	writewidth(width, ' ');
	return (all);
}

int			flagsminusoctal(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - octallength(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (format[i] == 'o')
		all += ft_printf_octal(nbr);
	writewidth(width, ' ');
	return (all);
}

int			flagsminusuint(const char *format, va_list ap, int i, int width)
{
	int			all;
	uintmax_t	nbr;

	all = 0;
	nbr = va_arg(ap, unsigned int);
	width = width - ft_intlen(nbr);
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = (unsigned long)nbr;
	else if (format[i] == 'l' && format[i + 1] == 'l')
		nbr = (unsigned long long)nbr;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (unsigned short)nbr;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (unsigned char)nbr;
	if (width > 0)
		all += ft_putunbr(nbr);
	else
		all += ft_putunbr(nbr);
	writewidth(width, ' ');
	return (all);
}

int			flagsminusint(const char *format, va_list ap, int i, int width)
{
	int all;
	intmax_t nbr;

	all = 0;
	if (format[i] == 'l' && format[i + 1] != 'l')
		nbr = va_arg(ap, long);
	else if (format [i] == 'l' && format[i + 1] == 'l')
		nbr = va_arg(ap, long long);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		nbr = (short)va_arg(ap, int);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		nbr = (signed char)va_arg(ap, int);
	else
		nbr = va_arg(ap, int);
	width = width - ft_intlen(nbr);
	if (nbr < 0)
		all += 1;
	nbr = negnbr(nbr);
	if (width > 0)
		all += ft_printf_nbr(nbr) + width;
	else
		all += ft_printf_nbr(nbr);
	writewidth(width, ' ');
	return (all);
}

int			flagsminusl(const char *format, va_list ap, int i, int width)
{
	int all;
	int nbr;

	all = 0;
	if (format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int			flagsminusll(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int			flagsminush(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

int			flagsminushh(const char *format, va_list ap, int i, int width)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && (format[i + 2] == 'd'
				|| format[i + 2] == 'i'))
		all += flagsminusint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'u')
		all += flagsminusuint(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
		all += flagsminusoctal(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
		all += flagsminushexa(format, ap, i, width);
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
		all += flagsminushexam(format, ap, i, width);
	return (all);
}

/*----------------------------------------------------------------------------*/

int			ft_printf_flagsplus(const char *format, va_list ap, int i)
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

int			ft_printf_flagsspace(const char *format, va_list ap, int i)
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


int			ft_printf_flagshashtag(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	i++;
	if (format[i] == 'o')
	{
		write(1, "0", 1);
		all += ft_printf_octal((unsigned int)va_arg(ap, int)) + 1;
	}
	else if (format[i] == 'h' && format[i + 1] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned short)va_arg(ap, int)) + 1;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned char)va_arg(ap, int)) + 1;
	}
	else
		all += ft_printf_flagshashtag2(format, ap, i);
	return (all);
}

int			ft_printf_flagshashtag2(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned long)va_arg(ap, long)) + 1;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
	{
		ft_putchar('0');
		all += ft_printf_octal((unsigned long long)va_arg(ap, long long)) + 1;
	}
	else if (format[i] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned int)va_arg(ap, int)) + 2;
	}
	else
		all += ft_printf_flagshashtag3(format, ap, i);
	return (all);
}

int			ft_printf_flagshashtag3(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned short)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned char)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x(va_arg(ap, long)) + 2;
	}
	else
		all += ft_printf_flagshashtag4(format, ap, i);
	return (all);
}

int			ft_printf_flagshashtag4(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'x')
	{
		ft_putstr("0x");
		all += ft_printf_x((unsigned long long)va_arg(ap, long long)) + 2;
	}
	else if (format[i] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned int)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'h' && format[i + 1] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned short)va_arg(ap, int)) + 2;
	}
	else
		all += ft_printf_flagshashtag5(format, ap, i);
	return (all);
}

int			ft_printf_flagshashtag5(const char *format, va_list ap, int i)
{
	int all;

	all = 0;
	if (format[i] == 'h' && format[i + 1] == 'h' && format[i + 2] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned char)va_arg(ap, int)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned long)va_arg(ap, long)) + 2;
	}
	else if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'X')
	{
		ft_putstr("0X");
		all += ft_printf_xm((unsigned long long)va_arg(ap, long long)) + 2;
	}
	return (all);
}

int			checkflags(const char *format, va_list ap, int i, int all)
{
	while (format[i])
	{
		if (format[i] == ' ' && format[i + 1] <= '9' && format[i + 1] > '0')
		{
			all += ft_printf_widthspace(format, ap, i);
			i++;
		}
		else if (format[i] == ' ' && format[i + 1] == '0')
		{
			all += printf_space_zero(format, ap, i + 1);
			i++;
		}
		else if (format[i] == '#' && format[i + 1] <= '9' && format[i + 1] > '0')
		{
			all += ft_printf_widthhasht(format, ap, i);
			i++;
		}
		else if (format[i] == '#' && format[i + 1] == '0')
		{
			all += printf_zero_hasht(format, ap, i);
			i++;
		}
		else if (format[i] == '-' && format[i + 1] <= '9' && format[i + 1] >= '0')
		{
			all +=ft_printf_widthminus(format, ap, i);
			i++;
		}
		else if (format[i] == '-')
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
		else if (format[i] == '0')
		{
			all += ft_printf_flagszero(format, ap, i + 1);
			i++;
		}
		else if (format[i] == '.')
		{
			ft_printf_flagszero(format, ap, i);
			i++;
		}
		else if (format[i] <= '9' && format[i] >= '0')
		{
			all += ft_printf_widthspace(format, ap, i);
			i++;
		}
		else
			all = checkall(format, ap, i, all);
		all = countall(format, i, all);
		i = counti(format, i);
		ft_putchar('|');
		if (i == 0)
			return (all);
	}
	return (all);
}

int			checkall2(const char *format, va_list ap, int i, int all)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		all += ft_printf_speint(format, ap, i);
	else if (format[i] == 'h' || format[i] == 'l')
		all += ft_printf_speintlh(format, ap, i);
	else if (format[i] == 'o' || format[i] == 'x' || format[i] == 'X')
		all += ft_printf_specxo(format, ap, i);
	else if (format[i] == 'j' || format[i] == 'z')
		all += ft_printf_specjz(format, ap, i);
	return (all);
}

int			checkall(const char *format, va_list ap, int i, int all)
{
	if (format[i] == 'c' || format[i] == 's')
		all += ft_printf_spechar(format, ap, i);
	else if (format[i] == 'p')
	{
		ft_putstr("0x10");
		ft_printf_p(va_arg(ap, int));
		all += 11;
	}
	else
		all = checkall2(format, ap, i, all);
	return (all);
}

int			printno_opt(const char *format, va_list ap, int i)
{
	int print;

	print = 0;
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
		print++;
	}
	if (format[i] == '%')
		return (checkflags(format, ap, i + 1, print));
	return (print);
}

int			checknoopt(const char *format, va_list ap, int i, int all)
{
	if (format[i] != '%')
		all += printno_opt(format, ap, i);
	else if (format[i] == '%')
		all += checkflags(format, ap, i + 1, all);
	return (all);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		all;

	i = 0;
	all = 0;
	va_start(ap, format);
	ft_putnbr(checknoopt(format, ap, i, all));
	va_end(ap);
	return (0);
}

int			main(void)
{
	char	*p;
	int		i;

	p = "test";
	ft_printf("%#5hhX", 485621);
	ft_putchar('\n');
	ft_putnbr(printf("|%#5hhX", 485621));
}
