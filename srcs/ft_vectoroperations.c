/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectoroperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:19:07 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 19:19:07 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector		ft_v_x_v(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x * b.x;
	v.y = a.y * b.y;
	v.z = a.z * b.z;
	v.buffx = 0;
	v.buffy = 0;
	return (v);
}

t_vector		ft_v_l_v(t_vector a, t_vector b)
{
	t_vector	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	v.p = a.p - b.p;
	v.buffx = 0;
	v.buffy = 0;
	v.color = a.color + (b.color - a.color) / 2;
	return (v);
}

t_vector		ft_normalized(t_vector v)
{
	ft_normalize(&v);
	return (v);
}

void			ft_normalize(t_vector *v)
{
	float norm;

	norm = sqrt(pow(v->x, 2) + pow(v->y, 2));
	norm = sqrt(pow(norm, 2) + pow(v->z, 2));
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
	v->p = 1;

	// double v;

	// v = sqrt((*a).x * (*a).x + (*a).y * (*a).y + (*a).z * (*a).z);
	// (*a).x = (*a).x * v;
	// (*a).y = (*a).y * v;
	// (*a).z = (*a).z * v;
}

float			ft_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
