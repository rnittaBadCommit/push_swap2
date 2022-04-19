#include "ft_malloc.h"

t_list	*save_list(int i)
{
	static t_list	save;
	static t_list	save2;

	if (i == 1)
		return (&save);
	else if (i == 2)
		return (&save2);
	return (NULL);
}

void	add_malloc_list(void *new, int index)
{
	t_list	*list;
	t_list	*tmp;

	list = save_list(1);
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p = new;
	list->next->index = index;
}

void	add_malloc_list2(void **new, int index)
{
	t_list	*list;
	t_list	*tmp;

	list = save_list(2);
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p2 = new;
	list->next->index = index;
}

void	ft_free_process(t_list *list, int i)
{
	if (list->next)
	{
		ft_free_process(list->next, i + 1);
		free(list->next);
	}
	free(list->p);
}
