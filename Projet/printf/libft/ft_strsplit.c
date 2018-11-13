/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:21:17 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/18 11:13:05 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_parts(const char *s, char c)
{
	int		cnt;
	int		i;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_wlen(const char *s, char c)
{
	int		len;

	if (!s)
		return (0);
	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	nb_word = ft_cnt_parts((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_cnt_parts((const char *)s, c) + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (t[index] == NULL)
			return (NULL);
		s = s + ft_wlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
