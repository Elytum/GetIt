/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:14:25 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 22:16:14 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void					ft_apply_m_to_obj(t_env *e, t_matrix matrix, char kind)
{
	t_object		*obj;
	t_vector		tmp;

	obj = e->world;
	while (obj)
	{
		if (kind == TRANSLATE)
			obj->tmatrix = ft_m_x_m(matrix, obj->tmatrix);
		else if (kind == SCALE)
			obj->smatrix = ft_m_x_m(matrix, obj->smatrix);
		else if (kind == ROTATE)
			obj->rmatrix = ft_m_x_m(matrix, obj->rmatrix);
		if (kind == TRANSLATE || kind == SCALE || kind == ROTATE)
		{
			obj->matrix = ft_m_x_m(ft_m_x_m(obj->tmatrix, obj->rmatrix),
				obj->smatrix);
			// obj->matrix = ft_m_x_m(ft_m_x_m(obj->smatrix, obj->rmatrix),
				// obj->tmatrix);
		}
		obj = obj->next;
	}
}

void					ft_recenter(t_vector ****map)
{
	t_vector	***ptr;
	size_t		maxy;
	size_t		maxx;
	size_t		y;
	size_t		x;

	ptr = *map;
	maxy = 0;
	while (ptr[maxy])
		maxy++;
	y = 0;
	while (ptr[y])
	{
		maxx = 0;
		while (ptr[y][maxx])
			maxx++;
		x = 0;
		while (ptr[y][x])
		{
			ptr[y][x]->x -= maxx / 2;
			ptr[y][x]->y -= maxy / 2;
			x++;
		}
		y++;
	}
}
