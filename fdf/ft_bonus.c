
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
		mlx->dec = mlx->dec + 2;
	if (key == X && mlx != NULL)
		mlx->dec = mlx->dec - 2;
	return (0);
}
