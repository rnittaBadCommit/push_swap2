#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <stdlib.h>

typedef struct s_list
{
	struct s_list *next;
	void *p;
}				t_list;

void ft_bzero(void *s, int size);

#endif