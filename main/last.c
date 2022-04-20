/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:15 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 01:24:03 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_process_3a(t_tree *tree)
{
	int	tmp[3];

	tmp[2] = pop('a' + tree->aorb);
	tmp[1] = pop('a' + tree->aorb);
	tmp[0] = pop('a' + tree->aorb);
	push('a' + tree->aorb, tmp[0]);
	push('a' + tree->aorb, tmp[1]);
	push('a' + tree->aorb, tmp[2]);
	if (tmp[0] - tmp[1] == 2)
		multi_record_stack(tree->aorb, 4131);
	else if (tmp[0] - tmp[1] == -2)
		multi_record_stack(tree->aorb, 1);
	else if (tmp[0] - tmp[2] == 2)
		multi_record_stack(tree->aorb, 14131);
	else if (tmp[0] - tmp[2] == -2)
		multi_record_stack(tree->aorb, 0);
	else if (tmp[1] - tmp[2] == 2)
		multi_record_stack(tree->aorb, 1413);
	else if (tmp[1] - tmp[2] == -2)
		multi_record_stack(tree->aorb, 413);
}

void	last_process_3b_2(t_tree *tree, int *tmp)
{
	if (tmp[0] - tmp[2] == -2)
	{
		multi_record_stack(tree->aorb, 1919);
		multi_record_stack(0, 1);
		multi_record_stack(tree->aorb, 9);
	}
	else if (tmp[1] - tmp[2] == 2)
		multi_record_stack(tree->aorb, 9199);
	else if (tmp[1] - tmp[2] == -2)
		multi_record_stack(tree->aorb, 19199);
}

void	last_process_3b(t_tree *tree)
{
	int	tmp[3];

	tmp[2] = pop('a' + tree->aorb);
	tmp[1] = pop('a' + tree->aorb);
	tmp[0] = pop('a' + tree->aorb);
	push('a' + tree->aorb, tmp[0]);
	push('a' + tree->aorb, tmp[1]);
	push('a' + tree->aorb, tmp[2]);
	if (tmp[0] - tmp[1] == 2)
		multi_record_stack(tree->aorb, 1999);
	else if (tmp[0] - tmp[1] == -2)
	{
		multi_record_stack(tree->aorb, 919);
		multi_record_stack(0, 1);
		multi_record_stack(tree->aorb, 9);
	}
	else if (tmp[0] - tmp[2] == 2)
		multi_record_stack(tree->aorb, 999);
	else
		last_process_3b_2(tree, tmp);
}

void	push_swap_last_process(t_tree *tree)
{
	int	tmp[3];

	if (tree->size == 3)
	{
		if (tree->aorb == 0)
			last_process_3a(tree);
		else
			last_process_3b(tree);
	}
	else if (tree->size == 2)
	{
		tmp[0] = pop('a' + tree->aorb);
		tmp[1] = pop('a' + tree->aorb);
		push('a' + tree->aorb, tmp[1]);
		push('a' + tree->aorb, tmp[0]);
		if (tree->aorb == 0 && tmp[1] > tmp[0])
			multi_record_stack(tree->aorb, SWAP);
		else if (tree->aorb == 1 && tmp[1] < tmp[0])
			multi_record_stack(tree->aorb, 199);
		else if (tree->aorb == 1)
			multi_record_stack(tree->aorb, 99);
	}
	else if (tree->size == 1 && tree->aorb == 1)
		multi_record_stack(tree->aorb, POP);
}
