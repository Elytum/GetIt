/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:52:36 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:52:38 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_put_pixel_to_screen(t_env *e, int x, int y, int color)
{
	int i;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	i = x * (e->bpp / 8) + y * e->size_line;
	e->pimg[i] = (color & 0xFF);
	e->pimg[i + 1] = (color & 0xFF00) >> 8;
	e->pimg[i + 2] = (color & 0xFF0000) >> 16;
	return (1);
}

int			ft_update_img(t_env *e, void f(t_env *e))
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->pimg = mlx_get_data_addr(e->img, &(e->bpp),
		&(e->size_line), &(e->endian));
	f(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
