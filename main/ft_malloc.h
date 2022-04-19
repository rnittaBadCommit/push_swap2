#ifndef FT_MALLOC_H
# define FT_MALLOC_H

#include <stdlib.h>
#include <stdio.h>
typedef struct s_list
{
	struct s_list *next;
	void *p;
	void **p2;
	int index;
}				t_list;

void ft_bzero(void *s, int size);
void *ft_malloc(int size, int index);
void **ft_malloc2(int size, int index);
void ft_free_all();

#endif