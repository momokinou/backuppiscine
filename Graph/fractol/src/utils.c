/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 11:20:22 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:20:22 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_auto(t_env *e)
{
	e->z = e->z * 1.10;
	e->x = e->x * 1.10;
	e->y = e->y * 1.10;
	e->x += e->win_width / 20;
	e->y += e->win_height / 20;
	e->i_max += 2;
}

void	put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->s_line);
	e->pxl[i] = c;
	e->pxl[++i] = c >> 8;
	e->pxl[++i] = c >> 16;
}
