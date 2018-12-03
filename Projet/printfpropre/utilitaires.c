/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilitaires.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 10:11:23 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 12:23:58 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		counti(const char *format, int i)
{
	while (format[i] && format[i] != '%')
		i++;
	if (format[i] == '%')
		return (i + 1);
	else if (!format[i])
		return (0);
	return (0);
}
