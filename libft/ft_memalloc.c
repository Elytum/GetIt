/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:12:05 by gpinchon          #+#    #+#             */
/*   Updated: 2014/11/29 20:52:29 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*memalloc;

	if (!(memalloc = (char*)malloc(sizeof(char) * size)) || !size)
		return (NULL);
	ft_memset(memalloc, '\0', size);
	return ((void*)memalloc);
}
