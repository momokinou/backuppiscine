/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:58:47 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/07 17:03:46 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < argc)
	{
		while (argv[b])
		{
			ft_putstr(argv[b]);
			ft_putchar('\n');
			b++;
		}
		a++;
	}
}
