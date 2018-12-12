/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printftest.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 10:31:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 13:12:56 by qmoricea    ###    #+. /#+    ###.fr     */
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
** Depuis la LIBFTPRINTF
*/
int			ft_printf(const char *format, ...);

/*
** Outils
*/
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char *format);
void		ft_putstr(char const *format);
void		ft_putnbr(intmax_t n);
void		ft_putnbr_fd(intmax_t n, int fd);
int			ft_putunbr(intmax_t n);
int			ft_putunbr_fd(intmax_t n, int fd);
int			ft_intlenc(unsigned int n, int i);
int			ft_intlen(int n);
int			ft_putnbr_ld(long n);
int			ft_putunbr_ld(long long n);
int			ft_putnbr_hd(short n);
int			ft_putunbr_hd(short n);

/*
** Gestion du no option
*/
int			checknoopt(const char *format, va_list ap, int i, int all);
int			printno_opt(const char *format, va_list ap, int all);

/*
** Check [flags][width][.precision][length]specifier
*/
int			checkall(const char *format, va_list ap, int i, int all);
int			checkall2(const char *format, va_list ap, int i, int all);
int			counti(const char *format, int i);
int			countall(const char *format, int i, int all);
int			is_valid(char c);

/*
** Gestion Specifiers c/s/p/d/i/u/o/x/X | Lengths h/hh/l/ll/j/z
*/
int			ft_printf_spechar(const char *format, va_list ap, int i);
int			ft_printf_speint(const char *format, va_list ap, int i);
int			ft_printf_speintlh(const char *format, va_list ap, int i);
int			ft_printf_speintll(const char *format, va_list ap, int i);
int			ft_printf_speinth(const char *format, va_list ap, int i);
int			ft_printf_speinthh(const char *format, va_list ap, int i);
int			ft_printf_specxo(const char *format, va_list ap, int i);
int			ft_printf_specz(const char *format, va_list ap, int i);
int			ft_printf_specjz(const char *format, va_list ap, int i);

/*
** Print Specifiers
*/
int			ft_printf_c(char c);
int			ft_printf_str(char *str);
int			ft_printf_nbr(int nbr);
int			ft_printf_unbr(int nbr);
int			ft_printf_p(uintmax_t n);
int			ft_printf_x(uintmax_t n);
int			ft_printf_xm(uintmax_t n);
int			ft_printf_octal(uintmax_t n);

/*
** Gestion des flags ' '/-/+/#/0
*/
int			checkflags(const char *format, va_list ap, int i, int all);
int			checkflags2(const char *format, va_list ap, int i, int all);
int			checkflags3(const char *format, va_list ap, int i, int all);

int			ft_printf_flagsplus(const char *format, va_list ap, int i);
void		ft_printf_plusnbr(intmax_t n);

int			ft_printf_widthspace(const char *format, va_list ap, int i);
int			printf_widthspace2(const char *format, va_list ap, int i,
		int width);
int			flagsspaceint(const char *format, va_list ap, int i, int width);
int			flagsspacel(const char *format, va_list ap, int i, int width);
int			flagsspacell(const char *format, va_list ap, int i, int width);
int			flagsspaceh(const char *format, va_list ap, int i, int width);
int			flagsspacehh(const char *format, va_list ap, int i, int widht);
int			flagsspaceuint(const char *format, va_list ap, int i, int width);
int			flagsspaceoctal(const char *format, va_list ap, int i, int width);
int			flagsspacehexa(const char *format, va_list ap, int i, int width);
int			flagsspacehexam(const char *format, va_list ap, int i, int width);

int			ft_printf_flagshashtag(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag2(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag3(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag4(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag5(const char *format, va_list ap, int i);
int			ft_printf_widthhasht(const char *format, va_list ap, int i);
int			printf_widthhasht2(const char *format, va_list ap, int i,
		int width);
int			flagshashtl(const char *format, va_list ap, int i, int width);
int			flagshashtll(const char *format, va_list ap, int i, int width);
int			flagshasht_h(const char *format, va_list ap, int i, int width);
int			flagshashthh(const char *format, va_list ap, int i, int width);
int			flagshashtoctal(const char *format, va_list ap, int i, int width);
int			flagshashthexa(const char *format, va_list ap, int i, int width);
int			flagshashthexam(const char *format, va_list ap, int i, int width);

int		printf_zero_hasht(const char *format, va_list ap, int i);
int		printf_zero_hasht2(const char *format, va_list ap, int i, int width);
int		zero_hasht_hexa(const char *format, va_list ap, int i, int width);
int		zero_hasht_hexam(const char *format, va_list ap, int i, int width);
int		zero_hasht_octal(const char *format, va_list ap, int i, int width);
int		zero_hashtl(const char *format, va_list ap, int i, int width);
int		zero_hashtll(const char *format, va_list ap, int i, int width);
int		zero_hasht_h(const char *format, va_list ap, int i, int width);
int		zero_hashthh(const char *format, va_list ap, int i, int width);
int		zero_hashthh_hexa(const char *format, va_list ap, int i, int width);
int		zero_hashthh_hexa2(const char *format, unsigned char nbr, int i,
		int width);
int		zero_hasht_octal(const char *format, va_list ap, int i, int width);

int			ft_printf_flagszero(const char *format, va_list ap, int i);
int			printf_flagszero2(const char *format, va_list ap, int i, int width);
int			flagszeroint(const char *format, va_list ap, int i, int width);
int			flagszerouint(const char *format, va_list ap, int i, int width);
int			flagszerohexa(const char *format, va_list ap, int i, int width);
int			flagszerohexam(const char *format, va_list ap, int i, int width);
int			flagszerooctal(const char *format, va_list ap, int i, int width);
int			flagszerol(const char *format, va_list ap, int i, int width);
int			flagszeroll(const char *format, va_list ap, int i, int width);
int			flagszeroh(const char *format, va_list ap, int i, int width);
int			flagszerohh(const char *format, va_list ap, int i, int width);

int			ft_printf_widthminus(const char *format, va_list ap, int i);
int			printf_widthminus2(const char *format, va_list ap, int i,
		int width);
int			flagsminushexa(const char *format, va_list ap, int i, int width);
int			flagsminushexam(const char *format, va_list ap, int i, int width);
int			flagsminusoctal(const char *format, va_list ap, int i, int width);
int			flagsminusuint(const char *format, va_list ap, int i, int width);
int			flagsminusint(const char *format, va_list ap, int i, int width);
int			flagsminusl(const char *format, va_list ap, int i, int width);
int			flagsminusll(const char *format, va_list ap, int i, int width);
int			flagsminush(const char *format, va_list ap, int i, int width);
int			flagsminushh(const char *format, va_list ap, int i, int width);

void		ft_printf_plusnbr(intmax_t n);

/*
** Gestion width
*/
void		checkwidthspec(const char *format, int i, intmax_t nbr);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_atoi(const char *format, int i);
void		writewidth(int width, char type);
int			negnbr(int nbr);

/*
** Gestion printf length
*/
int			octallength(int nbr);
int			hexalength(int nbr);

#endif
