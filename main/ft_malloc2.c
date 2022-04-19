#include "ft_malloc.h"

void	ft_free_all(void)
{
	t_list	*list;

	list = save_list(1);
	if (list->next)
		ft_free_process(list->next, 0);
	return ;
	free(list->next);
	list = save_list(2);
	if (list->next)
		ft_free_process(list->next, 0);
	free(list->next);
}

void	*ft_malloc(int size, int index)
{
	void	*ret;

	if (!size)
		return (NULL);
	ret = malloc(size);
	ft_bzero(ret, size);
	add_malloc_list(ret, index);
	return (ret);
}

void	**ft_malloc2(int size, int index)
{
	void	**ret;

	if (!size)
		return (NULL);
	ret = malloc(size);
	ft_bzero(ret, size);
	add_malloc_list2(ret, index);
	return (ret);
}
