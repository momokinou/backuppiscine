/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:03:36 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:21:43 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	char		**tetri_reset(char **tab, t_tetrim *tetrinos, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == tetrinos->d)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

static	char		**tetrisprepare(char **tab, t_tetrim *tetrinos, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetrinos->x[i] == x && tetrinos->y[i] == y)
			{
				tab[y][x] = tetrinos->d;
				i++;
			}
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

static	int			ft_check(char **tab, t_tetrim *tetrinos, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetrinos->x[i] == x && tetrinos->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tetrinos->x[i] == x && tetrinos->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static	char		**tetris(char **tab, t_tetrim *ttr, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!ttr->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			ttr = makenewxy(ttr, x, y);
			if (ft_check(tab, ttr, max))
				tmp = tetris(tetrisprepare(tab, ttr, max), ttr->next, max);
			if (tmp)
				return (tmp);
			tab = tetri_reset(tab, ttr, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char				**finish(t_tetrim *tetrinos, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = make_empty(tab, max);
		tab = tetris(tab, tetrinos, max);
		max++;
	}
	return (tab);
}
