#include <stdio.h>
#include "push_swap.h"

void split_by_mid4first(int n, int mid)
{
	int i;
	int tmp;

	i = -1;
	while (++i < n)
	{
		if ((tmp = check_top('a')) <= mid)
		{
			reverse_rotate_stack('a');
			record_ans(0, REVERSE_ROTATE);
			//printf("15\n");
		}
		else
		{
			push('b', pop('a'));
			record_ans(0, PUSH);
			//printf("21\n");
		}
	}
}

void *ft_malloc(int size)
{
	void *ret;

	ret = malloc(size);
	ft_bzero(ret, size);
	return (ret);
}

void make_child4first(t_tree *tree, t_all *all)
{
	t_tree *left_child;
	t_tree *right_child;

	tree->left = (t_tree *)malloc(sizeof(t_tree));
	tree->right = (t_tree *)malloc(sizeof(t_tree));
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
	all->tree_stack[left_child->tree_num] = left_child;
	all->tree_stack[right_child->tree_num] = right_child;
}

void push_swap_first_process(t_all *all, t_tree *tree)
{
	printf("push_swap_first_process\n");
	if (tree->size > 2)
	{
		printf("split_by_mid4first\ttree_num: %d\n", tree->tree_num);
		split_by_mid4first(tree->size, tree->mid);
		show_stack('a');
		show_stack('b');
		make_child4first(tree, all);
		printf("left  size: %d\n", tree->left->size);
		printf("right  size: %d\n", tree->right->size);
		printf("\n");
		push_swap_first_process(all, tree->left);
		printf("push_swap_process    in first.c\n");
		push_swap_process(tree->right, all, all->tree_stack);
	}
	else
	{
		all = all;//last4
		printf("push_swap_last_process\t\ttree_num: %d\t\tin first.c\n", tree->tree_num);
		push_swap_last_process(tree);
	}
}
