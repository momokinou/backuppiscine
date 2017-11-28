/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:07:03 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:19:44 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct			s_tetris
{
	char				d;
	char				*str;
	int					x[4];
	int					y[4];
	struct s_tetris		*next;
}						t_tetrim;

void					display_error(void);
char					*readdata(char *file);
void					magic_check(char *d);
int						getmaxs(t_tetrim *tetrinos);
char					**make_empty(char **tab, int max);
int						simple_check(char *data);
char					**finish(t_tetrim *tetrinos, int max);
t_tetrim				*makestr(char *str);
t_tetrim				*setdefault_xy(t_tetrim *tetrinos);
t_tetrim				*makenewxy(t_tetrim *tetrinos, int x, int y);
#endif
