/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 10:00:33 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/24 09:27:48 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	sp(const char *f)
{
	int		i;

	i = 1;
	while (f[i])
	{
		if (f[i] == '%')
		{
			write(1, "%", 1);
			i++;
		}
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (av[1])
	{
		while (av[i])
			i++;
		j = i - 2;
		i = 1;
		sp(av[i]);
	}
	return (0);
}
