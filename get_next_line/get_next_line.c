/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cretaill <cretaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by cretaill          #+#    #+#             */
/*   Updated: 2015/01/03 01:45:39 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_strndup(const char *str, size_t n)
{
	register char	*strnew;
	register char	*ptr;

	strnew = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ptr = strnew;
	while (*str && n--)
		*ptr++ = *str++;
	*ptr = '\0';
	return (strnew);
}

char		*ft_strcdup(const char *str, char c)
{
	register char	*strnew;
	register char	*ptr;

	strnew = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ptr = strnew;
	while (*str && *str != c)
		*ptr++ = *str++;
	*ptr = '\0';
	return (strnew);
}

int			ft_get_single_line(int fd, char **memory)
{
	char	*tmp;
	char	*buff;
	int		re;

	buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	while (!ft_strchr(*memory, '\n'))
	{
		ft_strclr(buff);
		if ((re = read(fd, buff, BUFF_SIZE)) == -1)
			return (re);
		if (re == 0)
			return (0);
		tmp = ft_strjoin(*memory, buff);
		free(*memory);
		*memory = tmp;
	}
	free(buff);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*memory = NULL;
	char		*tmp;
	char		*ptr;

	if (!line)
		return (-1);
	if (!memory)
		memory = ft_strdup("");
	if (ft_get_single_line(fd, &memory) == -1)
		return (-1);
	ptr = ft_strchr(memory, '\n');
	if (!ptr)
	{
		*line = memory;
		memory = NULL;
		if (*(*line))
			return (1);
		else
			return (0);
	}
	else if (ptr + 1 == '\0')
	{
		*ptr = '\0';
		*line = memory;
		memory = NULL;
		return (1);
	}
	*line = ft_strcdup(memory, '\n');
	tmp = ft_strdup(ptr + 1);
	free(memory);
	memory = tmp;
	return (1);
}
