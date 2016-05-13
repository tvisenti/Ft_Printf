/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:34:28 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 17:59:34 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_modifier_wc(t_flag *f, va_list *ap)
{
	wchar_t		wc;
	wchar_t		ws[2];

	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = '\0';
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
	{
		f->ret = -1;
		return (0);
	}
	f->warg = ws;
	ft_handler_char(f);
	return (0);
}

int		ft_handler_c(t_flag *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c;
	char		s[2];

	ft_apply_mask(f, mask_c);
	if (f->fla[10] == 1)
		return (ft_modifier_wc(f, ap));
	else
	{
		c = (char)va_arg(*ap, int);
		if (c == 0 && f->fla[0] == -1)
			f->fla[0] = 0;
		s[0] = c;
		s[1] = '\0';
		f->arg = s;
		ft_handler_char(f);
	}
	if (f->arg[0] == 0)
		ft_buf('\0', f);
	return (0);
}

int		ft_handler_wc(t_flag *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	ft_apply_mask(f, mask_c);
	return (ft_modifier_wc(f, ap));
}
