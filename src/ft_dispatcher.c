/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:53:39 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 18:45:14 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**			Pointe le bon handler en fonction du spec
*/

static void		ft_initialize_specs_suite(t_spec *specs)
{
	specs[11].c = 'x';
	specs[11].ptr = &ft_handler_x;
	specs[12].c = 'X';
	specs[12].ptr = &ft_handler_wx;
	specs[13].c = 'p';
	specs[13].ptr = &ft_handler_p;
	specs[14].c = 0;
	specs[14].ptr = NULL;
}

void			ft_initialize_specs(t_spec *specs)
{
	specs[0].c = 's';
	specs[0].ptr = &ft_handler_s;
	specs[1].c = 'S';
	specs[1].ptr = &ft_handler_ws;
	specs[2].c = 'c';
	specs[2].ptr = &ft_handler_c;
	specs[3].c = 'C';
	specs[3].ptr = &ft_handler_wc;
	specs[4].c = 'd';
	specs[4].ptr = &ft_handler_d;
	specs[5].c = 'D';
	specs[5].ptr = &ft_handler_wd;
	specs[6].c = 'i';
	specs[6].ptr = &ft_handler_d;
	specs[7].c = 'o';
	specs[7].ptr = &ft_handler_o;
	specs[8].c = 'O';
	specs[8].ptr = &ft_handler_wo;
	specs[9].c = 'u';
	specs[9].ptr = &ft_handler_u;
	specs[10].c = 'U';
	specs[10].ptr = &ft_handler_wu;
	ft_initialize_specs_suite(specs);
}

/*
**			Initialise le tableau
*/

void			ft_check_initialize(t_flag *f)
{
	int		i;

	i = 0;
	while (i < 14)
	{
		f->fla[i] = 0;
		i++;
	}
	f->ndx = 0;
}

/*
** 		Check les flags, retourne le bon handler en fonction du spec
*/

int				ft_dispatcher(t_flag *f, va_list *ap)
{
	t_spec	specs[16];
	int		j;

	if (ft_check(f) == -1)
		return (-1);
	ft_initialize_specs(specs);
	f->arg = NULL;
	f->warg = NULL;
	j = 0;
	f->spe = f->frmt[f->ndx];
	while (specs[j].c != f->spe && specs[j].c != 0)
		j++;
	if (specs[j].c == 0)
		return (ft_handler_undefined(f));
	return (specs[j].ptr(f, ap));
}
