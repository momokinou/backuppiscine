/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 21:48:13 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 10:57:36 by qmoricea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define HEX "0123456789abcdef"
# define HEXM "0123456789ABCDEF"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

/* Depuis la LIBFT */

size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putnbr(intmax_t n);
void				ft_putnbr_fd(intmax_t n, int fd);

/* Fin de la LIBFT */

/* LIBFTPRINTF alphabet */

int					ft_printf_c(char c);
int					ft_printf_str(char *str);

/* Fin de la LIBFTPRINTF alphabet */

/* LIBFTPRINTF nombres  */

int					ft_intlenc(unsigned int n, int i);
int					ft_intlen(int n);
int					ft_printf_l(const char *format, int i, va_list ap);
int					ft_printf_nbr(int nbr);
void				ft_printnbr_ld(long n);

/* Fin LIBFTPRINTF nombres  */

#endif
