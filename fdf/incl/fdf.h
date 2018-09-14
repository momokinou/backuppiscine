/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/14 08:29:12 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/14 10:59:29 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESC 53
# define LESS 27
# define MORE 24
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define RTRN 48
# define PVTD 30
# define PVTG 33
# define W 13
# define X 7
# define Z 6
# define A 0
# define S 1
# define D 2

# define MAX_WID 1800
# define MAX_HGH 1200

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef	struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				len;
	int				len_y;
	int				len_x;
	int				**map;
	int				x;
	int				y;
	int				coef_z;
	int				pad;
	int				dec;
	int				strtx;
	int				strty;
}					t_env;

typedef struct		s_bresen
{
	int				dx;
	int				dy;
	int				err;
	int				sx;
	int				sy;
}					t_bresen;

int					ft_check_open(int fd, char **av);
int					**ft_read_file_y(int fd, char *line, char **av, t_env *mlx);
char				**ft_error(char *line);
t_env				ft_init_mlx(t_env mlx);
int					ft_draw_col(t_env mlx);
int					ft_draw_line(t_env mlx);
void				ft_bresen(t_point a, t_point b, void *mlx_ptr,
					void *win_ptr);
int					ft_free_map(t_env **mlx);
void				ft_str_int_free(int **as);
t_bresen			ft_init_bresen(t_point a, t_point b);
int					ft_key_hook(int key, t_env *mlx);
int					ft_key_hook2(int key, t_env *mlx);
int					key_hook(int key_code, t_env *mlx);
#endif
