/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maintest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 21:14:28 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:57:55 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

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

void		ft_putunbr_fd(intmax_t n, int fd)
{
	uintmax_t x;

	x = n;
	if (n < 0)
		x = 4139320750;
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}

void		ft_putunbr(intmax_t n)
{
	ft_putunbr_fd(n, 1);
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
	ft_putunbr(nbr);
	return (ft_intlen(nbr));
}

void		ft_putnbr_ld(long n)
{
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
}

void		ft_putnbr_hd(short n)
{
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
}

int			ft_printf_x(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_x(n / 16) + ft_printf_x(n % 16));
	else
		return (ft_printf_c(HEX[n]));
}

int		ft_printf_xm(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_xm(n / 16) + ft_printf_xm(n % 16));
	else
		return (ft_printf_c(HEXM[n]));
}

void		printno_opt(const char *format)
{
	int i;

	i = 0;
	while (format[i])
	{
		write(1, &format[i], 1);
		i++;
	}
}

int			ft_printf_octal(unsigned int n)
{
	if (n >= 8)
		return (ft_printf_octal(n / 8) + ft_printf_x(n % 8));
	else
		return (ft_printf_c(48 + n));
}


void		ft_printf_flags(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{}
		else if (format[i])
		{
			;
			break ;
		}
		else if (format[i])
		{
			;
			break ;
		}
	}
}

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

void		ft_printf_speintl(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if(format[i] == 'l' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr_ld(va_arg(ap, long));
			break ;
		}
		else if (format[i] == 'l' && format[i + 1] == 'l' &&
				(format[i + 2] == 'd' || format[i + 2] == 'i'))
		{
			ft_putnbr_ld(va_arg(ap, long long));
			break ;
		}
	}
}

void		ft_printf_speinth(const char *format, va_list ap, int i)
{
	char *str;

	while (format[i])
	{
		if (format[i] == 'h' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putnbr_hd((short)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'h' && format[i + 1] == 'h' &&(format[i + 2] == 'd'
					|| format[i + 2] == 'i'))
		{
			ft_putchar(va_arg(ap, int));
			break ;
		}
	}
}

void		ft_printf_speint(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			write(1, "%", 1);
			break ;
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			ft_printf_nbr(va_arg(ap, int));
			break ;
		}
		else if (format[i] == 'u')
		{
			ft_printf_unbr(va_arg(ap, unsigned int));
			break ;
		}
		else if (format[i] == 'l')
		{
			ft_printf_speintl(format, ap, i);
			break ;
		}
		ft_printf_speinth(format, ap, i);
		break ;
	}
}

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

// Gestion Flqgs - + ' ' # 0

void		ft_printf_flagsminus(const char *format, va_list ap, int i)
{
}

void		ft_printf_flagsplus(const char *format, va_list ap, int i)
{
}

void		ft_printf_flagsspace(const char *format, va_list ap, int i)
{
}

void		ft_printf_flagshashtag(const char *format, va_list ap, int i)
{
}

void		ft_printf_flagszero(const char *format, va_list ap, int i)
{
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
	}
}

// Gestion f p

void		checkspec3(const char *format, va_list ap, int i)
{
	while (format[i])
	{
		if (format[i] == 'f')
		{
			ft_putnbr((float)va_arg(ap, int));
			break ;
		}
		if (format[i] == 'p')
		{
		}
	}
}

// Gestion x X o Specifiers & l ll h j z length

void		checkspec2(const char *format, va_list ap, int i)
{
	while (format[i] != '\0')
	{
		if (format[i] == 'x' || format[i] == 'X' || format[i] == 'o'
				|| format[i] == 'O')
		{
			ft_printf_specxo(format, ap, i);
			break ;
		}
		if (format[i] == 'l' || format[i] == 'h')
		{
			ft_printf_speint(format, ap, i);
			break ;
		}
		if (format[i] == 'j' || format[i] == 'z')
		{
			ft_printf_specjz(format, ap, i);
			break ;
		}
		checkspec3(format, ap, i);
		break ;
	}
}


// Gestion c s d i u Specifiers

void		checkspec(const char *format, va_list ap, int i)
{
	while (format[i] != '\0')
	{
		if (format[i++] != '%')
		{
			printno_opt(format);
			break ;
		}
		else
		{
			if (format[i] == 'c' || format[i] == 's')
			{
				ft_printf_spechar(format, ap, i);
				break ;
			}
			if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			{
				ft_printf_speint(format, ap, i);
				break ;
			}
			checkspec2(format, ap, i);
			break ;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	checkspec(format, ap, i);
	i = 0;
	va_end(ap);
	return (0);
}

int			main(void)
{
	ft_printf("%d", 545665);
	write(1, "\n", 1);
	ft_printf("%c", 'c');
	write(1, "\n", 1);
	ft_printf("%d", 0);
	write(1, "\n", 1);
	ft_printf("%o", 95);
	write(1, "\n", 1);
	ft_printf("%s", "test string");
	write(1, "\n", 1);
	printf("%s %c", "----------------------------------------", '\n');
	printf("%5d\n", 95);
	printf("%01d", 5);
}
