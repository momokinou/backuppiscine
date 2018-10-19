/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 11:14:07 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:14:08 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

static int		julia_iter(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->i_max)
	{
		e->jul->tmp = e->jul->zr;
		e->jul->zr = e->jul->zr * e->jul->zr - e->jul->zi * e->jul->zi - 0.8 +
			(0.6 / ((double)e->option_x / (double)e->win_width));
		e->jul->zi = 2 * e->jul->zi * e->jul->tmp + 0.27015 /
			((double)e->option_y / (double)e->win_height);
		if (e->jul->zr * e->jul->zr + e->jul->zi * e->jul->zi >= 4)
			return (i);
	}
	return (i);
}

void			julia(t_env *e)
{
	intmax_t	x;
	intmax_t	y;

	x = e->x;
	while (++x < e->win_width + e->x)
	{
		y = e->y;
		while (++y < e->win_height + e->y)
		{
			e->jul->zr = (long double)x / e->z + e->jul->x1;
			e->jul->zi = (long double)y / e->z + e->jul->y1;
			put_pxl(e, x - e->x, y - e->y, get_color(julia_iter(e), e));
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_info(e);
}
