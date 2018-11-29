/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printftest.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 10:31:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 14:11:49 by qmoricea    ###    #+. /#+    ###.fr     */
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

typedef struct		s_args
{
	char			specifier;
	char			flags;
	int				width;
	int				precision;
}					t_args;


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
int			ft_intlenc(unsigned int n, int i);
int			ft_intlen(int n);

/*
** Verifications
*/
int			is_valid(const char *format, va_list ap, int i);
int			is_percent(const char *format, va_list ap, int i, int all);

/*
** Gestion du no option
*/
int			checknoopt(const char *format, va_list ap, int i, int all);
int			printno_opt(const char *format, va_list ap, int all);

/*
** Check [flags][width][.precision][length]specifier
*/
int			checkall(const char *format, va_list ap, int i, int all);

/*
** Gestion des flags ' '/-/+/#/0
*/
int			checkflags(const char *format, va_list ap, int i, int all);

int			ft_printf_flagsplus(const char *format, va_list ap, int i);

int			ft_printf_flagshashtag(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag2(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag3(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag4(const char *format, va_list ap, int i);
int			ft_printf_flagshashtag5(const char *format, va_list ap, int i);

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

void		ft_printf_plusnbr(intmax_t n);

/*
** Gestion width
*/
void		checkwidthspec(const char *format, int i, intmax_t nbr);


/*
** Gestion des lengths l/ll/h/hh/j/z
*/
int			ft_printf_speinthl(const char *format, va_list ap, int i);
int			ft_printf_speintll(const char *format, va_list ap, int i);
int			ft_printf_speinth(const char *format, va_list ap, int i);
int			ft_printf_speinthh(const char *format, va_list ap, int i);

int			ft_putunbr_hd(short n);
#endif
