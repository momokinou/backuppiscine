/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 13:07:14 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 10:53:12 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	char	*p;

	p = "test";
	ft_putnbr(ft_printf("%#5hhX", 485621));
	ft_putchar('\n');
	ft_putnbr(printf("%#5hhX", (unsigned char)485621));
}
