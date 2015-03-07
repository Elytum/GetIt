/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:37:19 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 20:37:19 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix				ft_create_view_m(t_env *e)
{
	t_matrix	m;
	t_matrix	p;
	t_vector	dir;
	t_vector	right;
	t_vector	u;

	dir = ft_normalized(ft_v_l_v(e->eye, e->center));
	right = ft_normalized(ft_cross(dir, e->up));
	u = ft_normalized(ft_cross(right, dir));
	p = ft_translation(-e->center.x, -e->center.y, -e->center.z);
	m = ft_identity();
	m.a = right.x;
	m.b = right.y;
	m.c = right.z;
	m.d = 0;
	m.e = u.x;
	m.f = u.y;
	m.g = u.z;
	m.h = 0;
	m.i = dir.x;
	m.j = dir.y;
	m.k = dir.z;
	m.l = 0;
	m.m = 0;
	m.n = 0;
	m.o = 0;
	m.p = 1;
	// m.a = right.x;
	// m.e = right.y;
	// m.i = right.z;
	// m.b = u.x;
	// m.f = u.y;
	// m.j = u.z;
	// m.c = dir.x;
	// m.g = dir.y;
	// m.k = dir.z;
	return (ft_m_x_m(p, m));
}

t_matrix				ft_perspective(t_env *e)
{
	t_matrix	m;
	float		aspect;
	float		fd;

	aspect = (float)WIDTH / (float)HEIGHT;
	fd = 1 / tan(e->fov / 2 * M_PI / 180);
	m = ft_identity();
	m.a = fd / e->aspect;
	m.f = fd;
	m.k = - ((e->zfar + e->znear) / (e->zfar - e->znear));
	m.l = -1;
	m.o = - (e->zfar * e->znear) / (e->zfar - e->znear);
	m.p = 0;

	// m.a = fd / e->aspect;
	// m.f = fd;
	// m.k = - ((e->zfar + e->znear) / (e->zfar - e->znear));
	// m.l = - (e->zfar * e->znear) / (e->zfar - e->znear);
	// m.o = - 1;
	return (m);
}

/*

a b c d
e f g h
i j k l
m n o p

*/

void					ft_rasterize(t_vector *v, t_matrix worldviewproj)
{
	t_vector 			vector;
	static int i = 0;

	// vector.x = v->x;
	// vector.y = v->y;
	// vector.z = v->z;
	// vector.p = v->p;
	// ft_dropvw(&vector);
	if (i % 1000 == 0)
	{
		printf("\nworldviewproj = :\n");
		ft_putmatrix(worldviewproj);
		printf("\n");
	}
	vector = ft_m_x_v(worldviewproj, *v);
	ft_dropvw(&vector);
	(*v).buffx = WIDTH / 2 + vector.x / sqrt(vector.z);
	(*v).buffy = HEIGHT / 2 + vector.y / sqrt(vector.z);
	// printf("X = %f, Y = %f\n", (*v).x, (*v).y);
	// printf("Buffx = %f, buffy = %f\n", (*v).buffx, (*v).buffy);
	i++;
}
/*
	// ft_dropvw(v);
	// ft_dropvw(tmp);
	// (*v).buffx = (*tmp).x;
	// (*v).buffy = (*tmp).y;
*/

void					ft_applym2w(t_env *e)
{
	t_matrix		worldviewproj;
	t_object		*obj;
	t_vector		tmp;
	int			x;
	int			y;

	obj = e->world;
	worldviewproj = obj->matrix;
	// worldviewproj = ft_m_x_m(obj->matrix, ft_create_view_m(e));
	// worldviewproj = ft_m_x_m(worldviewproj, ft_perspective(e));

	// worldviewproj = ft_m_x_m(ft_create_view_m(e), ft_perspective(e));
	// worldviewproj = ft_m_x_m(ft_perspective(e), ft_create_view_m(e));

	// ft_putmatrix(worldviewproj);
	// worldviewproj = ft_m_x_m(worldviewproj, obj->matrix);
	
	// worldviewproj = ft_m_x_m(obj->matrix, ft_perspective(e));
	// worldviewproj = ft_m_x_m(worldviewproj, ft_create_view_m(e));
	// worldviewproj = ft_m_x_m(ft_create_view_m(e), ft_perspective(e));
	// worldviewproj = ft_m_x_m(obj->matrix, worldviewproj);
	y = 0;
	while (obj->map[y])
	{
		x = 0;
		while (obj->map[y][x])
		{
			if (obj->map[y][x]->exist)
			{
				// ft_dropvw(obj->map[y][x]);
				// ft_normalize(obj->map[y][x]);

				// ft_rasterize(obj->map[y][x], worldviewproj);
				// ft_rasterize(obj->map[y][x], worldviewproj);

				tmp = ft_m_x_v(worldviewproj, *obj->map[y][x]);
				obj->map[y][x]->buffx = tmp.x;
				obj->map[y][x]->buffy = tmp.y;
			}
			x++;
		}
		y++;
	}
}
/*
	// m = ft_m_x_m(obj->matrix, ft_m_x_m(ft_lookat(e), ft_perspective(e)));
	// m = ft_m_x_m(obj->matrix, ft_m_x_m(ft_perspective(e), ft_lookat(e)));

	// m = ft_m_x_m(ft_perspective(e), ft_m_x_m(obj->matrix, ft_lookat(e)));
	// m = ft_m_x_m(ft_perspective(e), ft_m_x_m(ft_lookat(e), obj->matrix));

	// m = ft_m_x_m(ft_lookat(e), ft_m_x_m(ft_perspective(e), obj->matrix));

	// m = ft_view_matrix(e, obj->matrix);

	// m = ft_m_x_m(ft_lookat(e), ft_m_x_m(obj->matrix, ft_perspective(e)));

	// m = obj->matrix;
				// m = ft_perspective(e);
				// m = ft_m_x_m(ft_create_view_m(e, obj->map[y][x]), m);
				// m = ft_m_x_m(ft_perspective(e), m);
				// m = ft_m_x_m(m, ft_perspective(e));
				// m = ft_m_x_m(m, obj->matrix);
				// m = ft_m_x_m(obj->matrix, m);


				// tmp = ft_m_x_v(m, *(obj->map[y][x]));
				// ft_dropvw(&tmp);
				// tmp = ft_m_x_v(ft_translation(WIDTH / 2, HEIGHT / 2, 0), tmp);
				// tmp = ft_m_x_v(ft_toscale(WIDTH / 2, HEIGHT / 2, 1), tmp);
*/

t_object				*ft_parsing(char *path)
{
	t_object		*object;

	object = (t_object *)ft_memalloc(sizeof(t_object));
	ft_putstr("Beginning parsing...\n");
	if (!(object->map = parser(path)))
		return (NULL);
	if (!(object->entities = ft_parse_entities(object->map)))
		return (NULL);
	object->matrix = ft_toscale(25, 25, 1);
	ft_putstr("Parsing done\n");
	return (object);
}
