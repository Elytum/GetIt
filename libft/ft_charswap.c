/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 18:43:59 by gpinchon          #+#    #+#             */
/*   Updated: 2014/11/25 19:00:23 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_charswap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}
