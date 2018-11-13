/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printhexa.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:57:55 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:46:27 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_x(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_x(n / 16) + ft_printf_x(n % 16));
	else
		return (ft_printf_c(HEX[n]));
}

int			ft_printf_xm(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_xm(n / 16) + ft_printf_xm(n % 16));
	else
		return (ft_printf_c(HEXM[n]));
}
