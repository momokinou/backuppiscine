/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pos.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:03:23 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:18:01 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim			*makenewxy(t_tetrim *tetrinos, int x, int y)
{
	int		rowmin;
	int		linemin;
	int		i;

	rowmin = 200;
	linemin = 200;
	i = 0;
	while (i != 4)
	{
		if (tetrinos->x[i] < rowmin)
			rowmin = tetrinos->x[i];
		if (tetrinos->y[i] < linemin)
			linemin = tetrinos->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		tetrinos->x[i] = tetrinos->x[i] - rowmin + x;
		tetrinos->y[i] = tetrinos->y[i] - linemin + y;
		i++;
	}
	return (tetrinos);
}

static	t_tetrim	*make_tetrinosxy(t_tetrim *tetrinos, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				tetrinos->x[i] = x;
				tetrinos->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tetrinos);
}

t_tetrim			*setdefault_xy(t_tetrim *tetrinos)
{
	t_tetrim	*temp;

	temp = tetrinos;
	while (tetrinos->next)
	{
		tetrinos = make_tetrinosxy(tetrinos, ft_strsplit(tetrinos->str, '\n'));
		free(tetrinos->str);
		tetrinos = tetrinos->next;
	}
	return (temp);
}
