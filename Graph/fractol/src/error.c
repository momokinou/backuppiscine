/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 11:13:35 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 11:13:37 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_arg(void)
{
	write(1, "Usage <filename> [mandelbrot/julia/burningship]\n", 48);
	exit(1);
}

void	error_malloc(void)
{
	write(1, "Malloc error\n", 13);
}
