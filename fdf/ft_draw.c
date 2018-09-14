/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/13 10:41:09 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/13 10:41:12 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "incl/fdf.h"

t_env		ft_init_mlx(t_env mlx)
{
	if (mlx.len_y && mlx.len_x < 500)
	{
		mlx.strtx = 550;
		mlx.strty = 470;
		mlx.pad = 25;
	}
	else if ((mlx.len_y && mlx.len_x > 500) || (mlx.len_y && mlx.len_x
			< 20000))
	{
		mlx.strtx = 1800 / 2;
		mlx.strty = 1200 / 2;
		mlx.pad = 8;
	}
	else if ((mlx.len_y && mlx.len_x > 20000))
	{
		mlx.strtx = 50;
		mlx.strty = 800;
		mlx.pad = 3;
	}
	mlx.y = 1;
	mlx.x = 1;
	mlx.dec = 5;
	mlx.coef_z = 1;
	return (mlx);
}

t_bresen	ft_init_bresen(t_point a, t_point b)
{
	t_bresen	point;

	point.dx = fabs((double)(b.x - a.x));
	point.dy = fabs((double)(b.y - a.y));
	if (a.x < b.x)
		point.sx = 1;
	else
		point.sx = -1;
	if (a.y < b.y)
		point.sy = 1;
	else
		point.sy = -1;
	if (point.dx > point.dy)
		point.err = point.dx / 2;
	else
		point.err = -point.dy / 2;
	return (point);
}

void		ft_bresen(t_point a, t_point b, void *mlx_ptr, void *win_ptr)
{
	int			e;
	t_bresen	point;

	point = ft_init_bresen(a, b);
	while (1)
	{
		if (a.x == b.x && a.y == b.y)
			break ;
		mlx_pixel_put(mlx_ptr, win_ptr, a.x, a.y, 0x0AACCFF);
		e = point.err;
		if (e > -point.dx)
		{
			point.err = point.err - point.dy;
			a.x += point.sx;
		}
		if (e < point.dy)
		{
			point.err = point.err + point.dx;
			a.y += point.sy;
		}
	}
}

int			ft_draw_col(t_env mlx)
{
	int				i;
	int				j;
	t_point			a;
	t_point			b;

	i = 0;
	while (i < mlx.len_y)
	{
		j = 0;
		while (j < mlx.len_x - 1)
		{
			a.z = mlx.map[i][j] * mlx.coef_z;
			a.y = (mlx.strty - (j * mlx.dec) + (i * mlx.pad) - 2 *
			a.z * mlx.y);
			a.x = (mlx.strtx + (j * mlx.dec) + (j * mlx.pad) + a.z * mlx.x);
			j++;
			b.z = mlx.map[i][j] * mlx.coef_z;
			b.y = (mlx.strty - (j * mlx.dec) + (i * mlx.pad) - 2 * b.z
			* mlx.y);
			b.x = (mlx.strtx + (j * mlx.dec) + (j * mlx.pad) + b.z * mlx.x);
			ft_bresen(a, b, mlx.mlx_ptr, mlx.win_ptr);
		}
		i++;
	}
	return (0);
}

int			ft_draw_line(t_env mlx)
{
	int				i;
	int				j;
	t_point			a;
	t_point			b;

	i = 0;
	while (i < mlx.len_y - 1)
	{
		j = -1;
		while (++j < mlx.len_x)
		{
			a.z = mlx.map[i][j] * mlx.coef_z;
			a.y = (mlx.strty - (j * mlx.dec) + (i * mlx.pad) - 2 * a.z * mlx.y);
			a.x = (mlx.strtx + (j * mlx.dec) + (j * mlx.pad) + a.z * mlx.x);
			i++;
			b.z = mlx.map[i][j] * mlx.coef_z;
			b.y = (mlx.strty - (j * mlx.dec) + (i * mlx.pad) - 2 * b.z * mlx.y);
			b.x = (mlx.strtx + (j * mlx.dec) + (j * mlx.pad) + b.z * mlx.x);
			ft_bresen(a, b, mlx.mlx_ptr, mlx.win_ptr);
			i--;
		}
		i++;
	}
	return (0);
}
