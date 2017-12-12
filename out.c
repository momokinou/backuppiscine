/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:01:30 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:01:34 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**make_empty(char **tab, int max)
{
	int		y;
	int		x;

	y = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (max + 1))))
	{
		while (y < max)
		{
			tab[y] = ft_strnew(max);
			x = 0;
			while (x < max)
			{
				tab[y][x] = '.';
				x++;
			}
			y++;
		}
		tab[y] = NULL;
		return (tab);
	}
	else
		return (NULL);
}

int		getmaxs(t_tetrim *tetrinos)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (tetrinos->next && i++)
		tetrinos = tetrinos->next;
	while (max * max < i * 4)
		max++;
	return (max);
}
