/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bonus.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/13 10:40:56 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/22 18:46:07 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "incl/fdf.h"

int		ft_key_hook(int key, t_env *mlx)
{
	if (key == ESC && mlx)
	{
		ft_free_map(&mlx);
		exit(0);
	}
	if (key == MORE && mlx)
		mlx->coef_z = mlx->coef_z + 1;
	if (key == LESS && mlx)
		mlx->coef_z = mlx->coef_z - 1;
	if (key == LEFT && mlx)
		mlx->strtx = mlx->strtx - 5;
	if (key == UP && mlx)
		mlx->strty = mlx->strty - 5;
	if (key == RIGHT && mlx)
		mlx->strtx = mlx->strtx + 5;
	if (key == DOWN && mlx)
		mlx->strty = mlx->strty + 5;
	if (key == RTRN && mlx)
		*mlx = ft_init_mlx(*mlx);
	ft_key_hook2(key, mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 5, 0xFFFFFF, "< for left");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 20, 0xFFFFFF, "> for right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 35, 0xFFFFFF, "^ for  up");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, 0xFFFFFF, "arrow down for down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 65, 0xFFFFFF, "w or + for decrease");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 80, 0xFFFFFF, "s or - for increase");
	ft_draw_col(*mlx);
	ft_draw_line(*mlx);
	return (0);
}


int		ft_key_hook2(int key, t_env *mlx)
{
	if (key == PVTD && mlx != NULL)
		mlx->dec = mlx->dec - 2;
	if (key == PVTG && mlx != NULL)
		mlx->dec = mlx->dec + 2;
	if (key == W && mlx != NULL)
		mlx->y = mlx->y + 2;
	if (key == A && mlx != NULL)
		mlx->x = mlx->x - 2;
	if (key == S && mlx != NULL)
		mlx->y = mlx->y - 2;
	if (key == D && mlx != NULL)
		mlx->x = mlx->x + 2;
	if (key == Z && mlx != NULL)
		mlx->dec = mlx->dec * 1.1;
	if (key == X && mlx != NULL)
		mlx->dec = mlx->dec * 0.9;
	return (0);
}
