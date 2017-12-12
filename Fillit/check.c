/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:03:51 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/30 18:17:35 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	char		*magic_add(int i, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = magic_add(i + 1, s);
	}
	if (s[i - 1] >= 0 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = magic_add(i - 1, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = magic_add(i + 5, s);
	}
	if (i - 5 >= 0 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = magic_add(i - 5, s);
	}
	if (s[i] == '#')
		s[i] = 'x';
	return (s);
}

static	int			magic_count(char *s)
{
	int		res;

	res = 0;
	while (*s)
	{
		if (*s == 'x')
			res++;
		if (*s == '.')
			res++;
		s++;
	}
	return (res);
}

void				magic_check(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '#')
		i++;
	s[i] = 'x';
	s = magic_add(i, s);
	if (magic_count(s) != 16)
		display_error();
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
}

int					simple_check(char *data)
{
	int		rtl;
	int		cube;
	int		dot;

	rtl = 0;
	cube = 0;
	dot = 0;
	while (*data)
	{
		if (*data == '.')
			dot++;
		else if (*data == '#')
			cube++;
		else if (*data == '\n')
			rtl++;
		else
			display_error();
		data++;
	}
	if (cube < 4)
		display_error();
	if (dot % 4 || cube % 4 || (rtl + 1) % 5)
		display_error();
	return (cube / 4);
}
