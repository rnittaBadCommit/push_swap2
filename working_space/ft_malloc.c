#include "ft_malloc.h"

void *ft_malloc(int size)
{
	void *ret;
	t_list *list;

	ret = malloc(size);
	ft_bzero(ret, size);
	add_malloc_list(ret);
	return (ret);
}

t_list *save_list()
{
	static t_list save;

	return (&save);
}

void add_malloc_list(void *new)
{
	t_list *list;
	t_list *tmp;

	list = save_list();
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p = new;
}

void ft_free_process(t_list *list)
{
	if (list->next)
	{
		ft_free_process(list->next);
		free(list->next);
	}
	free(list->p);
}

void ft_free_all()
{
	t_list *list;

	list = save_list();
	if (list->next)
		ft_free_process(list->next);
	free(list->next);
}