/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   funcforwidth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 08:58:16 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 12:29:41 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int			ft_atoi(const char *str)
{
	int n;
	int isneg;

	isneg = 0;
	n = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '%' || *str == '0' || *str== '.')
		str++;
	if (*str == '-')
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

int            widthatoi(const char *str)
{
	int n;
	int isneg;

	isneg = 0;
	n = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '%' || *str == '0' || *str == ' '
			|| *str == '-' || *str == '#')
		str++;
	if (*str == '-')
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
