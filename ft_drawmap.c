/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:10:55 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:10:58 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int 	ft_vectorisanumber(t_vector v)
{
	if (!(v.buffx == v.buffx && v.buffy == v.buffy) ||
		  v.buffx == INFINITY || v.buffy == INFINITY ||
		  v.buffx == -INFINITY || v.buffy == -INFINITY)
		return (0);
	// printf("Buffx : %f, buffy : %f\n", v.buffx, v.buffy);
	return (1);
}

void 	ft_drawmap(t_env *e)
{
	t_entity *ptr;

	ft_applym2w(e);
	// ft_trianglesort(e);
	ptr = e->world->entities;
	while (ptr)
	{
		if (ptr->size == 3)
		{
			if (ft_vectorisanumber(*(ptr->a)) && ft_vectorisanumber(*(ptr->b))
				&& ft_vectorisanumber(*(ptr->c)))
			{
				// ft_drawtriangle(e, ptr);
				
				// ft_drawtriangle2(e, ptr);
				
				ft_drawline(ptr->a, ptr->b, e);
				ft_drawline(ptr->c, ptr->b, e);
				ft_drawline(ptr->a, ptr->c, e);
			}
		}
		else if (ptr->size == 2)
			if (ft_vectorisanumber(*(ptr->a)) && ft_vectorisanumber(*(ptr->b)))
				ft_drawline(ptr->a, ptr->b, e);
		else if (ptr->size == 1)
			if (ft_vectorisanumber(*(ptr->a)))
				ft_put_pixel_to_screen(e, (int)ptr->a->buffx, 
					(int)ptr->a->buffy, ptr->a->color);
		ptr = ptr->next;
	}
}
