/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printchar.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 12:44:33 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:00:35 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void		ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

/*    Print Char+String de Printf    */

int			ft_printf_c(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int			ft_printf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(null)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}
