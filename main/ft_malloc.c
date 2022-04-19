#include "ft_malloc.h"

t_list *save_list(int i)
{
	static t_list save;
	static t_list save2;

	if (i == 1)
		return (&save);
	else if (i == 2)
		return (&save2);
	return (NULL);
}

void add_malloc_list(void *new, int index)
{
	t_list *list;
	t_list *tmp;

	list = save_list(1);
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p = new;
	list->next->index = index;
}

void add_malloc_list2(void **new, int index)
{
	t_list *list;
	t_list *tmp;

	list = save_list(2);
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p2 = new;
	list->next->index = index;
}

void ft_free_process(t_list *list, int i)
{
	if (list->next)
	{
		ft_free_process(list->next, i + 1);
		free(list->next);
	}
	free(list->p);
}

void ft_free_all()
{
	t_list *list;

	list = save_list(1);
	if (list->next)
		ft_free_process(list->next, 0);
	return;
	free(list->next);
	list = save_list(2);
	if (list->next)
		ft_free_process(list->next, 0);
	free(list->next);
}

void *ft_malloc(int size, int index)
{
	void *ret;

	if (!size)
		return (NULL);
	ret = malloc(size);
	ft_bzero(ret, size);
	add_malloc_list(ret, index);
	return (ret);
}

void **ft_malloc2(int size, int index)
{
	void **ret;

	if (!size)
		return (NULL);
	ret = malloc(size);
	ft_bzero(ret, size);
	add_malloc_list2(ret, index);
	return (ret);
}