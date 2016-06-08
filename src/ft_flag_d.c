/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:20:57 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/08 10:33:25 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**		'd' / 'D' / 'i' : recupere et cast l'arg
*/

char	*pf_ft_modifier_d(t_flag *f, va_list *ap)
{
	intmax_t	data;
	uintmax_t	data_max;

	data = 0;
	if (f->fla[12] == 1)
		data = (intmax_t)(va_arg(*ap, ssize_t));
	else if (f->fla[11] == 1)
		data = (va_arg(*ap, intmax_t));
	else if (f->fla[9] == 1)
		data = (intmax_t)(va_arg(*ap, long long));
	else if (f->fla[10] == 1)
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->fla[8] == 1)
		data = (intmax_t)((short)va_arg(*ap, int));
	else if (f->fla[7] == 1)
		data = (intmax_t)((char)va_arg(*ap, int));
	else if (f->spe == 'D')
		data = (intmax_t)(va_arg(*ap, long));
	else if (f->spe == 'd' || f->spe == 'i')
		data = (intmax_t)(va_arg(*ap, int));
	data_max = pf_ft_sign(f, data);
	return (pf_ft_itoa_base(data_max, 10));
}

/*
**			'd' / 'i' : Applique le mask, traitement en numb
*/

int		pf_ft_handler_d(t_flag *f, va_list *ap)
{
	static int	mask_d[13] = {0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_apply_mask(f, mask_d);
	f->arg = pf_ft_modifier_d(f, ap);
	pf_ft_handler_numb(f);
	return (0);
}

/*
**			'D' : Applique le mask, traitement en numb
*/

int		pf_ft_handler_wd(t_flag *f, va_list *ap)
{
	static int	mask_wd[13] = {0, 0, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	pf_ft_apply_mask(f, mask_wd);
	f->arg = pf_ft_modifier_d(f, ap);
	pf_ft_handler_numb(f);
	return (0);
}
