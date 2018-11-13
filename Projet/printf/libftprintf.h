/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 21:48:13 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 13:50:05 by qmoricea    ###    #+. /#+    ###.fr     */
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

/* LIBFTPRINTF alphabet */

int					ft_printf_c(char c);
int					ft_printf_str(char *str);

/* LIBFTPRINTF nombres  */

int					ft_intlenc(unsigned int n, int i);
int					ft_intlen(int n);
int					ft_printf_l(const char *format, int i, va_list ap);
int					ft_printf_nbr(int nbr);
void				ft_printnbr_ld(long n);

/* LIBFTPRINTF unsigned nombres  */

void				ft_putunbr(intmax_t n);
void				ft_putunbr_fd(intmax_t n, int fd);

/* LIBFTPRINTF length fonctions long + long long + short for d/i */

void				ft_putnbr_ld(long n);
void				ft_putnbr_hd(short n);

/* LIBFTPRINTF hexa/octets */

int					ft_printf_x(unsigned int n);
int					ft_printf_xm(unsigned int n);
int					ft_printf_octal(unsigned int n);

/* LIBFTPRINTF no options */

void				printno_opt(const char *format);

/* LIBFTPRINTF specifier char */

void				ft_printf_spechar(const char *format, va_list ap, int i);

/* LIBFTPRINTF specifier int */

void				ft_printf_speintl(const char *format, va_list ap, int i);
void				ft_printf_speinth(const char *format, va_list ap, int i);
void				ft_printf_speint(const char *format, va_list ap, int i);

/* LIBFTPRINTF specifier x X o */

void				ft_printf_specxo(const char *format, va_list ap, int i);

/* LIBFTPRINTF length j/z for all int */

void				ft_printf_specjz(const char *format, va_list ap, int i);

/* LIBFTPRINTF gestion spec + length */

// Gestion c s d i u Specifiers
void				checkspec(const char *format, va_list ap, int i);
// Gestion x X o Specifiers & l ll h j z length
void				checkspec2(const char *format, va_list ap, int i);
// Gestion f p
void				checkspec3(const char *format, va_list ap, int i);

/* LIBFTPRINTF main printf */

int					ft_printf(const char *format, ...);

#endif
