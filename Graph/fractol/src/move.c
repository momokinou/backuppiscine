/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 11:16:40 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:16:41 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_env *e)
{
	e->x += e->win_width / 12;
	e->y += e->win_height / 12;
	e->z = e->z * 1.2;
	e->x = e->x * 1.2;
	e->y = e->y * 1.2;
}

void	zoom_out(t_env *e)
{
	if (e->z / 1.2 < 10)
		return ;
	e->x -= e->win_width / 12;
	e->y -= e->win_height / 12;
	e->z = e->z / 1.2;
	e->x = e->x / 1.2;
	e->y = e->y / 1.2;
}
