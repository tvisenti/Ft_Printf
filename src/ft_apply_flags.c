/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:23:29 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 17:40:43 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** Pas de free dans la precision WARNING
** Sub string if 's' or 'S'.
*/

void	ft_precision_string(t_flag *f)
{
	if (f->fla[0] == -1)
		f->arg = "\0";
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1))
		f->arg = ft_wstrsub(f->warg, 0, f->fla[0]);
	else if (f->spe == 's')
		f->arg = ft_strsub(f->arg, 0, f->fla[0]);
}

/*
** Ajout 0 pour o et O, 0x pour x et p, 0X pour X
*/

void	ft_sharp(t_flag *f)
{
	if ((f->fla[2] == 1 && f->arg[0] != '0' && f->fla[0] != -1)
		|| f->spe == 'p')
	{
		if (f->spe == 'o' || f->spe == 'O' || f->spe == 'x' || f->spe == 'X' ||
			f->spe == 'p')
		{
			if ((f->spe == 'x' && f->arg[0] != '0') || f->spe == 'p')
			{
				ft_buf('0', f);
				ft_buf('x', f);
			}
			else if (f->spe == 'X' && f->arg[0] != '0')
			{
				ft_buf('0', f);
				ft_buf('X', f);
			}
			else if ((f->spe == 'o' || f->spe == 'O') &&
				f->fla[0] <= ft_strlen(f->arg))
				ft_buf('0', f);
			else if ((f->spe == 'o' || f->spe == 'O') && f->fla[0] == -1)
				ft_buf('0', f);
		}
	}
}

/*
** Ajoute un espace si flag ' ' OU un signe +/- si flag '+'
** appelle la fonction ft_sharp
*/

void	ft_space_plus_sharp(t_flag *f)
{
	if (f->fla[5] == 1 || f->fla[6] == 1)
	{
		if (f->spe == 'd' || f->spe == 'D' || f->spe == 'i')
		{
			if (f->fla[6] == 1 && f->fla[5] == 0 && f->sign != '-')
				ft_buf(' ', f);
			if (f->fla[5] == 1 && ft_isdigit(f->arg[0]) && f->sign == '+')
				ft_buf('+', f);
		}
	}
	if (f->sign == '-')
		ft_buf('-', f);
	ft_sharp(f);
}
