#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "get_next_line.h"
/*
 *    int main ()
 *       {
 *          int fd;
 *             char *line;
 *                fd = open("lorem", O_RDONLY);
 *                   if (fd == -1)
 *                      ft_putstr("open() failed");
 *                         while(get_next_line(fd, &line)>0)
 *                            ft_putendl(line);
 *                               close(fd);
 *                                  return (0);
 *                                     }*/

int main(int ac, char **av)
{
	char	*line = NULL;
	int		fd;
	int		ret;

	if (ac > 1)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			while ((ret = (get_next_line(fd, &line))) > 0)
			{
				printf("%s\n", line);
				free(line);
			}
			if (!ret)
				ft_putstr("Lecture finie");
			if (ret == -1)
				ft_putstr("Erreur");
		}
	}
	if (ac == 1)
	{
		while ((ret = (get_next_line(0, &line))) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		if (!ret)
			ft_putstr("Lecture finie");
		if (ret == -1)
			ft_putstr("Erreur");
	}
	return (0);
}
