/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 16:01:48 by nzenzela     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/28 16:17:00 by nzenzela    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			display_error(void)
{
	write(1, "An error has been detected\n", 27);
	exit(0);
}

t_tetrim		*makestr(char *str)
{
	int			i;
	int			k;
	char		w;
	t_tetrim	*tetrinos;
	t_tetrim	*temp;

	k = 0;
	w = 64;
	i = simple_check(str);
	if (!(tetrinos = (t_tetrim *)malloc(sizeof(t_tetrim))))
		return (NULL);
	temp = tetrinos;
	while (i-- > 0)
	{
		temp->str = ft_strndup(&str[k], 20);
		magic_check(temp->str);
		temp->d = ++w;
		k += 21;
		if (!(temp->next = (t_tetrim *)malloc(sizeof(t_tetrim))))
			return (NULL);
		temp = temp->next;
	}
	temp->next = NULL;
	return (tetrinos);
}

char			*readdata(char *file)
{
	int			fd;
	int			read_stat;
	int			i;
	char		tmp[545];
	char		buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		display_error();
	while ((read_stat = read(fd, buffer, 1)))
	{
		tmp[i++] = buffer[0];
		if (i > 545)
			display_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		display_error();
	return (ft_strdup(tmp));
}

int				main(int argc, char *argv[])
{
	t_tetrim	*tetrinos;
	char		*data;
	char		**result;

	if (argc == 2)
	{
		data = readdata(argv[1]);
		tetrinos = makestr(data);
		tetrinos = setdefault_xy(tetrinos);
		result = finish(tetrinos, getmaxs(tetrinos));
		free(tetrinos);
		while (*result)
			ft_putendl(*result++);
	}
	else
	{
		write(1, "correct usage : ./fillit <file>", 31);
		return (0);
	}
	return (0);
}
