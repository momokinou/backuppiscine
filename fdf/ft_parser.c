
#include "incl/fdf.h"

static int		**ft_read_file_x(int fd, char *line, t_env *mlx)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (get_next_line(fd, &line))
	{
		j = -1;
		mlx->len_x = 0;
		split = ft_error(line);
		ft_strdel(&line);
		while (split[mlx->len_x])
			mlx->len_x++;
		if (!(mlx->map[i] = (int *)malloc(sizeof(int*) * mlx->len_x)))
			return (0);
		while (++j < mlx->len_x)
		{
			mlx->map[i][j] = ft_atoi(split[j]);
			ft_strdel(&split[j]);
		}
		free(split);
		i++;
	}
	ft_strdel(&line);
	return (0);
}

int				**ft_read_file_y(int fd, char *line, char **av, t_env *mlx)
{
	mlx->len = 0;
	while (get_next_line(fd, &line))
	{
		mlx->len++;
		ft_strdel(&line);
		mlx->len_y = mlx->len;
	}
	ft_strdel(&line);
	if (!(mlx->map = (int **)malloc(sizeof(int *) * mlx->len)))
		return (0);
	close(fd);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	ft_read_file_x(fd, line, mlx);
	*mlx = ft_init_mlx(*mlx);
	ft_draw_col(*mlx);
	ft_draw_line(*mlx);
	return (0);
}
