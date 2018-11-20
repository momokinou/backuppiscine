/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printftest.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 10:31:58 by qmoricea     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 11:38:17 by qmoricea    ###    #+. /#+    ###.fr     */
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
	char			*width;
	char			*precision;
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

#endif
