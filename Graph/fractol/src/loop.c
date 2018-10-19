/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 11:16:03 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:16:05 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

int		loop_hook(t_env *e)
{
	if (e->psychedelic == 1)
	{
		psychedelic(e);
		e->fractal(e);
	}
	if (e->zoom_auto == 1)
	{
		zoom_auto(e);
		e->fractal(e);
	}
	return (0);
}
