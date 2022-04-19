#include <stdio.h>
#include "push_swap.h"

void	split_by_mid4first(int n, int mid)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < n)
	{
		tmp = check_top('a');
		if (tmp <= mid)
		{
			reverse_rotate_stack('a');
			record_ans(0, REVERSE_ROTATE);
		}
		else
		{
			push('b', pop('a'));
			record_ans(1, PUSH);
			i++;
		}
	}
}

void	make_child4first(t_tree *tree, t_all *all)
{
	t_tree	*left_child;
	t_tree	*right_child;

	tree->left = (t_tree *)ft_malloc(sizeof(t_tree), 8);
	tree->right = (t_tree *)ft_malloc(sizeof(t_tree), 9);
	left_child = tree->left;
	right_child = tree->right;
	left_child->tree_num = tree->tree_num * 2 + 1;
	right_child->tree_num = tree->tree_num * 2 + 2;
	left_child->aorb = tree->aorb;
	right_child->aorb = !tree->aorb;
	left_child->size = (tree->size + 1) / 2;
	right_child->size = tree->size - left_child->size;
	left_child->min = tree->min;
	right_child->min = left_child->min + left_child->size;
	left_child->mid = (left_child->min + (left_child->size - 1) / 2);
	right_child->mid = (right_child->min + (right_child->size - 1) / 2);
	left_child->rotate_left_size = 0;
	right_child->rotate_left_size = 0;
	left_child->is_largest = 0;
	right_child->is_largest = tree->is_largest;
	all->tree_stack[left_child->tree_num] = left_child;
	all->tree_stack[right_child->tree_num] = right_child;
}

void	push_swap_first_process(t_all *all, t_tree *tree)
{
	if (tree->size > 3)
	{
		make_child4first(tree, all);
		split_by_mid4first(tree->right->size, tree->mid);
		show_stack('a');
		show_stack('b');
		push_swap_first_process(all, tree->left);
		push_swap_process(tree->right, all, all->tree_stack);
	}
	else
	{
		all = all;
		push_swap_last_process(tree);
	}
}
