/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoroperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:22:01 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 19:22:02 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector		ft_cross(t_vector x, t_vector y)
{
	t_vector v;

	v.x = x.y * y.z - x.z * y.y,
	v.y = x.z * y.x - x.x * y.z,
	v.z = x.x * y.y - x.y * y.x;
	v.p = 1;
	return (v);
}

t_vector		ft_m_x_v(t_matrix m, t_vector o)
{
	t_vector	v;

	v.x = m.a * o.x + m.b * o.y + m.c * o.z + m.d * o.p;
	v.y = m.e * o.x + m.f * o.y + m.g * o.z + m.h * o.p;
	v.z = m.i * o.x + m.j * o.y + m.k * o.z + m.l * o.p;
	v.p = m.m * o.x + m.n * o.y + m.o * o.z + m.p * o.p;
	v.buffx = 0;
	v.buffy = 0;
	v.color = o.color;
	return (v);
}

void			ft_dropvw(t_vector *v)
{
	float divisor;

	divisor = v->p + EPSILON;
	v->x /= divisor;
	v->y /= divisor;
	v->z /= divisor;
	v->p = 1;
}
