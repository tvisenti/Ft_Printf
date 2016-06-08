/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:26:11 by tvisenti          #+#    #+#             */
/*   Updated: 2016/06/08 10:36:49 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*pf_ft_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	int		real_len;
	int		i;
	char	*fresh;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && (int)len >= pf_ft_wcharlen(ws[i]))
	{
		len -= pf_ft_wcharlen(ws[i]);
		real_len += pf_ft_wcharlen(ws[i]);
		i++;
	}
	fresh = pf_ft_transform_wchar_in_char(ws);
	return (pf_ft_strsub_with_free(fresh, start, real_len));
}

char		*pf_ft_strsub_with_free(char const *s, unsigned int start,
	size_t len)
{
	char	*fresh;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	fresh = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	while (len > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
		len--;
	}
	free(tmp);
	return (fresh);
}
