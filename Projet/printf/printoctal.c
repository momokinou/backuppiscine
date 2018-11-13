/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printoctal.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 13:00:45 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:01:11 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_octal(unsigned int n)
{
	if (n >= 8)
		return (ft_printf_octal(n / 8) + ft_printf_x(n % 8));
	else
		return (ft_printf_c(48 + n));
}
