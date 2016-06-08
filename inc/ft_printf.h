/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:27:23 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/08 10:37:22 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

char			g_buf[4096];
int				g_i;

/*
** 	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
** 	|pre|wid| # | 0 | - | + |   | hh| h | ll|  l |  j |  z |
*/

typedef struct	s_flag
{
	int			ret;
	char		*frmt;
	int			ndx;
	char		spe;
	char		*arg;
	wchar_t		*warg;

	char		sign;
	va_list		ap;
	int			fla[13];
}				t_flag;

typedef struct	s_spec
{
	char		c;
	int			(*ptr)();
}				t_spec;

/*
** ft_PRINTF
*/

int				ft_printf(const char *format, ...);
void			pf_ft_end(t_flag *f);

/*
** CHECKS
*/

int				pf_ft_check(t_flag *f);
void			pf_ft_check_initialize(t_flag *f);
void			pf_ft_check_flag(t_flag *f);
void			pf_ft_check_width(t_flag *f);
void			pf_ft_check_precision(t_flag *f);
void			pf_ft_check_modifier(t_flag *f);

/*
** UTILS
*/

int				pf_ft_isdigit(int c);
char			*pf_ft_strsub(char const *s, unsigned int start, size_t len);
char			*pf_ft_itoa_base(uintmax_t nbr, int base);
uintmax_t		pf_ft_sign(t_flag *f, intmax_t nbr);
size_t			pf_ft_strlen(const char *str);
long			pf_ft_atoi(const char *str);
char			*pf_ft_strlwr(char *s1);

/*
** Les Wchars
*/

void			pf_ft_putwchar(wchar_t wchar, t_flag *f);
int				pf_ft_wcharlen(wchar_t wchar);
size_t			pf_ft_wbytelen(wchar_t *ws);
size_t			pf_ft_wstrlen(wchar_t *ws);
char			*pf_ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char			*pf_ft_strsub_with_free(char const *s, unsigned int start,
				size_t len);
char			*pf_ft_transform_wchar_in_char(wchar_t *ws);
int				pf_ft_putwchar_in_char(wchar_t wchar, char *fresh, int i);

/*
** DISPATCHER
*/

void			pf_ft_initialize_specs(t_spec *specs);
int				pf_ft_dispatcher(t_flag *f, va_list *ap);

/*
** HANDLERS: functions that handle specifiers
*/

void			pf_ft_apply_mask(t_flag *f, int *mask);
int				pf_ft_handler_char(t_flag *f);
int				pf_ft_handler_numb(t_flag *f);

int				pf_ft_handler_c(t_flag *f, va_list *ap);
int				pf_ft_handler_wc(t_flag *f, va_list *ap);
int				pf_ft_modifier_wc(t_flag *f, va_list *ap);

int				pf_ft_handler_s(t_flag *f, va_list *ap);
int				pf_ft_handler_ws(t_flag *f, va_list *ap);

int				pf_ft_handler_d(t_flag *f, va_list *ap);
int				pf_ft_handler_wd(t_flag *f, va_list *ap);
char			*pf_ft_modifier_d(t_flag *f, va_list *ap);

int				pf_ft_handler_o(t_flag *f, va_list *ap);
int				pf_ft_handler_u(t_flag *f, va_list *ap);
char			*pf_ft_modifier_u_o(t_flag *f, va_list *ap);

int				pf_ft_handler_wo(t_flag *f, va_list *ap);
int				pf_ft_handler_wu(t_flag *f, va_list *ap);
char			*pf_ft_modifier_wu_wo(t_flag *f, va_list *ap);

int				pf_ft_handler_x(t_flag *f, va_list *ap);
int				pf_ft_handler_wx(t_flag *f, va_list *ap);
char			*pf_ft_modifier_x(t_flag *f, va_list *ap);

int				pf_ft_handler_p(t_flag *f, va_list *ap);
int				pf_ft_handler_undefined(t_flag *f);

/*
** ft_apply_flags.c
*/

void			pf_ft_space_plus_sharp(t_flag *f);
void			pf_ft_sharp(t_flag *f);
void			pf_ft_precision_string(t_flag *f);

/*
** ft_display_numb.c
*/

void			pf_ft_precision_without_width(t_flag *f);
void			pf_ft_precision_numb(t_flag *f, int len);
void			pf_ft_zero_numb(t_flag *f);
void			pf_ft_minus_numb(t_flag *f);
void			pf_ft_width_numb(t_flag *f);

/*
** ft_display_numb.c
*/

void			pf_ft_display_arg(t_flag *f);
void			pf_ft_width_char(t_flag *f);
void			pf_ft_minus_char(t_flag *f);
void			pf_ft_zero_char(t_flag *f);

/*
** ft_buff.c
*/

void			pf_ft_buf(char c, t_flag *f);
void			pf_ft_buf_null(t_flag *f);
void			pf_ft_display(t_flag *f);
void			pf_ft_bufset(void);

#endif
