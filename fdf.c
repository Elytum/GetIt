/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:13:12 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 20:13:15 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int						ft_updatekey(int keycode, t_env *e)
{
	t_matrix		*m;

	printf("Keycode = %i\n", keycode);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65464 || keycode == 65461 || keycode == 65460 ||
			keycode == 65462 || keycode == 65463 || keycode == 65465)
		ft_updateeye(e, keycode);
	else if (keycode == 65364 || keycode == 65362 || keycode == 65363 ||
			keycode == 65361)
		ft_translateworld(e, keycode);
	else if (keycode == 121 || keycode == 117 || keycode == 104 ||
			keycode == 106 || keycode == 110 || keycode == 109)
		ft_rotateworld(e, keycode);
	else if (keycode == 61 || keycode == 45 || keycode == 48 || keycode == 57 ||
			keycode == 53 || keycode == 54 || keycode == 55 || keycode == 56)
		ft_scaleworld(e, keycode);
	else if (keycode == 119 || keycode == 115 || keycode == 97 ||
			keycode == 100 || keycode == 113 || keycode == 101)
		ft_updatecenter(e, keycode);
	e->refresh = 1;
	return (keycode);
}

int						ft_initmlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putstr("Error : mlx not found.\n");
		return (0);
	}
	if (!(e->win = mlx_new_window(e->mlx, e->width, e->height, "Fdf")))
	{
		ft_putstr("Error : mlx not found.\n");
		return (0);
	}
	return (1);
}

/*t_vector **generatetriangle(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	t_vector **triangle;
	// t_object *world;
	// t_entity *cube;
	// t_vector *v0;
	// t_vector *v1;
	// t_vector *v2;
	// t_vector ***map;

	// world = (t_object *)ft_memalloc(sizeof(t_object));
	// cube = (t_entity *)ft_memalloc(sizeof(t_entity));
	// map = (t_vector ***)ft_memalloc(sizeof(t_vector **));
	// map[0] = (t_vector **)ft_memalloc(sizeof(t_vector *) * 4);
	
	// world->entities = cube;
	// world->map = map;
	triangle = (t_vector **)ft_memalloc(sizeof(t_vector *) * 4);
	v0 = (t_vector *)ft_memalloc(sizeof(t_vector));
	v1 = (t_vector *)ft_memalloc(sizeof(t_vector));
	v2 = (t_vector *)ft_memalloc(sizeof(t_vector));
	v0->exist = 1;
	v1->exist = 1;
	v2->exist = 1;
	v0->p = 1.0;
	v1->p = 1.0;
	v2->p = 1.0;

	v0->x = a;
	v0->y = b;
	v0->z = c;
	v0->color = 0xFF0000;
	v1->x = d;
	v1->y = e;
	v1->z = f;
	v1->color = 0xFF0000;
	v2->x = g;
	v2->y = h;
	v2->z = i;
	v2->color = 0xFF0000;


	// ft_entities_add(&triangle, ft_new3entity(v0, v1, v2));
	triangle[0] = v0;
	triangle[1] = v1;
	triangle[2] = v2;
	triangle[3] = NULL;
	return (triangle);
}

t_object *generatecube(void)
{
	t_object *world;
	t_entity *cube;
	t_vector ***map;

	world = (t_object *)ft_memalloc(sizeof(t_object));
	cube = (t_entity *)ft_memalloc(sizeof(t_entity));
	map = (t_vector ***)ft_memalloc(sizeof(t_vector **));
	map[0] = generatetriangle(0, 0, 0, 1, 0, 0, 0, 1, 0);
	map[1] = generatetriangle(0, 0, 0, 0, 1, 0, 0, 0, 1);
}*/

int						ft_initworld(t_env *e, char *path)
{
	if (!(e->world = ft_parsing(path)))
		return (0);
	// e->world = generatecube();
	e->world->smatrix = ft_normalm();
	e->world->tmatrix = ft_normalm();
	e->world->rmatrix = ft_normalm();
	e->world->matrix = ft_normalm();
	return (1);
}

int						ft_initenv(t_env *e, char *path)
{
	
	if (!ft_initworld(e, path))
		return (0);
	e->maxlinep2 = sqrt(HEIGHT * HEIGHT + WIDTH * WIDTH);
	printf("maxlinep2 = %i\n", e->maxlinep2);
	e->width = WIDTH;
	e->height = HEIGHT;
	e->refresh = 1;
	e->center.x = 0.f;
	e->center.y = 0.f;
	e->center.z = 0.f;
	e->center.p = 1.f;
	e->eye.x = 1.f;
	e->eye.y = 1.f;
	e->eye.z = 1.f;
	e->eye.p = 1.f;
	ft_normalize(&e->eye);
	e->up.x = 0.f;
	e->up.y = 1.f;
	e->up.z = 0.f;
	e->up.p = 1.f;
	ft_normalize(&e->up);
	e->aspect = ((float)WIDTH) / ((float)HEIGHT);
	e->zfar = 100.f;
	e->znear = 1.f;
	e->fov = 45.f;
	if (!ft_initmlx(e))
		return (0);
	return (1);
}

int						main(int ac, char **av)
{
	t_env				*e;

	if (ac != 2)
	{
		printf("Map inputs invalid, valid format : ./fdf [path]\n");
		return (0);
	}
	if (!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putstr("Malloc error\n");
		return (0);
	}
	if (!ft_initenv(e, *(av + 1)))
		return (0);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 3, ft_updatekey, e);
	mlx_loop_hook(e->mlx, ft_refresh, e);
	mlx_loop(e->mlx);
	return (0);
}
