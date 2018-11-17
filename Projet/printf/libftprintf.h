/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 21:48:13 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 12:35:49 by qmoricea    ###    #+. /#+    ###.fr     */
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

/*
**Depuis la LIBFTPRINTF
*/
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putnbr(intmax_t n);
void				ft_putnbr_fd(intmax_t n, int fd);

/*
**LIBFTPRINTF alphabet
*/
int					ft_printf_c(char c);
int					ft_printf_str(char *str);

/*
**LIBFTPRINTF nombres
*/
int					ft_intlenc(unsigned int n, int i);
int					ft_intlen(int n);
int					ft_printf_l(const char *format, int i, va_list ap);
int					ft_printf_nbr(int nbr);
void				ft_printnbr_ld(long n);
void				ft_printf_plusnbr(intmax_t n);

/*
**LIBFTPRINTF unsigned nombres
*/
void				ft_putunbr(intmax_t n);
void				ft_putunbr_fd(intmax_t n, int fd);
int					ft_printf_unbr(int nbr);

/*
**LIBFTPRINTF length fonctions long + long long + short for d/i
*/
void				ft_putnbr_ld(long n);
void				ft_putnbr_hd(short n);
void				ft_putunbr_hd(short n);

/*
**LIBFTPRINTF hexa/octets/pointer adress
*/
int					ft_printf_x(unsigned int n);
int					ft_printf_xm(unsigned int n);
int					ft_printf_octal(unsigned int n);
int					ft_printf_p(unsigned int n);

/*
**LIBFTPRINTF no options
*/
void				printno_opt(const char *format);

/*
**LIBFTPRINTF specifier char
*/
void				ft_printf_spechar(const char *format, va_list ap, int i);

/*
**LIBFTPRINTF specifier int
*/
void				ft_printf_speintl(const char *format, va_list ap, int i);
void				ft_printf_speinth(const char *format, va_list ap, int i);
void				ft_printf_speinth2(const char *format, va_list ap, int i);
void				ft_printf_speint(const char *format, va_list ap, int i);

/*
**LIBFTPRINTF specifier x X o
*/
void				ft_printf_specxo(const char *format, va_list ap, int i);

/*
**LIBFTPRINTF length j/z for all int
*/
void				ft_printf_specjz(const char *format, va_list ap, int i);
void				ft_printf_specjz2(const char *format, va_list ap, int i);

/*
**LIBFTPRINTF gestion spec + length
*/
/*
**Gestion c s d i u Specifiers
**Gestion x X o Specifiers & l ll h j z
**Gestion f p
**Gestion no options
*/
void				checkspec(const char *format, va_list ap, int i);
void				checkspec2(const char *format, va_list ap, int i);
void				checkspec3(const char *format, va_list ap, int i);
void				checknoopt(const char *format, va_list ap, int i);

/*
**Gestion des Flags - + ' ' et #
*/
void				ft_printf_flagsminus(const char *format, va_list ap, int i);
void				ft_printf_flagsplus(const char *format, va_list ap, int i);
void				ft_printf_flagsspace(const char *format, va_list ap, int i);
void				ft_printf_flagshashtag(const char *format, va_list ap,
		int i);
void				ft_printf_flagszero(const char *format, va_list ap, int i);
void				ft_printf_flagszero2(const char *format, va_list ap, int i);
void				ft_printf_flagszero3(const char *format, va_list ap, int i);
void				ft_printf_flagszero4(const char *format, va_list ap, int i);

/*
**Check des Flags
*/
void				checkflags(const char *format, va_list ap, int i);
void				checkflags2(const char *format, va_list ap, int i);
void				checkflags3(const char *format, va_list ap, int i);

/*
**Gestion width
*/
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
int					widthatoi(const char *str);
void				checkwidthspec(const char *format, int i, intmax_t nbr);
void				checkwidthspec2(const char *format, int i, char *str);
void				writewidth(int width, char type);
void				ft_printf_width(const char *format, va_list ap, int i);

/*
**LIBFTPRINTF main printf
*/
int					ft_printf(const char *format, ...);

#endif
