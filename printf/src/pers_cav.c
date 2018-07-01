/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pers_cav.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <nzenzela@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 15:40:37 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 19:53:38 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point	pers_cav_ver(int x, int y, int **map, t_opt opt)
{
	t_point	pt;

	pt.x1 = (x * opt.x_mult * opt.mult) - opt.tilt + opt.x_decal \
	- ((opt.x_med / 2) * opt.x_mult * opt.mult) + ((opt.y_med / 2) \
	* opt.x_mult * opt.mult * opt.t_med);
	pt.y1 = (y * opt.y_mult * opt.mult) - ((map[x][y]) * opt.z_mult \
	* opt.mult) + opt.y_decal - opt.y_med * opt.mult;
	pt.x2 = ((x + 1) * opt.x_mult * opt.mult) - opt.tilt + opt.x_decal \
	- ((opt.x_med / 2) * opt.x_mult * opt.mult) + ((opt.y_med / 2) \
	* opt.x_mult * opt.mult * opt.t_med);
	pt.y2 = (y * opt.y_mult * opt.mult) - (map[x + 1][y] * opt.z_mult \
	* opt.mult) + opt.y_decal - opt.y_med * opt.mult;
	return (pt);
}

t_point	pers_cav_hor(int x, int y, int **map, t_opt opt)
{
	t_point	pt;

	pt.x1 = (x * opt.x_mult * opt.mult) - opt.tilt + opt.x_decal \
	- ((opt.x_med / 2) * opt.x_mult * opt.mult) + ((opt.y_med / 2) \
	* opt.x_mult * opt.mult * opt.t_med);
	pt.y1 = (y * opt.y_mult * opt.mult) - ((map[x][y]) * opt.z_mult \
	* opt.mult) + opt.y_decal - opt.y_med * opt.mult;
	pt.x2 = (x * opt.x_mult * opt.mult) - opt.tilt - opt.tmp_tilt \
	+ opt.x_decal - ((opt.x_med / 2) * opt.x_mult * opt.mult) \
	+ ((opt.y_med / 2) * opt.x_mult * opt.mult * opt.t_med);
	pt.y2 = ((y + 1) * opt.y_mult * opt.mult) - (map[x][y + 1] \
	* opt.z_mult * opt.mult) + opt.y_decal - opt.y_med * opt.mult;
	return (pt);
}
