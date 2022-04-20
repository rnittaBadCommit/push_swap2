/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:49 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 04:29:03 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, int size)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (++i < size)
		str[i] = 0;
}

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	count(int n)
{
	static int	c;

	c += n;
	return (c);
}

t_all	*all_save(t_all *all)
{
	static t_all	*save;

	if (!save)
		save = all;
	return (save);
}

void	ft_write(int a, char *s, int size)
{
	if (write(a, s, size) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
