/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 12:12:52 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:03:23 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		all;

	i = 0;
	all = 0;
	va_start(ap, format);
	all = checknoopt(format, ap, i, all);
	va_end(ap);
	return (all);
}
