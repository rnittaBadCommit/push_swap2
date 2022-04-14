#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define POP 9

void record_ans(int aorb, int ans)
{
	write(1, "ab" + aorb+ans, 0);
	//printf("%d\n", ans);

}

void multi_record_stack2(int aorb, int tmp)
{
	if (tmp == PUSH)
		push('a' + aorb, pop('a' + !aorb));
	else if (tmp == SWAP)
		swap_top('a' + aorb);
	else if (tmp == ROTATE)
		rotate_stack('a' + aorb);
	else if (tmp == REVERSE_ROTATE)
		reverse_rotate_stack('a' + aorb);
	else if (tmp == POP)
		push('a' + !aorb, pop('a' + aorb));
	record_ans(aorb, tmp);
}
void multi_record_stack(int aorb, long long int reversed_processes)
{
	long long int processes;

	processes = 0;
	while (reversed_processes)
	{
		processes = processes * 10 + reversed_processes % 10;
		reversed_processes /= 10;
	}
	while (processes)
	{
		multi_record_stack2(aorb, processes % 10);
		processes /= 10;
	}
}

void multi_rotate_record_stack(int aorb, int n)
{
	while (n--)
	{
		rotate_stack('a' + aorb);
		record_ans(aorb, ROTATE);
	}
}

void multi_rr_record_stack(int n)
{
	while (n--)
	{
		rotate_stack('a');
		rotate_stack('b');
		record_ans(0, REVERSE_ROTATE);
	}
}

void split_by_mid(int aorb, int n, int mid, int tree_num)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a' + aorb) < mid)
		{
			push('a' + !aorb, pop('a' + aorb));
			record_ans(aorb, PUSH);
		}
		else
		{
			reverse_rotate_stack('a' + aorb);
			record_ans(aorb, ROTATE);
		}
	}
	printf("split_by_mid\n");
		printf("tree_num: %d\n", tree_num);
	show_stack('a');
	show_stack('b');
	printf("\n");
}

void push_swap_last_process(t_tree *tree)
{
	int tmp[3];
	// if (tree->aorb)
	// 	for (int i = 0; i < tree->size; i++)
	// 		push('a', pop('b'));
	// printf("push_swap_last_process\n");
	// show_stack('a');
	// show_stack('b');
	// printf("\n");
	if (tree->size == 2)
	{
		tmp[0] = pop('a' + tree->aorb);
		tmp[1] = pop('a' + tree->aorb);
		push('a' + tree->aorb, tmp[1]);
		push('a' + tree->aorb, tmp[0]);
		if (tree->aorb == 0 && tmp[1] > tmp[0])
			swap_top('a');
		else if (tree->aorb == 1 && tmp[1] < tmp[0])
		{
			swap_top('b');
			push('a', pop('b'));
			push('a', pop('b'));
		}
		else if (tree->aorb == 1)
		{
			push('a', pop('b'));
			push('a', pop('b'));
		}
	}
	else if (tree->size == 1)
	{
		if (tree->aorb == 1)
			push('a', pop('b'));
	}
	// else if (tree->size == 4)
	// {
	// 	if (tree->aorb == 0)
	// 		push_swap_last4_a();
	// 	else
	// 		push_swap_last4_b();
	// }

		printf("push_swap_last_process\n  tree->size:%d\n", tree->size);
		printf("tree_num: %d\n", tree->tree_num);
	//exit(1);
		show_stack('a');
		show_stack('b');
		printf("\n");
}

void make_child(t_tree *tree)
{
	t_tree *left_child;
	t_tree *right_child;

	tree->left = (t_tree *)ft_malloc(sizeof(t_tree));
	tree->right = (t_tree *)ft_malloc(sizeof(t_tree));
	left_child = tree->left;
	right_child = tree->right;
	left_child->lorr = 0;
	right_child->lorr = 1;
	left_child->parent = tree;
	right_child->parent = tree;
	left_child->aorb = !tree->aorb;
	left_child->min = tree->min;
	left_child->size = tree->size / 2;
	left_child->mid = left_child->min + left_child->size / 2;
	left_child->tree_num = tree->tree_num * 2 + 1;
	right_child = tree->right;
	right_child->aorb = tree->aorb;
	right_child->is_rotate_left = 1;
	right_child->is_largest = tree->is_largest;
	right_child->min = left_child->min + left_child->size;
	right_child->size = tree->size - left_child->size;
	right_child->mid = right_child->min + right_child->size / 2;
	right_child->tree_num = tree->tree_num * 2 + 2;
}

