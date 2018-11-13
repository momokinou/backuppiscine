/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 21:23:06 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 22:35:14 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int decoct(int dec)
{
	int		octal;
	int		i;

	octal = 0;
	i = 1;
	while (dec != 0)
	{
		octal += (dec % 8) * i;
		dec /= 8;
		i *= 10;
	}

	return(octal);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nbr;
	char	c;
	char	*str;

	i = 0;
	va_start(ap, format);
	while(format[i] != '\0')
	{
		if(format[i++] != '%')
		{
			while(format[i])
			{
				write(1, &format[i], 1);
				i++;
			}
		}
		else
		{
			if(format[i] == '%')
				write(1, "%", 1);
			else if(format[i] == 'c' || format[i] == 'C')
			{
				c = (wchar_t)va_arg(ap, wint_t);
				ft_printf_c(c);
			}
			else if(format[i] == 's' || format[i] == 'S')
			{
				str = va_arg(ap, char *);
				ft_printf_str(str);
			}
			else if(format[i] == 'd' || format[i] == 'D')
			{
				nbr = va_arg(ap, int);
				ft_printf_nbr(nbr);
			}
			else if(format[i] == 'o' || format[i] == 'O')
			{
			}
		}
	}
	i = 0;
	va_end(ap);
	return(0);
}

int		main(void)
{
	ft_printf("%d", 9);
	write(1, "\n", 1);
	printf("%s %c", "----------------------------------------", '\n');
	printf("%c\n", 9);
	printf("%o", 8);
}
