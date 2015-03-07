/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 16:01:08 by gpinchon          #+#    #+#             */
/*   Updated: 2014/11/30 22:45:15 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *str, const char *to_find)
{
	char *index;
	char *index2;

	if (!*to_find)
		return ((char*)str);
	index2 = (char*)to_find;
	while (*str)
	{
		if (*str == *index2)
		{
			index = (char*)str;
			while (*to_find == *str && *to_find && *str)
			{
				to_find++;
				str++;
			}
			if (!*to_find)
				return (index);
			to_find = index2;
		}
		str++;
	}
	return (NULL);
}
