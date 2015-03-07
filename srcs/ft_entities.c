/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entities.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:21:53 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 20:21:55 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_entity	*ft_new3entity(t_vector *a, t_vector *b, t_vector *c)
{
	t_entity *newe;

	newe = (t_entity *)ft_memalloc(sizeof(t_entity));
	newe->size = 3;
	newe->a = a;
	newe->b = b;
	newe->c = c;
	return (newe);
}

t_entity	*ft_new2entity(t_vector *a, t_vector *b)
{
	t_entity *newe;

	newe = (t_entity *)ft_memalloc(sizeof(t_entity));
	newe->size = 2;
	newe->a = a;
	newe->b = b;
	return (newe);
}

t_entity	*ft_new1entity(t_vector *a)
{
	t_entity *newe;

	newe = (t_entity *)ft_memalloc(sizeof(t_entity));
	newe->size = 1;
	newe->a = a;
	return (newe);
}

void		ft_entities_add(t_entity **alst, t_entity *newe)
{
	if (!alst)
		return ;
	if (newe)
	{
		if (*alst)
			newe->next = *alst;
		*alst = newe;
	}
}
