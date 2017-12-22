/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 17:24:18 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/22 15:36:09 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_malloc_again(char **str)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*str))))
		return (0);
	ft_strcpy(tmp, *str);
	*str = 0;
	if (!(*str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(*str, tmp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buffer;
	int				i;

	if (fd < 0 || (!buffer && !(buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	if(!(*line = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((i = read(fd, &buffer, BUFF_SIZE)) > 0)
	{
		if (!(ft_malloc_again(&buffer)))
			return (-1);
		ft_strncat(buffer, *line, BUFF_SIZE);
		if (ft_memcmp((*line), buffer, ft_strlen(*line)) == 0)
		write(1, &buffer, 1);
		i++;
	}
	return (0);
}
