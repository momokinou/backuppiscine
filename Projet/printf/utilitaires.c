/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilitaires.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:11:23 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:37:34 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		counti(const char *format, int i)
{
	while (format[i] && is_valid(format[i]) && format[i] != '%')
		i++;
	i++;
	while (format[i] && format[i] != '%')
		ft_putchar(format[i++]);
	if (format[i] == '%')
		return (i + 1);
	else if (!format[i])
		return (0);
	return (0);
}

int		countall(const char *format, int i, int all)
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

int		is_valid(char c)
{
	return (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'u'
			&& c != 'o' && c != 'x' && c != 'X' && c != 'f');
}
