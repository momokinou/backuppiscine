/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   intlen.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:49:19 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 12:50:12 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_intlenc(unsigned int n, int i)
{
	if (n >= 10)
		return (ft_intlenc(n / 10, i + 1));
	else
		return (i + 1);
	return (0);
}

int			ft_intlen(int n)
{
	int				len;
	unsigned int	i;

	if (n < 0)
		i = n * -1;
	else
		i = n;
	len = ft_intlenc(i, 0);
	if (n < 0)
		len = len + 1;
	else
		len = len + 0;
	return (len);
}
