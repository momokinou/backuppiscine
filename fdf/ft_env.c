/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <jodoming@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/16 14:48:14 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 01:50:21 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "incl/fdf.h"

char		**ft_error(char *line)
{
	char	**split;
	int		i;
	int		j;

	split = ft_strsplit(line, ' ');
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (((split[i][j] < '0' || split[i][j] > '9') && split[i][j] != ' '
						&& split[i][j] != '\n' && split[i][j] != '-' &&
						split[i][j] != ',' && (split[i][j - 1] < '0' ||
						split[i][j - 1] > '9')) && split[i][j] != 'x' &&
						split[i][j] != 'F')
			{
				ft_putendl("error");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (split);
}

void		ft_str_int_free(int **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

int			ft_free_map(t_env **mlx)
{
	int		i;

	i = 0;
	while (i < (*mlx)->len)
	{
		free((*mlx)->map[i]);
		i++;
	}
	free((*mlx)->map);
	return (0);
}
