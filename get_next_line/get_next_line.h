#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int get_next_line(int const fd, char **line);

#endif
