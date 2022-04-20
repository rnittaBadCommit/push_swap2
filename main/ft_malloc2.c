/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:11 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 03:50:02 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_free_all(void)
{
	t_list	*list;

	list = save_list(1);
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
