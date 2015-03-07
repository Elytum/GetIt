/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:32:09 by gpinchon          #+#    #+#             */
/*   Updated: 2014/12/19 16:38:56 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "./libft/libft.h"

int		findchar(char *buffer, char n)
{
	int	count;

	count = 0;
	while (buffer[count] != n && buffer[count])
		count++;
	return (count);
}

char	*separate(char *big_buffer, char **save)
{
	int		position;
	char	*tmp;

	position = findchar(big_buffer, '\n');
	big_buffer[position] = '\0';
	free(*save);
	if ((tmp = ft_strdup(big_buffer)) == NULL)
		return (NULL);
	if ((*save = ft_strdup(big_buffer + position + 1)) == NULL)
		return (NULL);
	free(big_buffer);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buff;
	char		*big_buff;
	static char	*save = NULL;

	if (save != NULL && findchar(save, '\n') != findchar(save, '\0'))
		return ((*line = separate(save, &save)) == NULL ? -1 : 1);
	if ((buff = malloc(BUFF_SIZE + 1)) == NULL || BUFF_SIZE <= 0)
		return (-1);
	buff[0] = '\0';
	big_buff = save;
	save = NULL;
	ret = BUFF_SIZE;
	while (ret == BUFF_SIZE && findchar(buff, '\n') == findchar(buff, '\0'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return ((*line = big_buff) == NULL ? -1 : 0);
		buff[ret] = '\0';
		if ((big_buff = ft_strjoin(big_buff, buff)) == NULL)
			return (-1);
	}
	return ((*line = separate(big_buff, &save)) == NULL ? -1 : 1);
}
