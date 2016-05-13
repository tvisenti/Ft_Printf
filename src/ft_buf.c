/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:36:02 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 18:34:51 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 				Initialise g_buf avec des \0
*/

void				ft_bufset(void)
{
	int				n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

/*
** 				Affiche g_buf jusqu'à g_i
*/

void				ft_display(t_flag *f)
{
	f->ret += write(1, g_buf, g_i);
	ft_bufset();
}

/*
** 				Affiche (null)
*/

void				ft_buf_null(t_flag *f)
{
	static char		str[6] = "(null)";
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_buf(str[i], f);
		i++;
	}
}

/*
** 			Ajoute dans g_buf jusqu'à 4095 char et affiche si full
*/

void				ft_buf(char c, t_flag *f)
{
	g_buf[g_i] = c;
	g_i++;
	if (g_i == 4096)
		ft_display(f);
}
