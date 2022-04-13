#include <stdio.h>
#include "push_swap.h"

void split_by_mid4first(int n, int mid)
{
	static int a;
	int i;
	int tmp;

	i = -1;
	while (++i < n)
	{
		if ((tmp = check_top('a')) < mid)
		{
			reverse_rotate_stack('a');
			record_ans(0, REVERSE_ROTATE);
			//printf("15\n");
			a++;
			if (a == -100)
				exit (2);
		}
		else
		{
			push('b', pop('a'));
			record_ans(0, PUSH);
			//printf("21\n");
		}
	}
	show_stack('a');
	show_stack('b');
}

void make_child4first(t_tree *tree)
{
	t_tree *left_child;
	t_tree *right_child;

	tree->left = (t_tree *)malloc(sizeof(t_tree));
	tree->right = (t_tree *)malloc(sizeof(t_tree));
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
		printf("push_swap_first_process\n");
		split_by_mid4first(tree->size, tree->mid);
		make_child4first(tree);
		printf("left  size: %d\n", tree->left->size);
		printf("right  size: %d\n", tree->right->size);
		printf("\n");
		push_swap_first_process(all, tree->left);
		printf("push_swap_process    in first.c\n");
		push_swap_process(tree->right, 0);
	}
	else
	{
		all = all;//last4
		printf("\nlast4\n");
		show_stack('a');
		show_stack('b');
		printf("\n");
	}
}
