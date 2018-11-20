/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printftest.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 10:31:29 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 11:15:50 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "printftest.h"
#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>

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
/*----------------------------------------------------------------------------*/






int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		all;

	i = 0;
	all = 0;
	va_start(ap, format);
	checknoopt(format, ap, i, all);
	va_end(ap);
	return (0);
}

int			main(void)
{
	ft_printf("%c%%test%%");
}
