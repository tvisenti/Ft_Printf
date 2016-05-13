/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:24:50 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 18:26:20 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** Initialise le tableau des flags, check les flags corrects, ajoute
** la precision et la width si il y en a et mets le f->fla[n] a 1 pour
** le flag correspondant.
*/

int			ft_check(t_flag *f)
{
	ft_check_initialize(f);
	while (f->frmt[f->ndx] == '#' || f->frmt[f->ndx] == '0'
		|| f->frmt[f->ndx] == '-' || f->frmt[f->ndx] == '+'
		|| f->frmt[f->ndx] == ' ' || f->frmt[f->ndx] == 'h'
		|| f->frmt[f->ndx] == 'l' || f->frmt[f->ndx] == 'j'
		|| f->frmt[f->ndx] == 'z' || f->frmt[f->ndx] == '.'
		|| ft_isdigit(f->frmt[f->ndx]))
	{
		ft_check_flag(f);
		ft_check_width(f);
		ft_check_precision(f);
		ft_check_modifier(f);
	}
	if (f->ndx == ft_strlen(f->frmt))
		return (-1);
	return (0);
}

void		ft_check_flag(t_flag *f)
{
	if (f->frmt[f->ndx] == '#' || f->frmt[f->ndx] == '0'
		|| f->frmt[f->ndx] == '-' || f->frmt[f->ndx] == '+'
		|| f->frmt[f->ndx] == ' ')
	{
		if (f->frmt[f->ndx] == '#')
			f->fla[2] = 1;
		if (f->frmt[f->ndx] == '0')
			f->fla[3] = 1;
		if (f->frmt[f->ndx] == '-')
			f->fla[4] = 1;
		if (f->frmt[f->ndx] == '+')
			f->fla[5] = 1;
		if (f->frmt[f->ndx] == ' ')
			f->fla[6] = 1;
		f->ndx++;
	}
}

void		ft_check_width(t_flag *f)
{
	int		i;
	char	*str;

	i = f->ndx;
	if (ft_isdigit(f->frmt[f->ndx]) && f->frmt[f->ndx] != '0')
	{
		while (ft_isdigit(f->frmt[f->ndx]))
		{
			f->ndx++;
		}
		if (f->ndx - i > 0)
		{
			f->fla[1] = 0;
			str = ft_strsub(f->frmt, i, f->ndx - i);
			f->fla[1] = ft_atoi((const char*)str);
			free(str);
		}
	}
}

void		ft_check_precision(t_flag *f)
{
	int		i;
	char	*str;

	if (f->frmt[f->ndx] == '.')
	{
		f->fla[0] = 0;
		i = ++f->ndx;
		while (ft_isdigit(f->frmt[f->ndx]))
			f->ndx++;
		if (f->ndx - i > 0)
		{
			str = ft_strsub(f->frmt, i, f->ndx - i);
			f->fla[0] = ft_atoi((const char*)str);
			free(str);
		}
		if (f->fla[0] == 0)
			f->fla[0] = -1;
	}
}

void		ft_check_modifier(t_flag *f)
{
	while (f->frmt[f->ndx] == 'h' || f->frmt[f->ndx] == 'l' ||
		f->frmt[f->ndx] == 'j' || f->frmt[f->ndx] == 'z')
	{
		if (f->frmt[f->ndx] == 'h' && f->frmt[f->ndx + 1] == 'h')
		{
			f->fla[7] = 1;
			f->ndx++;
		}
		else if (f->frmt[f->ndx] == 'h')
			f->fla[8] = 1;
		if (f->frmt[f->ndx] == 'l' && f->frmt[f->ndx + 1] == 'l')
		{
			f->fla[9] = 1;
			f->ndx++;
		}
		else if (f->frmt[f->ndx] == 'l')
			f->fla[10] = 1;
		if (f->frmt[f->ndx] == 'j')
			f->fla[11] = 1;
		if (f->frmt[f->ndx] == 'z')
			f->fla[12] = 1;
		f->ndx++;
	}
}
