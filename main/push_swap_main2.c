/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:24 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 01:24:00 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_by_mid(int aorb, int n, int mid)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a' + aorb) <= mid)
		{
			push('a' + !aorb, pop('a' + aorb));
			record_ans(!aorb, PUSH);
		}
		else
		{
			reverse_rotate_stack('a' + aorb);
			record_ans(aorb, REVERSE_ROTATE);
		}
	}
	show_stack('a');
	show_stack('b');
}

void	make_child(t_tree *tree, t_all *all)
{
	t_tree	*left_child;
	t_tree	*right_child;

	tree->left = (t_tree *)ft_malloc(sizeof(t_tree), 2);
	tree->right = (t_tree *)ft_malloc(sizeof(t_tree), 3);
	left_child = tree->left;
	right_child = tree->right;
	left_child->tree_num = tree->tree_num * 2 + 1;
	right_child->tree_num = tree->tree_num * 2 + 2;
	left_child->aorb = !tree->aorb;
	right_child->aorb = tree->aorb;
	left_child->size = (tree->size + 1) / 2;
	right_child->size = tree->size - left_child->size;
	left_child->min = tree->min;
	right_child->min = left_child->min + left_child->size;
	left_child->mid = (left_child->min + (left_child->size - 1) / 2);
	right_child->mid = (right_child->min + (right_child->size - 1) / 2);
	left_child->rotate_left_size = 0;
	right_child->rotate_left_size = right_child->size;
	left_child->is_largest = 0;
	right_child->is_largest = tree->is_largest;
	all->tree_stack[left_child->tree_num] = left_child;
	all->tree_stack[right_child->tree_num] = right_child;
}

void	move2top2(t_tree *tree)
{
	multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
	pop(tree->aorb);
}

void	move2top(t_tree *tree, t_tree **tree_stack)
{
	int	tmp;
	int	min;

	if (tree->rotate_left_size && tree->is_largest == 0)
	{
		if (tree->aorb == 0)
		{
			tmp = check_top(!tree->aorb);
			if ((tmp != LEN_NOT_POSITIVE))
			{
				min = ft_min(tree->rotate_left_size, \
					tree_stack[tmp]->rotate_left_size);
				multi_rr_record_stack(min);
				tree->rotate_left_size -= min;
				tree_stack[tmp]->rotate_left_size -= min;
				multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
				tree->rotate_left_size = 0;
				pop(tree->aorb);
			}
			else
				multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
		}
		else
			move2top2(tree);
	}
}

void	push_swap_process(t_tree *tree, t_all *all, t_tree **tree_stack)
{
	move2top(tree, tree_stack);
	if (tree->size <= 3)
		push_swap_last_process(tree);
	else
	{
		split_by_mid(tree->aorb, tree->size, tree->mid);
		make_child(tree, all);
		push(tree->aorb, tree->right->tree_num);
		push_swap_process(tree->left, all, tree_stack);
		push_swap_process(tree->right, all, tree_stack);
	}
}
