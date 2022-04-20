/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:09 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 01:24:04 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*p;
	void			**p2;
	int				index;
}				t_list;

void	ft_bzero(void *s, int size);
void	*ft_malloc(int size, int index);
void	**ft_malloc2(int size, int index);
void	ft_free_all(void);
t_list	*save_list(int i);
void	add_malloc_list(void *new, int index);
void	add_malloc_list2(void **new, int index);
void	ft_free_process(t_list *list, int i);

#endif