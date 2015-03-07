/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:20:50 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 17:20:52 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_h(double derr, t_env *e, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->buffx;
	y = p1->buffy;
	err = 0;
	while (x < p2->buffx)
	{
		ft_put_pixel_to_screen(e, x, y, e->color);
		err += derr;
		if (err > 0.5)
		{
			y += (p1->buffy < p2->buffy) ? 1 : -1;
			err -= 1.0;
		}
		x++;
	}
}

void	ft_draw_l(double derr, t_env *e, t_vector *p1, t_vector *p2)
{
	int		x;
	int		y;
	double	err;

	x = p1->buffx;
	y = p1->buffy;
	err = 0;
	while (y < p2->buffy)
	{
		ft_put_pixel_to_screen(e, x, y, e->color);
		err += derr;
		if (err > 0.5)
		{
			x += (p1->buffx < p2->buffx) ? 1 : -1;
			err -= 1.0;
		}
		y++;
	}
}

int		ft_inscreen(t_vector *p1, t_vector *p2, t_env *e)
{
	int a;
	int b;
	float r;

	if ((p1->buffx < -1 || p1->buffx > e->width + 1 ||
		p1->buffy < -1 || p1->buffy > e->height + 1) &&
		(p2->buffx < -1 || p2->buffx > e->width + 1 ||
		p2->buffy < -1 || p2->buffy > e->height + 1))
		return (0);
	a = p2->buffx - p1->buffx;
	b = p2->buffy - p1->buffy;
	r = sqrt(a * a + b * b);
	if (r > e->maxlinep2 || r != r)
		return (0);
	return (1);
}

void	ft_drawline(t_vector *p1, t_vector *p2, t_env *e)
{
	double		dx;
	double		dy;

	if (!ft_inscreen(p1, p2, e))
		return ;
	dx = abs(p2->buffx - p1->buffx);
	dy = abs(p2->buffy - p1->buffy);
	e->color = p1->color + (p2->color - p1->color) / 2;
	if (dx > dy && (p1->buffx > p2->buffx))
		ft_drawline(p2, p1, e);
	else if (dx > dy)
		ft_draw_h(dy / dx, e, p1, p2);
	else if (p1->buffy > p2->buffy)
		ft_drawline(p2, p1, e);
	else
		ft_draw_l(dx / dy, e, p1, p2);
}
