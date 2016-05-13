/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:18:08 by tvisenti          #+#    #+#             */
/*   Updated: 2016/05/13 17:41:52 by tvisenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "./inc/ft_printf.h"
#include <locale.h>

int		main(void)
{
	int ret;

	setlocale(LC_ALL, "");
	printf("TRUE :\n");
	ret = printf("[%s]\n", "La jolie chaine.");
	printf("ret : |%d|\n", ret);
	printf("MINE :\n");
	ret = ft_printf("[%s]\n", "La jolie chaine.");
	printf("ret : |%d|\n", ret);
	return (0);
}
