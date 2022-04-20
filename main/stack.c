/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:44 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 01:23:53 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(int i)
{
	stack(i, REVERSE_ROTATE, 0);
}

void	show_stack(int i)
{
	stack(i, SHOW, 0);
}

int	delete_stack(int i)
{
	exit(0);
	return (stack(i, DELETE, 0));
}

void	swap_top(int i)
{
	stack(i, SWAP, 0);
}

int	check_top(int i)
{
	int	ret;

	ret = pop(i);
	push(i, ret);
	return (ret);
}
