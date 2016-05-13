/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:44:49 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 19:17:44 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**					0xxxxxxx // 0x00
**	Aucune action
** 					110xxxxx 10xxxxxx // 0xC0 0x80
** 	Je deplace de 6 sur la droite et j'ajoute 11000000
** 	Je filtre par 111111 et j'ajoute 10000000
** 					1110xxxx 10xxxxxx 10xxxxxx // 0xE0 0x80 0x80
**	Je deplace de 12 sur la droite et j'ajoute 11100000
**	Je deplace de 6, je filtre par 111111 et j'ajoute 10000000
**	Je filtre par 111111 et j'ajoute 10000000
** 					11110xxx 10xxxxxx 10xxxxxx 10xxxxxx // 0xF0 0x80 0x80 0x80
**	Je deplace de 18 sur la droite et j'ajoute 11110000
**	Je deplace de 12 sur la droite, je filtre par 111111 et j'ajoute 10000000
**	Je deplace de 6 sur la droite, je filtre par 111111 et j'ajoute 10000000
**	Je filtre par 111111 et j'ajoute 10000000
*/

int		ft_putwchar_in_char(wchar_t wchar, char *fresh, int i)
{
	int		size;

	size = ft_wcharlen(wchar);
	if (size == 1)
		fresh[i++] = wchar;
	else if (size == 2)
	{
		fresh[i++] = (wchar >> 6) + 0xC0;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		fresh[i++] = (wchar >> 12) + 0xE0;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		fresh[i++] = (wchar >> 18) + 0xF0;
		fresh[i++] = ((wchar >> 12) & 0x3F) + 0x80;
		fresh[i++] = ((wchar >> 6) & 0x3F) + 0x80;
		fresh[i++] = (wchar & 0x3F) + 0x80;
	}
	return (i);
}

/*
**		Transforme les wchar en char
*/

char	*ft_transform_wchar_in_char(wchar_t *ws)
{
	char	*fresh;
	int		i;
	int		k;
	int		len;

	if (!ws)
		return (0);
	i = 0;
	k = 0;
	len = ft_wbytelen(ws);
	fresh = (char*)malloc(sizeof(char) * len);
	fresh[len] = '\0';
	while (ws[k])
	{
		i = ft_putwchar_in_char(ws[k], fresh, i);
		k++;
	}
	return (fresh);
}
