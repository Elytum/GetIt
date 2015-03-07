/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:24:13 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:24:19 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix				ft_dropmw(t_matrix o)
{
	t_matrix			m;

	m.a = o.a / o.p;
	m.b = o.b / o.p;
	m.c = o.c / o.p;
	m.d = o.d / o.p;
	m.e = o.e / o.p;
	m.f = o.f / o.p;
	m.g = o.g / o.p;
	m.h = o.h / o.p;
	m.i = o.i / o.p;
	m.j = o.j / o.p;
	m.k = o.k / o.p;
	m.l = o.l / o.p;
	m.m = o.m / o.p;
	m.n = o.n / o.p;
	m.o = o.o / o.p;
	m.p = 1;
	return (m);
}

// t_matrix				ft_lookat(t_env *e)
// {
// 	static t_matrix		m;
// 	static t_vector		f;
// 	static t_vector		s;
// 	static t_vector		u;
// 	static t_vector		eye;

// 	eye = ft_normalized(e->eye);
// 	f = ft_normalized(ft_v_l_v(e->center, eye));
// 	s = ft_normalized(ft_cross(f, e->up));
// 	u = ft_cross(s, f);
// 	m.a = s.x;
// 	m.b = s.y;
// 	m.c = s.z;
// 	m.d = -ft_dot(s, eye);
// 	m.e = u.x;
// 	m.f = u.y;
// 	m.g = u.z;
// 	m.h = -ft_dot(u, eye);
// 	m.i = -f.x;
// 	m.j = -f.y;
// 	m.k = -f.z;
// 	m.l = ft_dot(f, eye);
// 	m.p = 1.f;
// 	return (m);
// }

// t_matrix				ft_orthographic(t_env *e)
// {
// 	static t_matrix		m;
// 	static double		zrange;

// 	zrange = e->zfar - e->znear;
// 	if (!(e->zfar > e->znear))
// 		return (ft_normal());
// 	m.a = 1.f / WIDTH;
// 	m.f = 1.f / HEIGHT;
// 	m.k = -2.0 / zrange;
// 	m.l = (e->zfar + e->znear) / zrange;
// 	m.p = 1.f;
// 	return (m);
// }

// t_matrix				ft_perspective(t_env *e)
// {
// 	static t_matrix		m;
// 	static double		tanhalffovy;
// 	static float		epsilon = 1e-7f;

// 	if (!(e->zfar > e->znear) || !(e->aspect - epsilon > 0))
// 		return (ft_normal());
// 	tanhalffovy = tan(e->fovy / 2.0);
// 	m.a = 1.f / (e->aspect * tanhalffovy);
// 	m.f = 1.f / tanhalffovy;
// 	m.k = -(e->zfar + e->znear) / (e->zfar - e->znear);
// 	m.l = -(2.f * e->zfar * e->znear) / (e->zfar - e->znear);
// 	m.o = -1;
// 	return (m);
// }

t_matrix				ft_identity(void)
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
