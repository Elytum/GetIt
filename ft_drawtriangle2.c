/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtriangle2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 04:07:29 by achazal           #+#    #+#             */
/*   Updated: 2015/01/18 04:07:32 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_edge		newedge2(int x1, int y1, int x2, int y2)
{
	t_edge nedge;

    if (y1 < y2)
    {
        nedge.x1 = x1;
        nedge.y1 = y1;
        nedge.x2 = x2;
        nedge.y2 = y2;
    }
    else
    {
        nedge.x1 = x2;
        nedge.y1 = y2;
        nedge.x2 = x1;
        nedge.y2 = y1;
    }
    return (nedge);
}

t_span		newspan2(int x1, int x2)
{
	t_span nspan;

    if (x1 < x2)
    {
        nspan.x1 = x1;
        nspan.x2 = x2;
    }
    else
    {
        nspan.x1 = x2;
        nspan.x2 = x1;
    }
    return (nspan);
}

void	drawspan2(t_env *e, int color, const t_span span, int y)
{
    int xdiff;
    float factor;
    float factorstep;
    int x;

    xdiff = span.x2 - span.x1;
    if (xdiff == 0)
        return;

    factor = 0.0f;
    factorstep = 1.0f / (float)xdiff;
    x = span.x1;
    for(; x < span.x2; x++) {
    	ft_put_pixel_to_screen(e, x, y, color);
        factor += factorstep;
    }
}

void		drawspansbetweenedges2(t_env *e, const t_edge e1, const t_edge e2, int color)
{
    static 	float e1ydiff;
	static 	float e2ydiff;
    static 	float e1xdiff;
    static 	float e2xdiff;
    static 	float factor1;
    static 	float factorStep1;
    static 	float factor2;
    static 	float factorStep2;
    static 	int y;

    e1ydiff = (float)(e1.y2 - e1.y1);
    if(e1ydiff == 0.0f)
        return;
    e2ydiff = (float)(e2.y2 - e2.y1);
    if(e2ydiff == 0.0f)
        return;
    e1xdiff = (float)(e1.x2 - e1.x1);
    e2xdiff = (float)(e2.x2 - e2.x1);
    factor1 = (float)(e2.y1 - e1.y1) / e1ydiff;
    factorStep1 = 1.0f / e1ydiff;
    factor2 = 0.0f;
    factorStep2 = 1.0f / e2ydiff;
    y = e2.y1;
    for(; y < e2.y2; y++) {
        t_span span = newspan2(e1.x1 + (int)(e1xdiff * factor1),
        	e2.x1 + (int)(e2xdiff * factor2));
        drawspan2(e, color, span, y);
        factor1 += factorStep1;
        factor2 += factorStep2;
	}
}

int 	ft_tricolor(int color1, int color2, int color3)
{
	int color;

	color = (((color1 & 255) + (color2 & 255) + (color3 & 255)) / 3);
    color += ((((color1 >> 8) & 255) + ((color2 >> 8) & 255) + ((color2 >> 8) & 255)) / 3) << 8;
    color += ((((color1 >> 16) & 255) + ((color2 >> 16) & 255) + ((color2 >> 16) & 255)) / 3) << 16;
    return (color);
}

void 	ft_drawtriangle2(t_env *e, t_entity *t)
{
    t_edge edges[3];
    int color;
    int shortedge1;
    int shortedge2;
    int maxlength;
    int longedge;
    int i;
    int length;

    if (t->a->buffx < -WIDTH * 0.2 || t->a->buffx > WIDTH * 1.2 || t->a->buffy < -HEIGHT * 0.2 || t->a->buffy > HEIGHT * 1.2
	|| t->b->buffx < -WIDTH * 0.2 || t->b->buffx > WIDTH * 1.2 || t->b->buffy < -HEIGHT * 0.2 || t->b->buffy > HEIGHT * 1.2
	|| t->c->buffx < -WIDTH * 0.2 || t->c->buffx > WIDTH * 1.2 || t->c->buffy < -HEIGHT * 0.2 || t->c->buffy > HEIGHT * 1.2)
		return ;
    edges[0] = newedge2((int)t->a->buffx, (int)t->a->buffy, (int)t->b->buffx, (int)t->b->buffy);
    edges[1] = newedge2((int)t->b->buffx, (int)t->b->buffy, (int)t->c->buffx, (int)t->c->buffy);
    edges[2] = newedge2((int)t->c->buffx, (int)t->c->buffy, (int)t->a->buffx, (int)t->a->buffy);
    color = ft_tricolor(t->a->color, t->a->color, t->a->color);
    maxlength = 0;
    longedge = 0;
    i = 0;
    while (i < 3)
    {
        length = edges[i].y2 - edges[i].y1;
        if (length > maxlength)
        {
            maxlength = length;
            longedge = i;
        }
        i++;
    }
    shortedge1 = (longedge + 1) % 3;
    shortedge2 = (longedge + 2) % 3;
    drawspansbetweenedges2(e, edges[longedge], edges[shortedge1], color);
    drawspansbetweenedges2(e, edges[longedge], edges[shortedge2], color);
}