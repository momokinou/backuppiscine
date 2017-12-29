/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 17:24:24 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 14:30:18 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct			w_fd
{
	int					fd;
	int					start;
	t_list				*lst;
	struct fd_list		*next;
}						x_fd;

int						get_next_line(const int fd, char **line);

#endif
