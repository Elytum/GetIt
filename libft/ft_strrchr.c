/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:52:55 by gpinchon          #+#    #+#             */
/*   Updated: 2014/11/29 20:44:26 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	int count;

	count = ft_strlen(str);
	while (count >= 0)
	{
		if (str[count] == c)
			return ((char*)&str[count]);
		count--;
	}
	return (NULL);
}
