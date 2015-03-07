/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtriangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:12:30 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:12:36 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_edge				edge(int color1, int x1, int y1, int color2, int x2, int y2)
{
	t_edge edge;

	if(y1 < y2)
	{
		edge.color1 = color1;
		edge.x1 = x1;
		edge.y1 = y1;
		edge.color2 = color2;
		edge.x2 = x2;
		edge.y2 = y2;
	}
	else
	{
		edge.color1 = color2;
		edge.x1 = x2;
		edge.y1 = y2;
		edge.color2 = color1;
		edge.x2 = x1;
		edge.y2 = y1;
	}
	return (edge);
}

t_span				newspan(int color1, int x1, int color2, int x2)
{
	t_span	span;

	if(x1 < x2)
	{
		span.color1 = color1;
		span.x1 = x1;
		span.color2 = color2;
		span.x2 = x2;
	}
	else
	{
		span.color1 = color2;
		span.x1 = x2;
		span.color2 = color1;
		span.x2 = x1;
	}
	return (span);
}

void				drawspan(t_env *e, t_span span, int y)
{
	static int		xdiff;
	static int		colordiff;
	static float	factor;
	static float	factorStep;
	static int		x;

	xdiff = span.x2 - span.x1;
	if (xdiff == 0)
		return ;
	colordiff = span.color2 - span.color1;
	factor = 0.0f;
	factorStep = 1.0f / (float)xdiff;
	x = span.x1;
	while (x < span.x2)
	{
		ft_put_pixel_to_screen(e, x, y, span.color1 + (colordiff * factor));
		factor += factorStep;
		x++;
	}
}

void				drawspansBetweenedges(t_env *e, t_edge e1, t_edge e2)
{
	float	e1ydiff;
	float	e2ydiff;
	float	e1xdiff;
	float	e2xdiff;
	int		e1colordiff;
	int		e2colordiff;
	float	factor1;
	float	factorStep1;
	float	factor2;
	float	factorStep2;
	int		y;
	t_span	span;

	e1ydiff = (float)(e1.y2 - e1.y1);
	e2ydiff = (float)(e2.y2 - e2.y1);
	e1xdiff = (float)(e1.x2 - e1.x1);
	e2xdiff = (float)(e2.x2 - e2.x1);
	if(e1ydiff == 0.0f)
		return;
	if(e2ydiff == 0.0f)
		return;
	e1colordiff = (e1.color2 - e1.color1);
	e2colordiff = (e2.color2 - e2.color1);
	factor1 = (float)(e2.y1 - e1.y1) / e1ydiff;
	factorStep1 = 1.0f / e1ydiff;
	factor2 = 0.0f;
	factorStep2 = 1.0f / e2ydiff;
	y = e2.y1;
	while (y < e2.y2)
	{
		span = newspan(e1.color1 + (e1colordiff * factor1),
		e1.x1 + (int)(e1xdiff * factor1),
		e2.color1 + (e2colordiff * factor2),
		e2.x1 + (int)(e2xdiff * factor2));
		drawspan(e, span, y);
		factor1 += factorStep1;
		factor2 += factorStep2;
		y++;
	}
}

void ft_drawtriangle(t_env *e, t_entity *t)
{
	int maxlength;
	int longedge;
	int i;
	t_edge edges[3];
	int length;
	int shortedge1;
	int shortedge2;

	if ((t->a->buffx < -WIDTH * 0.2 || t->a->buffx > WIDTH * 1.2 || t->a->buffy < -HEIGHT * 0.2 || t->a->buffy > HEIGHT * 1.2) &&
		(t->b->buffx < -WIDTH * 0.2 || t->b->buffx > WIDTH * 1.2 || t->b->buffy < -HEIGHT * 0.2 || t->b->buffy > HEIGHT * 1.2) &&
		(t->c->buffx < -WIDTH * 0.2 || t->c->buffx > WIDTH * 1.2 || t->c->buffy < -HEIGHT * 0.2 || t->c->buffy > HEIGHT * 1.2))
		return ;
	edges[0] = edge(t->a->color, (int)t->a->buffx, (int)t->a->buffy, t->b->color, \
		(int)t->b->buffx, (int)t->b->buffy);
	edges[1] = edge(t->b->color, (int)t->b->buffx, (int)t->b->buffy, t->c->color, \
		(int)t->c->buffx, (int)t->c->buffy);
	edges[2] = edge(t->c->color, (int)t->c->buffx, (int)t->c->buffy, t->a->color, \
		(int)t->a->buffx, (int)t->a->buffy);
	maxlength = 0;
	longedge = 0;
	i = 0;
	while(i < 3)
	{
		length = edges[i].y2 - edges[i].y1;
		if(length > maxlength)
		{
			maxlength = length;
			longedge = i;
		}
		i++;
	}
	shortedge1 = (longedge + 1) % 3;
	shortedge2 = (longedge + 2) % 3;
	drawspansBetweenedges(e, edges[longedge], edges[shortedge1]);
	drawspansBetweenedges(e, edges[longedge], edges[shortedge2]);
}