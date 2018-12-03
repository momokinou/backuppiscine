/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gestion_width.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:05:45 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:19:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int		ft_atoi(const char *format, int i)
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

void	writewidth(int width, char type)
{
	while (width > 0)
	{
		ft_putchar(type);
		width--;
	}
}
