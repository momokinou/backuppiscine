/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/14 09:54:30 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/22 18:44:57 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "incl/fdf.h"

int				ft_check_open(int fd, char **av)
{
	char		buff[1];

	errno = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("Invalid file.");
		exit(1);
	}
	read(fd, buff, 1);
	if (errno != 0)
	{
		perror("fdf ");
		exit(1);
	}
	return (fd);
}

int				main(int ac, char **av)
{
	int			fd;
	int			i;
	char		*line;
	t_env		mlx;

	fd = 0;
	i = 0;
	line = NULL;
	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf [MAP].fdf");
		return (0);
	}
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, MAX_WID, MAX_HGH, "FDF");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 5, 0xFFFFFF, "< for left");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 20, 0xFFFFFF, "> for right");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 35, 0xFFFFFF, "^ for  up");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 50, 0xFFFFFF, "arrow down for down");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 65, 0xFFFFFF, "w or + for decrease");
	mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, 10, 80, 0xFFFFFF, "s or - for increase");
	fd = ft_check_open(fd, av);
	ft_read_file_y(fd, line, av, &mlx);
	mlx_key_hook(mlx.win_ptr, ft_key_hook, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
