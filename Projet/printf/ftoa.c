/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ftoa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 09:57:29 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 11:52:43 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char const *s)
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

void	ft_putnbr_fd(intmax_t n, int fd)
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

void	ft_putnbr(intmax_t n)
{
	ft_putnbr_fd(n, 1);
}

int		ft_pow(int nb, int power)
{
	int i;
	int result;

	i = power;
	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
		result = (result * nb);
		i--;
	return (result);
}

void	reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 2;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int reversdigits(int num)
{
	int rev_num = 0, remainder;

	while(num != 0)
	{
		remainder = num % 10;
		rev_num = rev_num * 10 + remainder;
		num /= 10;
	}
	return (rev_num);
}

void	ftoa(float n, char *res, int afterpoint)
{
	int ipart;
	float fpart;
	int i;
	int stock;

	stock = afterpoint;
	ipart = (int)n;
	fpart = n - ipart;
	ft_putnbr(ipart);
	if (fpart < 0)
		fpart = -fpart;
	if (afterpoint > 0)
	{
		ft_putchar('.');
		while (stock > 0)
		{
			fpart = fpart * ft_pow(10, afterpoint);
			ft_putnbr(fpart);
			stock--;
		}
	}
	fpart = reversdigits((int)fpart);
	ft_putchar('\n');
}

int main()
{
	char *res;
	float n = -233.007;
	ftoa(n, res, -1);
	printf("\n%f", 233.007);
	return 0;
}
