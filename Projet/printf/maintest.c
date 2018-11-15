/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   maintest.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 21:14:28 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 11:47:37 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include "libftprintf.h"
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

/*size_t		udigit_count(uintmax_t n, unsigned int base)
  {
  size_t i;

  i = 0;
  if (n == 0)
  return (1);
  while (n)
  {
  i++;
  n /= base;
  }
  return (i);
  }

  void		*memalloc(size_t size)
  {
  void *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
  return (NULL);
  while (size > 0)
  {
  size--;
  ((unsigned char *)ptr)[size] = (unsigned char)0;
  }
  return (ptr);
  }

  char		*uitoa_base(uintmax_t n, unsigned int base, const char *dig,
  int precision)
  {
  size_t        count;
  char        *str;

  count = udigit_count(n, base);
  if (count < precision)
  count = precision;
  str = memalloc(count + 1);
  if (str == NULL)
  return (NULL);
  while (count > 0)
  {
  str[count - 1] = dig[n % base];
  count--;
  n /= base;
  }
  return (str);
  }*/

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
		if (format[i] == 'd' || format[i] == 'i')
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








size_t		udigit_count(uintmax_t n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

void		*memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		((unsigned char *)ptr)[size] = (unsigned char)0;
	}
	return (ptr);
}

char		*uitoa_base(uintmax_t n, unsigned int base, const char *dig,
		int precision)
{
	size_t		count;
	char		*str;

	count = udigit_count(n, base);
	if (count < precision)
		count = precision;
	str = memalloc(count + 1);
	if (str == NULL)
		return (NULL);
	while (count > 0)
	{
		str[count - 1] = dig[n % base];
		count--;
		n /= base;
	}
	return (str);
}




/* TEST DES LARGEURS */



int        ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int        ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int                ft_atoi(const char *str)
{
	int n;
	int isneg;

	isneg = 0;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '%' || *str == '0')
		str++;
	else if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		n = n * 10 + (*str++ - '0');
	}
	if (isneg)
		return (-n);
	else
		return (n);
}

void        ft_printf_widthspeint(const char *format, int width, int i, 
		intmax_t nbr)
{
	while (format[i])
	{
		if (format[i] == 'd' || format[i] == 'i')
		{
			ft_printf_nbr(nbr);
			break ;
		}
		else if (format[i] == 'u')
		{
			ft_printf_unbr(nbr);
			break ;
		}
		break ;
	}
}

void        checkwidthspec(const char *format, int width, int i, intmax_t
		nbr, char type)
{
	while (width > 0)
	{
		if (type == '0')
			write(1, "0", 1);
		width--;
	}
	if (format[i] == 'd' || format[i] == 'i')
		ft_putunbr(nbr);
}


void        ft_printf_flagszero(const char *format, va_list ap, int i)
{
	int n;
	int m;

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
		checkwidthspec(format, n, i, m, '0');
	}
}







// Gestion Flags - + ' ' # 0

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

/*void		checkwidthspec(const char *format, int width, int i, int nbr)
  {
  while (format[i] == '0')
  i++;
  i++;
  while (format[i])
  {
  if (format[i] == 'd' || format[i] == 'i')
  {
  ft_printf_widthspeint(format, width, i, nbr);
  break ;
  }
  break ;
  }
  }


  void        ft_printf_flagszero(const char *format, va_list ap, int i)
  {
  int n;
  int m;

  n = 0;
  i++;
  while (format[i])
  {
  while (format[i] <= '9' && format[i] > '0')
  {
//ft_putchar(format[i]);
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
checkwidthspec(format, n, i, m);
}
while (n != 0 && n > 0)
{
write(1, "0", 1);
n--;
}
ft_putchar(format[i]);
}*/

void        checkflags(const char *format, va_list ap, int i)
{
	while (format[i])
	{;
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
		i++;
	}
}
// Gestion f p

