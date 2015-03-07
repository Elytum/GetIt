/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 18:25:44 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 18:25:49 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t				ft_sline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str && !ft_isdigit(*str) && *str != '.')
		str++;
	while (*str)
	{
		while (ft_isdigit(*str))
			str++;
		while (*str && !ft_isdigit(*str))
		{
			if (*str == '.')
				i++;
			str++;
		}
		i++;
	}
	return (i);
}

void				ft_skipbuff(char **buff)
{
	while (**buff && !ft_isdigit(**buff) && **buff != '.')
		(*buff)++;
}

t_vector			**ft_fillline(char *buff, int y)
{
	t_vector	**line;
	int		i;

	line = (t_vector **)ft_memalloc(sizeof(t_vector *) * (ft_sline(buff) + 1));
	i = 0;
	ft_skipbuff(&buff);
	while (*buff)
	{
		line[i] = (t_vector *)ft_memalloc(sizeof(t_vector));
		line[i]->p = 1;
		if (ft_isdigit(*buff))
		{
			line[i]->z = ft_atoi(buff);
			line[i]->x = i;
			line[i]->y = y;
			line[i]->color = ft_getcolor(line[i]->z);
			line[i]->exist = 1;
			while (ft_isdigit(*buff))
				buff++;
		}
		(*buff == '.') ? buff++ : buff;
		ft_skipbuff(&buff);
		i++;
	}
	return (line);
}

size_t				ft_getnbrofline(char *filename)
{
	int		fd;
	size_t	size;
	char	*buff;
	int		check;

	if ((fd = open(filename, O_RDONLY)) <= 0)
	{
		ft_putstr("Error using getnextline : File can't be opened\n");
		return (0);
	}
	size = 0;
	while ((check = get_next_line(fd, &buff)) > 0)
	{
		if (*buff)
			size++;
		free(buff);
	}
	close(fd);
	if (check == -1)
	{
		ft_putstr("Error using getnextline : File can't be read\n");
		return (0);
	}
	return (size);
}
