/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:01:56 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:02:06 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_updateeye(t_env *e, int keycode)
{
	if (keycode == 65464)
		e->eye = ft_m_x_v(ft_rotate_x(-0.5), e->eye);
	else if (keycode == 65461)
		e->eye = ft_m_x_v(ft_rotate_x(0.5), e->eye);
	else if (keycode == 65460)
		e->eye = ft_m_x_v(ft_rotate_y(-0.5), e->eye);
	else if (keycode == 65462)
		e->eye = ft_m_x_v(ft_rotate_y(0.5), e->eye);
	else if (keycode == 65463)
		e->eye = ft_m_x_v(ft_rotate_z(-0.5), e->eye);
	else if (keycode == 65465)
		e->eye = ft_m_x_v(ft_rotate_z(0.5), e->eye);
	// if (keycode == 65464 || keycode == 65461 || keycode == 65460 ||
		// keycode == 65462 || keycode == 65463 || keycode == 65465)
		// ft_normalize(&e->eye);
}

void			ft_translateworld(t_env *e, int keycode)
{
	if (keycode == 65364)
		ft_apply_m_to_obj(e, ft_translation(0, 10, 0), TRANSLATE);
	else if (keycode == 65362)
		ft_apply_m_to_obj(e, ft_translation(0, -10, 0), TRANSLATE);
	else if (keycode == 65363)
		ft_apply_m_to_obj(e, ft_translation(10, 0, 0), TRANSLATE);
	else if (keycode == 65361)
		ft_apply_m_to_obj(e, ft_translation(-10, 0, 0), TRANSLATE);
}

void			ft_scaleworld(t_env *e, int keycode)
{
	if (keycode == 61)
		ft_apply_m_to_obj(e, ft_toscale(10.0 / 9.0, 10.0 / 9.0, 10.0 / 9.0), SCALE);
	else if (keycode == 45)
		ft_apply_m_to_obj(e, ft_toscale(9.0 / 10.0, 9.0 / 10.0, 9.0 / 10.0), SCALE);
	else if (keycode == 48)
		ft_apply_m_to_obj(e, ft_toscale(1, 1, 9.f / 10.f), SCALE);
	else if (keycode == 57)
		ft_apply_m_to_obj(e, ft_toscale(1, 1, 10.f / 9.f), SCALE);
	else if (keycode == 53)
		ft_apply_m_to_obj(e, ft_toscale(1, 9.f / 10.f, 1), SCALE);
	else if (keycode == 54)
		ft_apply_m_to_obj(e, ft_toscale(1, 10.f / 9.f, 1), SCALE);
	else if (keycode == 55)
		ft_apply_m_to_obj(e, ft_toscale(9.f / 10.f, 1, 1), SCALE);
	else if (keycode == 56)
		ft_apply_m_to_obj(e, ft_toscale(10.f / 9.f, 1, 1), SCALE);
}

void			ft_rotateworld(t_env *e, int keycode)
{
	if (keycode == 121)
		ft_apply_m_to_obj(e, ft_rotate_x(-0.1), ROTATE);
	else if (keycode == 117)
		ft_apply_m_to_obj(e, ft_rotate_x(0.1), ROTATE);
	else if (keycode == 104)
		ft_apply_m_to_obj(e, ft_rotate_y(-0.1), ROTATE);
	else if (keycode == 106)
		ft_apply_m_to_obj(e, ft_rotate_y(0.1), ROTATE);
	else if (keycode == 110)
		ft_apply_m_to_obj(e, ft_rotate_z(0.1), ROTATE);
	else if (keycode == 109)
		ft_apply_m_to_obj(e, ft_rotate_z(-0.1), ROTATE);
}

void			ft_updatecenter(t_env *e, int keycode)
{
	if (keycode == 119)
		e->center = ft_m_x_v(ft_translation(0, -1, 0), e->center);
	else if (keycode == 115)
		e->center = ft_m_x_v(ft_translation(0, 1, 0), e->center);
	else if (keycode == 97)
		e->center = ft_m_x_v(ft_translation(-1, 0, 0), e->center);
	else if (keycode == 100)
		e->center = ft_m_x_v(ft_translation(1, 0, 0), e->center);
	else if (keycode == 113)
		e->center = ft_m_x_v(ft_translation(0, 0, -1), e->center);
	else if (keycode == 101)
		e->center = ft_m_x_v(ft_translation(0, 0, 1), e->center);
}