void		checkspec3(const char *format, va_list ap, int i)
{
		if (format[i] == 'f')
		{
			ft_putnbr((float)va_arg(ap, int));
			i++;
		}
		if (format[i] == 'p')
		{
			ft_putstr(uitoa_base(va_arg(ap, unsigned int),16, format, 0));
			i++;
		}
		checkflags(format, ap, i);
}

// Gestion x X o Specifiers & l ll h j z length

void		checkspec2(const char *format, va_list ap, int i)
{
		if (format[i] == 'x' || format[i] == 'X' || format[i] == 'o')
		{
			ft_printf_specxo(format, ap, i);
			i++;
		}
		if (format[i] == 'l' || format[i] == 'h')
		{
			ft_printf_speint(format, ap, i);
			i++;
		}
		if (format[i] == 'j' || format[i] == 'z')
		{
			ft_printf_specjz(format, ap, i);
			i++;
		}
		checkspec3(format, ap, i);
}


// Gestion c s d i u Specifiers

void		checkspec(const char *format, va_list ap, int i)
{
		if (format[i] == '%')
		{
			write(1, "%", 1);
			i++;
		}
		if (format[i] == 'c' || format[i] == 's')
		{
			ft_printf_spechar(format, ap, i);
			i++;
		}
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		{
			ft_printf_speint(format, ap, i);
			i++;
		}
		checkspec2(format, ap, i);
}

void		checknoopt(const char *format, va_list ap, int i)
{
	if (format[i++] != '%')
	{
		printno_opt(format);
	}
	else
	{
		checkflags(format, ap, i);
	}
}

/* TEST POINTER */



/* TEST DES PRECISION */












int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	checknoopt(format, ap, i);
	i = 0;
	va_end(ap);
	return (0);
}

int			main(void)
{
	char *p;

	p = "test";
	// Test d
	ft_printf("%d", 545665);
	write(1, "\n", 1);
	printf("d %d%s\n", 545665, "->printf");

	// Test c
	ft_printf("%c", 'c');
	write(1, "\n", 1);
	printf("c %c%s\n", 'c', "->printf");

	// Test i
	ft_printf("%i", 0);
	write(1, "\n", 1);
	printf("i %i%s\n", 0, "->printf");

	// Test o
	ft_printf("%o", 95);
	write(1, "\n", 1);
	printf("o %o%s\n", 95, "->printf");

	// Test x
	ft_printf("%x", 101);
	write(1, "\n", 1);
	printf("x %x%s\n", 101, "->printf");

	// Test X
	ft_printf("%X", 42);
	write(1, "\n", 1);
	printf("X %X%s\n", 42, "->printf");

	// Test s
	ft_printf("%s", "test string");
	write(1, "\n", 1);
	printf("s %s%s\n", "test string", "->printf");

	// Test u
	ft_printf("%u", 101);
	write(1, "\n", 1);
	printf("u %u%s\n", 101, "->printf");

	// Test %%
	ft_printf("%%");
	write(1, "\n", 1);
	printf("%%");
	printf("%s\n", "->printf");

	// Partie Test des Flags - + ' ' et #
	// Test - (MINUS)
	ft_printf("%-d", 95);
	write(1, "\n", 1);
	printf("- %-d%s\n", 95, "->printf");

	// Test + (PLUS)
	ft_printf("%+d", 58);
	write(1, "\n", 1);
	printf("+ %+d%s\n", 58, "->printf");

	// Test ' ' (Space)
	ft_printf("% d", 18);
	write(1, "\n", 1);
	printf("Space % d%s\n", 18, "->printf");

	// Test # (Hashtag)
	ft_printf("%#x", 36);
	write(1, "\n", 1);
	printf("# %#x%s\n", 36, "->printf");

	//Test 0 (Zero)
	ft_printf("%05d", 15);
	write(1, "\n", 1);
	printf("0 %05d%s\n", 15, "->printf");

	//Test p
	ft_printf("%p", p);
	write(1, "\n", 1);
	printf("p %p%s\n", p, "->printf");

	printf("%s \n", "----------------------------------------");
	printf("%p\n", p);
	printf("%01d", 5);
}
