/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printfchar2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/17 11:38:18 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 11:43:50 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_c(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int		ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(null)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
