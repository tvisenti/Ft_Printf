/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:41:52 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 19:40:35 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 		Mets la chaine dans g_buf, affiche (null) si l'arg est null
*/

void		ft_display_arg(t_flag *f)
{
	int		i;
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->fla[10] == 1) || f->spe == 'S' ||
		(f->spe == 'c' && f->fla[10] == 1) || f->spe == 'C'))
	{
		if (f->arg != NULL)
		{
			if (f->arg[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->fla[10] == 1)))
				ft_buf('\0', f);
			len = ft_strlen(f->arg);
			while (len-- > 0)
				ft_buf(f->arg[++i], f);
		}
		else if (f->fla[0] != -1)
			ft_buf_null(f);
	}
	else
	{
		while (f->arg[++i] != '\0')
			ft_buf(f->arg[i], f);
	}
	ft_end(f);
}

/*
** 				Width - strlen(arg) : Mets des ' ' ou '0' si > 0
*/

void		ft_zero_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->fla[3] == 1 && f->fla[0] <= 0)
			ft_buf('0', f);
		else
			ft_buf(' ', f);
	}
	ft_display_arg(f);
}

/*
**			Flag '-' : Mets l'arg en premier puis mets les espaces
*/

void		ft_minus_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	ft_display_arg(f);
	while (nb_space-- > 0)
		ft_buf(' ', f);
}

/*
**			Check si la width > strlen(arg), dispatche si '-' ou pas
*/

void		ft_width_char(t_flag *f)
{
	int		i;

	i = 0;
	if (f->arg)
		i = ft_strlen(f->arg);
	if (i < f->fla[1])
	{
		if (f->fla[4] == 1)
			ft_minus_char(f);
		else
			ft_zero_char(f);
	}
	else
		ft_display_arg(f);
}
