#include <stdio.h>
#include "push_swap.h"

void split_by_mid4first(int n, int mid)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a') < mid)
		{
			rotate_stack('a');
			record_ans(0, ROTATE);
			printf("15\n");
		}
		else
		{
			push('a', pop('a'));
			record_ans(0, PUSH);
			printf("21\n");
		}
	}
}

void make_child4first(t_tree *tree)
{
	t_tree *left_child;
	t_tree *right_child;

	left_child = tree->left;
	right_child = tree->right;
	left_child->aorb = tree->aorb;
	left_child->min = tree->min;
	left_child->size = tree->size / 2;
	left_child->mid = left_child->min + left_child->size / 2;
	right_child = tree->right;
	right_child->aorb = !tree->aorb;
	right_child->min = left_child->min + left_child->size;
	right_child->size = tree->size - left_child->size;
	right_child->mid = right_child->min + right_child->size / 2;
	right_child->isbottom = 0;
}

void push_swap_first_process(t_all *all, t_tree *tree)
{
	if (tree->size > 4)
	{
		split_by_mid4first(tree->size, tree->mid);
		make_child4first(tree);
		push_swap_first_process(all, tree->left);
		push_swap_process(tree->right, 0);
	}
	else
		all = all;//last4
}
