/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:08:31 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/15 09:53:48 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*rl(const int fd, char *buff, int *ret)
{
	char	tpm[BUFF_SIZE + 1];
	char	*store;

	*ret = read(fd, tpm, BUFF_SIZE);
	tpm[*ret] = '\0';
	store = buff;
	if (!(buff = ft_strjoin(buff, tpm)))
		return (NULL);
	ft_strdel(&store);
	return (buff);
}

int				gf(char **line, char **buff)
{
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	ft_bzero(*buff, ft_strlen(*buff));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff = "";
	int			ret;
	char		*file;

	ret = 1;
	if (!line || fd < 0 || (buff[0] == '\0' && (!(buff = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((file = ft_strchr(buff, '\n')) != NULL)
		{
			*file = '\0';
			if (!(*line = ft_strdup(buff)))
				return (-1);
			ft_memmove(buff, file + 1, ft_strlen(file + 1) + 1);
			return (1);
		}
		if (!(buff = rl(fd, buff, &ret)))
			return (-1);
	}
	ft_strdel(&file);
	if (ret == 0 && ft_strlen(buff))
		ret = gf(&(*line), &buff);
	return (ret);
}
