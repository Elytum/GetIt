/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 20:25:51 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 20:25:52 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector				***parser(char *filename)
{
	unsigned int	fd;
	unsigned int	size;
	t_vector		***map;
	char			*buff;
	int				check;

	size = ft_getnbrofline(filename);
	map = (t_vector ***)ft_memalloc(sizeof(t_vector **) * (size + 1));
	size = 0;
	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (ft_perror("Error using getnextline : File can't be opened\n"));
	while (get_next_line(fd, &buff) > 0)
	{
		if (*buff)
			map[size] = ft_fillline(buff, size);
		free(buff);
		size++;
	}
	map[size] = NULL;
	if (check == -1)
		ft_putstr("Error using getnextline : File can't be read\n");
	close(fd);
	ft_recenter(&map);
	return (map);
}

size_t					ft_lenline(t_vector **map)
{
	static size_t		size;

	size = 0;
	if (!map)
		return (-1);
	while (map[size])
		size++;
	return (size);
}
