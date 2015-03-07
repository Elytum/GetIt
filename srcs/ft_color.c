/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:07:46 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:07:51 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_getcolor(int height)
{
	if (height < WATER_DARK_HEIGHT)
		return (WATER_DARK_HEIGHT);
	else if (height < WATER_LIGHT_HEIGHT)
		return (WATER_LIGHT_COLOR);
	else if (height < GRASS_DARK_HEIGHT)
		return (GRASS_DARK_COLOR);
	else if (height < GRASS_WHITE_HEIGHT)
		return (GRASS_WHITE_COLOR);
	else if (height < MOUNTAIN_DARK_HEIGHT)
		return (MOUNTAIN_DARK_COLOR);
	else if (height < MOUNTAIN_LIGHT_HEIGHT)
		return (MOUNTAIN_LIGHT_COLOR);
	else
		return (ICE_COLOR);
}
