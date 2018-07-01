/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keymap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <nzenzela@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 16:40:59 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/30 19:57:13 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		red_cross(void)
{
	ft_close("Closing window.", EXIT_SUCCESS);
	return (0);
}

int		kf(int keycode, t_glob *glob)
{
	if (keycode == ESC)
		ft_close("Closing window.", EXIT_SUCCESS);
	if (keycode == CENTER)
		ft_center(glob);
	if (keycode == 82)
		ft_zero(glob);
	else if (keycode == DECREASE)
		ft_decrease(glob);
	else if (keycode == INCREASE)
		ft_increase(glob);
	else if (keycode == UP || keycode == 126)
		ft_up(glob);
	else if (keycode == DOWN || keycode == 125)
		ft_down(glob);
	else if (keycode == LEFT || keycode == 123)
		ft_left(glob);
	else if (keycode == RIGHT || keycode == 124)
		ft_right(glob);
	else if (keycode == ZOOMIN)
		ft_zoomin(glob);
	else if (keycode == ZOOMOUT)
		ft_zoomout(glob);
	else if (keycode == 92)
		ft_color(glob);
	return (0);
}
