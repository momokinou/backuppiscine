/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_nbr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:08:53 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 10:10:10 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_nbr(int nbr)
{
		ft_putnbr(nbr);
			return (ft_intlen(nbr));
}

int		ft_printf_unbr(int nbr)
{
		return (ft_putunbr(nbr));
}
