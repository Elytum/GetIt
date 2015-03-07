/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:16:09 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 19:16:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_refresh(t_env *e)
{
	if (e->refresh == 1)
	{
		ft_update_img(e, ft_drawmap);
		return (0);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	ft_update_img(e, ft_drawmap);
	return (0);
}
