/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:22:17 by gpinchon          #+#    #+#             */
/*   Updated: 2015/01/06 22:49:52 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"


t_entity *ft_parse_entities(t_vector ***map)
{
	t_entity *entities;
	int size;
	int snext;
	int ssnext;
	int spast;
	int x;
	int y;
	int done;

	entities = NULL;
	y = 0;
	while (map[y])
	{
		x = 0;
		size = ft_lenline(map[y]);
		snext = ft_lenline(map[y + 1]);
		if (snext != -1)
			ssnext = ft_lenline(map[y + 2]);
		else
			ssnext = -1;
		if (y > 0)
			spast = ft_lenline(map[y - 1]);
		else
			spast = 0;
		while (map[y][x])
		{
			done = 0;
			// printf("Size = %i, snext = %i\n", size, snext);
			if (x > 0 && snext >= x - 1)
			{
				//TRIANGLES
				// printf("Setting up triangles : x = %i, y = %i\n", x, y);
				// x x  ++  x
				//   x  ++  x x
				if (snext > x)
				{
					if (snext > x && map[y + 1][x]->exist && map[y][x - 1]->exist && map[y][x]->exist)
					{
						ft_entities_add(&entities, ft_new3entity(map[y + 1][x], map[y][x - 1], map[y][x]));
						done++;
					}
					if (map[y + 1][x - 1]->exist && map[y][x - 1]->exist && map[y + 1][x]->exist)
					{
						ft_entities_add(&entities, ft_new3entity(map[y + 1][x - 1], map[y][x - 1], map[y + 1][x]));
						done++;
					}
				}
				if (done == 0 && snext > x - 1)
				{
					// x x ||   x
					// x   || x x
					if (map[y + 1][x - 1]->exist && map[y][x - 1]->exist && map[y][x]->exist)
					{
						ft_entities_add(&entities, ft_new3entity(map[y + 1][x - 1], map[y][x - 1], map[y][x]));
						done++;
					}
					if (snext > x && map[y + 1][x - 1]->exist && map[y + 1][x]->exist && map[y][x]->exist)
					{
						ft_entities_add(&entities, ft_new3entity(map[y + 1][x - 1], map[y + 1][x], map[y][x]));
						done++;
					}
				}
				//DIAGONALES
				if (done == 0 && snext > x - 1)
				{
					if (map[y][x]->exist && map[y + 1][x - 1]->exist)
					{
						ft_entities_add(&entities, ft_new2entity(map[y + 1][x - 1], map[y][x]));
						done++;
					}
					else if(snext > x && map[y][x - 1]->exist && map[y + 1][x]->exist)
					{
						ft_entities_add(&entities, ft_new2entity(map[y][x - 1], map[y + 1][x]));
						done++;
					}
				}
			}
			if (x > 0)
			{
				//TRAIT HAUT
				if (done == 0 && map[y][x - 1]->exist && map[y][x]->exist && (y == 0 || spast < x || (map[y - 1][x] && (!map[y - 1][x]->exist && !map[y - 1][x - 1]->exist))))
				{
					ft_entities_add(&entities, ft_new2entity(map[y][x - 1], map[y][x]));
					done++;
				}
				//TRAIT BAS
				if (done == 0 && snext >= size && map[y + 1][x - 1]->exist && map[y + 1][x]->exist && (ssnext == -1 || ssnext < x || (!map[y + 1][x - 1]->exist && !map[y + 1][x]->exist)))
				{
					ft_entities_add(&entities, ft_new2entity(map[y + 1][x - 1], map[y + 1][x]));
					done++;
				}
				//TRAIT GAUCHE
				if (done == 0 && snext >= size - 1 && map[y][x - 1]->exist && map[y + 1][x - 1]->exist)
				{
					ft_entities_add(&entities, ft_new2entity(map[y][x - 1], map[y + 1][x - 1]));
					done++;
				}
			}
			//TRAIT DROIT
			if (done == 0 && snext >= size && map[y][x]->exist && map[y + 1][x]->exist)
			{
				ft_entities_add(&entities, ft_new2entity(map[y][x], map[y + 1][x]));
				done++;
			}
			//POINTS
			if (done == 0 && map[y][x]->exist)
				ft_entities_add(&entities, ft_new1entity(map[y][x]));
			else if (done == 0 && x > 0 && map[y][x - 1]->exist)
				ft_entities_add(&entities, ft_new1entity(map[y][x - 1]));
			else if (done == 0 && snext > x && map[y + 1][x]->exist)
				ft_entities_add(&entities, ft_new1entity(map[y + 1][x]));
			else if (done == 0 && x > 0 && snext > x - 1 && map[y + 1][x - 1]->exist)
				ft_entities_add(&entities, ft_new1entity(map[y + 1][x - 1]));
			x++;
		}
		y++;
	}
	return (entities);
}

// void	ft_calculatecenter(t_entity *ptr)
// {
// 	if (ptr->size == 1)
// 	{
// 		ptr->center.x = ptr->a->x;
// 		ptr->center.x = ptr->a->y;
// 	}
// 	else if (ptr->size == 2)
// 	{
// 		ptr->center.x = (ptr->a->x + ptr->b->x) / 2;
// 		ptr->center.x = (ptr->a->y + ptr->b->y) / 2;
// 	}
// 	else if (ptr->size == 3)
// 	{
// 		ptr->center.x = (ptr->a->x + ptr->b->x + ptr->c->x) / 3;
// 		ptr->center.x = (ptr->a->y + ptr->b->y + ptr->c->y) / 3;
// 	}
// }
