/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:23:29 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/08 10:33:43 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**				precision : S / ls / s
**		Tronque la chaine et mets la chaine tronque dns f->arg
*/

void	pf_ft_precision_string(t_flag *f)
{
	if (f->fla[0] == -1)
		f->arg = "\0";
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1))
		f->arg = pf_ft_wstrsub(f->warg, 0, f->fla[0]);
	else if (f->spe == 's')
		f->arg = pf_ft_strsub(f->arg, 0, f->fla[0]);
}

/*
**					# : o / O / x / X / p
**		Ajout 0 pour o et O, 0x pour x et p, 0X pour X
*/

void	pf_ft_sharp(t_flag *f)
{
	if ((f->fla[2] == 1 && f->arg[0] != '0' && f->fla[0] != -1)
		|| f->spe == 'p')
	{
		if (f->spe == 'o' || f->spe == 'O' || f->spe == 'x' || f->spe == 'X' ||
			f->spe == 'p')
		{
			if ((f->spe == 'x' && f->arg[0] != '0') || f->spe == 'p')
			{
				pf_ft_buf('0', f);
				pf_ft_buf('x', f);
			}
			else if (f->spe == 'X' && f->arg[0] != '0')
			{
				pf_ft_buf('0', f);
				pf_ft_buf('X', f);
			}
			else if ((f->spe == 'o' || f->spe == 'O') &&
				f->fla[0] <= pf_ft_strlen(f->arg))
				pf_ft_buf('0', f);
			else if ((f->spe == 'o' || f->spe == 'O') && f->fla[0] == -1)
				pf_ft_buf('0', f);
		}
	}
}

/*
**					space ou + : d / D / i && #
** 		Ajoute un espace si flag ' ' OU un signe +/- si flag '+'
** 		appelle la fonction pf_ft_sharp
*/

void	pf_ft_space_plus_sharp(t_flag *f)
{
	if (f->fla[5] == 1 || f->fla[6] == 1)
	{
		if (f->spe == 'd' || f->spe == 'D' || f->spe == 'i')
		{
			if (f->fla[6] == 1 && f->fla[5] == 0 && f->sign != '-')
				pf_ft_buf(' ', f);
			if (f->fla[5] == 1 && pf_ft_isdigit(f->arg[0]) && f->sign == '+')
				pf_ft_buf('+', f);
		}
	}
	if (f->sign == '-')
		pf_ft_buf('-', f);
	pf_ft_sharp(f);
}
