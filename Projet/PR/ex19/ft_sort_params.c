/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:42:25 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/07 16:08:15 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i	] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}

char	**sort(int nb, char **argv)
{
	int		i;
	int		j;
	char	*b;

	i = 0;
	j = 1;
	while (i < nb)
	{
		while (j < nb - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				b = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = b;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (argv);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == -1)
		return (-1);
	sort(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
