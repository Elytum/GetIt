/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 01:35:40 by achazal           #+#    #+#             */
/*   Updated: 2015/01/18 01:35:40 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_matrix		ft_normalm(void)
{
	t_matrix	m;

	m.a = 1;
	m.b = 0;
	m.c = 0;
	m.d = 0;
	m.e = 0;
	m.f = 1;
	m.g = 0;
	m.h = 0;
	m.i = 0;
	m.j = 0;
	m.k = 1;
	m.l = 0;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	return (m);
}