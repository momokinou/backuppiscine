/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoricea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:41:44 by qmoricea          #+#    #+#             */
/*   Updated: 2017/11/12 14:41:44 by qmoricea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(const int file)
{
	char buffer;

	while (read(file, BUFF_SIZE, 1) != 0)
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int file;

	if (argc != 2
	{
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	get_next_line(file);
	close(file);
	return (0);
}