int push_swap_process(t_tree *tree, t_tree *tmp)//int b_size)
{
	int ret;

	if (tree->size <= 2)
	{
		push_swap_last_process(tree);
		if (tree->lorr == 0)
			return (0);
		else
			return (1);
	}
	else
	{
		split_by_mid(tree->aorb, tree->size, tree->mid, tree->tree_num);
		make_child(tree);
		printf("left  size: %d\n", tree->left->size);
		printf("right  size: %d\n", tree->right->size);
		printf("\n\n");
		ret = push_swap_process(tree->left, tree->right);
		if (tree->right->aorb == 0)
		{
			if (tmp->is_rotate_left && ret)
			{
				multi_rr_record_stack(tree->right->size);
				multi_rotate_record_stack(1, tmp->size - tree->right->size);
				tree->parent->right->is_rotate_left = 0;
				printf("move to right, double,  tmp->size: %d\n", tmp->size);
		printf("tree_num: %d\n", tree->tree_num);
				show_stack('a');
				show_stack('b');
				write(1, "", 0);
			}
			else if (tmp->is_rotate_left)
			{
				multi_rotate_record_stack(0, tree->right->size);

				printf("move to right, single,  tree->right->size: %d\n", tree->right->size);
		printf("tree_num: %d\n", tree->tree_num);
			}
		}
		else if (tree->right->is_rotate_left)
		{
			multi_rotate_record_stack(tree->right->aorb, tree->right->size);
			printf("move to right, single\n");
		printf("tree_num: %d\n", tree->tree_num);
			show_stack('a');
			show_stack('b');
			write(1, "", 0);
		}
		else
		{
			show_stack('a');
			show_stack('b');
		}
		printf("\n");
		push_swap_process(tree->right, tree->right);
	}
	return (1);
}

void push_swap_ini(t_all *all)
{
	all->tree = (t_tree *)ft_malloc(sizeof(t_tree));
	all->tree->size = all->size;
	all->tree->min = 0;
	all->tree->aorb = 0;
	all->tree->mid = all->size / 2;
	all->tree->tree_num = 0;
}

void push_swap_main(t_all *all)
{
	push_swap_ini(all);
	push_swap_first_process(all, all->tree);
}

int main()
{
	int n = 100;
	t_all all;
	all.size = n;
	ini_stack('a', n, NULL);
	ini_stack('b', n, NULL);
	for (int i = 0; i < n; i++)
		push('a', n - i - 1);

	// push('a', 1);
	// push('a', 4);
	// push('a', 7);
	// push('a', 20);
	// push('a', 2);
	// push('a', 3);
	// push('a', 18);
	// push('a', 0);
	// push('a', 16);
	// push('a', 8);
	// push('a', 5);
	// push('a', 6);
	// push('a', 19);
	// push('a', 13);
	// push('a', 9);
	// push('a', 10);
	// push('a', 14);
	// push('a', 17);
	// push('a', 15);
	// push('a', 12);
	// push('a', 11);
	// rotate_stack('a');
	// rotate_stack('a');

	show_stack('a');
	printf("\n");
	push_swap_main(&all);
	show_stack('a');
	show_stack('b');
	printf("\n");

int flag = 1;
int tmp;
	for (int i = 0; i < n; i++)
		if (n - i - 1 != (tmp = pop('a')))
		{
			printf("Error: expecter:%d, actual: %d\n", i, tmp);
			flag = 0;
		}
	if (flag)
		printf("OK\n");
}
