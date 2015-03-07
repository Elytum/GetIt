/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 16:20:10 by gpinchon          #+#    #+#             */
/*   Updated: 2014/12/05 21:56:29 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	intlenght(int n)
{
	size_t	size;

	size = 1;
	while ((n /= 10))
		size++;
	return (size);
}

char	*isneg(int n, char *str, char *ptr)
{
	n *= -1;
	while (n)
	{
		*(ptr++) = '0' + (n % 10);
		n /= 10;
	}
	*ptr = '-';
	*(ptr + 1) = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa(int n)
{
	char			*str;
	char			*ptr;

	str = (char *)malloc(sizeof(char) * (intlenght(n) + 1));
	ptr = str;
	ft_strclr(str);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (isneg(n, str, ptr));
	if (!n)
		*ptr = '0';
	while (n)
	{
		*(ptr++) = '0' + (n % 10);
		n /= 10;
	}
	return (ft_strrev(str));
}
