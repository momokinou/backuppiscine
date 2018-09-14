/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/13 10:41:16 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 10:41:19 by qmoricea    ###    #+. /#+    ###.fr     */
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
