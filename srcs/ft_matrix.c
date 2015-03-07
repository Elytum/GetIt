/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 15:58:04 by achazal           #+#    #+#             */
/*   Updated: 2014/11/19 16:14:25 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix		ft_toscale(float a, float b, float c)
{
	t_matrix	m;

	m.a = a;
	m.b = 0;
	m.c = 0;
	m.d = 0;
	m.e = 0;
	m.f = b;
	m.g = 0;
	m.h = 0;
	m.i = 0;
	m.j = 0;
	m.k = c;
	m.l = 0;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	return (m);
}

t_matrix		ft_translation(float a, float b, float c)
{
	t_matrix	m;

	m.a = 1;
	m.b = 0;
	m.c = 0;
	m.d = a;
	m.e = 0;
	m.f = 1;
	m.g = 0;
	m.h = b;
	m.i = 0;
	m.j = 0;
	m.k = 1;
	m.l = c;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	return (m);
}

t_matrix		ft_rotate_x(float beta)
{
	t_matrix	m;

	m.a = 1;
	m.b = 0;
	m.c = 0;
	m.d = 0;
	m.e = 0;
	m.f = cos(beta);
	m.g = -sin(beta);
	m.h = 0;
	m.i = 0;
	m.j = sin(beta);
	m.k = cos(beta);
	m.l = 0;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	return (m);
}

t_matrix		ft_rotate_y(float beta)
{
	t_matrix	m;

	m.a = cos(beta);
	m.b = 0;
	m.c = sin(beta);
	m.d = 0;
	m.e = 0;
	m.f = 1;
	m.g = 0;
	m.h = 0;
	m.i = -sin(beta);
	m.j = 0;
	m.k = cos(beta);
	m.l = 0;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	return (m);
}

t_matrix		ft_rotate_z(float beta)
{
	t_matrix	m;

	m.a = cos(beta);
	m.b = -sin(beta);
	m.c = 0;
	m.d = 0;
	m.e = sin(beta);
	m.f = cos(beta);
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
