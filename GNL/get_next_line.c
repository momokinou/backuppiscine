/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 17:24:18 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 16:29:21 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char *tpm;
	char *buff;
	int i;

	i = 1;
	while (buff[i] != 0)
	{
		if (read(fd, &buff[i], BUFF_SIZE) != 0)
		{
			tpm = ft_strchr(buff, '\n');
			while (tpm[i] != '\n')
			{
				write(1, &buff[i], BUFF_SIZE);
				i++;
			}
		}
	}
	return(0);
}

int		main(int argc, char **argv)
{
	int fd;
	char **line;

	if(argc != 2)
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	close(fd);
	return (0);
}
