/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 17:24:18 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 16:58:49 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"
#include "libft/libft.h"

int		checkerror(int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc(sizeof(char) * (BUFF_SIZE))))
			return (-1);
	}
	return (0);
}

char	*readline(char *str, int fd)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	char *buffer;

	if (checkerror(fd, &buffer, line) == -1)
		return (-1);
	while (read(fd, &buffer, 1) != 0)
	{
		write(1, &buffer, 1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if(argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
