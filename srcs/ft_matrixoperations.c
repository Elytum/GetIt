/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixoperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 02:10:29 by achazal           #+#    #+#             */
/*   Updated: 2014/11/20 02:10:31 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix		ft_m_x_m(t_matrix a, t_matrix b)
{
	t_matrix	m;

	m.a = a.a * b.a + a.b * b.e + a.c * b.i + a.d * b.m;
	m.b = a.a * b.b + a.b * b.f + a.c * b.j + a.d * b.n;
	m.c = a.a * b.c + a.b * b.g + a.c * b.k + a.d * b.o;
	m.d = a.a * b.d + a.b * b.h + a.c * b.l + a.d * b.p;
	m.e = a.e * b.a + a.f * b.e + a.g * b.i + a.h * b.m;
	m.f = a.e * b.b + a.f * b.f + a.g * b.j + a.h * b.n;
	m.g = a.e * b.c + a.f * b.g + a.g * b.k + a.h * b.o;
	m.h = a.e * b.d + a.f * b.h + a.g * b.l + a.h * b.p;
	m.i = a.i * b.a + a.j * b.e + a.k * b.i + a.l * b.m;
	m.j = a.i * b.b + a.j * b.f + a.k * b.j + a.l * b.n;
	m.k = a.i * b.c + a.j * b.g + a.k * b.k + a.l * b.o;
	m.l = a.i * b.d + a.j * b.h + a.k * b.l + a.l * b.p;
	m.m = a.m * b.a + a.n * b.e + a.o * b.i + a.p * b.m;
	m.n = a.m * b.b + a.n * b.f + a.o * b.j + a.p * b.n;
	m.o = a.m * b.c + a.n * b.g + a.o * b.k + a.p * b.o;
	m.p = a.m * b.d + a.n * b.h + a.o * b.l + a.p * b.p;
	return (m);
}
