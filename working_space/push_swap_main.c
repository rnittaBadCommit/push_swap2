#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define POP 9


// void last_4_a()
// {
// 	int tmp[]
// }

int count(int n)
{
	static int c;

	c += n;
	return (c);
}

void record_ans(int aorb, int ans)
{
	if (ans == POP && aorb != 2)
		aorb = !aorb;
	if (ans == POP)
		ans = PUSH;
	if (ans == ROTATE)
		ans = REVERSE_ROTATE;
	else if (ans == REVERSE_ROTATE)
		ans = ROTATE;
	if (ans == REVERSE_ROTATE)
		write(1, "rr", 2);
	else
		write(1, "zspr" + ans, 1);	
	if (aorb == 2)
		write(1, "zsprr" + ans, 1);
	else
		write(1, "ab" + aorb, 1);
	write(1, "\n", 1);
	count(1);
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
		record_ans(2, ROTATE);
	}
}

void split_by_mid(int aorb, int n, int mid, int tree_num)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a' + aorb) <= mid)
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
	//zprintf("split_by_mid\n");
		//zprintf("tree_num: %d\n", tree_num);
	show_stack('a');
	show_stack('b');
	//zprintf("\n");
}


// tmp:	0 1 2

// 		0 1 2
// 		0 2 1
// 		1 0 2
// 		1 2 0
// 		2 0 1
// 		2 1 0
		
void last_process_3a(t_tree *tree)
{
	int tmp[3];

	tmp[2] = pop('a' + tree->aorb);
	tmp[1] = pop('a' + tree->aorb);
	tmp[0] = pop('a' + tree->aorb);
	push('a' + tree->aorb, tmp[0]);
	push('a' + tree->aorb, tmp[1]);
	push('a' + tree->aorb, tmp[2]);
	if (tmp[0] - tmp[1] == 2)		//2 0 1
		multi_record_stack(tree->aorb, 4131);
	else if (tmp[0] - tmp[1] == -2)	//0 2 1
		multi_record_stack(tree->aorb, 1);
	else if (tmp[0] - tmp[2] == 2)	//2 1 0
		multi_record_stack(tree->aorb, 14131);
	else if (tmp[0] - tmp[2] == -2)	//0 1 2
		multi_record_stack(tree->aorb, 0);
	else if (tmp[1] - tmp[2] == 2)	//1 2 0
		multi_record_stack(tree->aorb, 1413);
	else if (tmp[1] - tmp[2] == -2)	//1 0 2
		multi_record_stack(tree->aorb, 413);
}

void last_process_3b(t_tree *tree)
{
	int tmp[3];

	tmp[2] = pop('a' + tree->aorb);
	tmp[1] = pop('a' + tree->aorb);
	tmp[0] = pop('a' + tree->aorb);
	push('a' + tree->aorb, tmp[0]);
	push('a' + tree->aorb, tmp[1]);
	push('a' + tree->aorb, tmp[2]);
	if (tmp[0] - tmp[1] == 2)		//2 0 1
		multi_record_stack(tree->aorb, 1999);
	else if (tmp[0] - tmp[1] == -2)	//0 2 1
	{
		multi_record_stack(tree->aorb, 919);
		multi_record_stack(0, 1);
		multi_record_stack(tree->aorb, 9);
	}
	else if (tmp[0] - tmp[2] == 2)	//2 1 0
		multi_record_stack(tree->aorb, 999);
	else if (tmp[0] - tmp[2] == -2)	//0 1 2
	{
		multi_record_stack(tree->aorb, 1919);
		multi_record_stack(0, 1);
		multi_record_stack(tree->aorb, 9);
	}
	else if (tmp[1] - tmp[2] == 2)	//1 2 0
		multi_record_stack(tree->aorb, 9199);
	else if (tmp[1] - tmp[2] == -2)	//1 0 2
		multi_record_stack(tree->aorb, 19199);
}

void push_swap_last_process(t_tree *tree)
{
	int tmp[3];

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
		{
			multi_record_stack(tree->aorb, 199);
		}
		else if (tree->aorb == 1)
		{
			multi_record_stack(tree->aorb, 99);
		}
	}
	else if (tree->size == 1)
	{
		if (tree->aorb == 1)
			multi_record_stack(tree->aorb, POP);
	}
	// else if (tree->size == 4)
	// {
	// 	if (tree->aorb == 0)
	// 		push_swap_last4_a();
	// 	else
	// 		push_swap_last4_b();
	// }

		//zprintf("push_swap_last_process\n  tree->size:%d\n", tree->size);
		//zprintf("tree_num: %d\n", tree->tree_num);
	//exit(2);
		show_stack('a');
		show_stack('b');
		//zprintf("\n");
}

void make_child(t_tree *tree, t_all *all)
{
	t_tree *left_child;
	t_tree *right_child;

	tree->left = (t_tree *)ft_malloc(sizeof(t_tree));
	tree->right = (t_tree *)ft_malloc(sizeof(t_tree));
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
	all->tree_stack[left_child->tree_num] = left_child;
	all->tree_stack[right_child->tree_num] = right_child;
}

/*
int push_swap_process(t_tree *tree, t_tree *tmp)//int b_size)
{
	int ret;

	if (tree->size <= 2)
	{
		push_swap_last_process(tree);
		printf("tree->lorr: %d\n", tree->lorr);
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
*/

void move2top(t_tree *tree, t_tree **tree_stack)
{
	int tmp;
	int min;

	if (tree->rotate_left_size)
	{
		if (tree->aorb == 0)
		{
			if ((tmp = check_top(!tree->aorb) != LEN_NOT_POSITIVE))
			{
				min = MIN(tree->rotate_left_size, tree_stack[tmp]->rotate_left_size);
				multi_rr_record_stack(min);
				tree->rotate_left_size -= min;
				multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
				tree->rotate_left_size = 0;
				pop(tree->aorb);
			}
			else
			{
				multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
			}

		}
		else
		{
			multi_rotate_record_stack(tree->aorb, tree->rotate_left_size);
			pop(tree->aorb);
		}
	}
}

void push_swap_process(t_tree *tree, t_all *all, t_tree **tree_stack)
{
	move2top(tree, tree_stack);
	if (tree->size <= 3)
		push_swap_last_process(tree);
	else
	{
		split_by_mid(tree->aorb, tree->size, tree->mid, tree->tree_num);
		make_child(tree, all);
		push(tree->aorb, tree->right->tree_num);
		push_swap_process(tree->left, all, tree_stack);
		push_swap_process(tree->right, all, tree_stack);
	}
}

void push_swap_ini(t_all *all)
{
	t_tree *tree;

	all->tree = (t_tree *)ft_malloc(sizeof(t_tree));
	tree = all->tree;
	tree->tree_num = 0;
	tree->aorb = 0;
	tree->size = all->size;
	tree->min = 0;
	tree->mid = (all->size - 1) / 2;
	tree->rotate_left_size = 0;
	all->tree_stack = (t_tree **)ft_malloc(sizeof(t_tree *) * all->size + 1);
	ini_stack(0, all->size + 1, NULL);
	ini_stack(1, all->size + 1, NULL);
}

void push_swap_main(t_all *all)
{
	push_swap_ini(all);
	push_swap_first_process(all, all->tree);
}


int check_args(int argc, char **argv)
{
	if (!argv)
		return(1);
	if (argc == 1)
		return (1);
	return (0);
}

void main_ini(int *input, int size)
{
	int i;

	ini_stack('a', size, NULL);
	ini_stack('b', size, NULL);
	i = -1;
	while (++i < size)
		push('b', input[i]);
	i = -1;
	while (++i < size)
		push('a', pop('b'));
}

int ft_atoi(char *s, int *err_flag)
{
	long long int ret;
	int i;
	int posi;

	ret = 0;
	i = -1;
	posi = 1;
	if (s[0] == '-')
	{
		i++;
		posi = -1;
	}
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret = ret * 10 + s[i] - '0';
		else
		{
			*err_flag = 1;
			return (-1);
		}
		if ((posi == 1 && ret > INT_MAX) || (posi == -1 && -ret < INT_MIN))
		{
			*err_flag = 1;
			return (-1);
		}
	}
	return (posi * ret);
}

int main(int argc, char **argv)
{
	t_all all;
	int i;
	int *input;
	int err_flag;



	err_flag = 0;
	ft_bzero(&all, sizeof(all));
	if (check_args(argc, argv))
		return (1);
	all.size = argc - 1;
	input = malloc(sizeof(int) * all.size);
	i = -1;
	while (++i < all.size)
		input[i] = ft_atoi(argv[i + 1], &err_flag);
	if (err_flag)
	{
		free(input);
		write(2, "Error\n", 6);
		return (1);
	}
	data2order(input, all.size, &err_flag);
	if (err_flag)
	{
		free(input);
		write(2, "Error\n", 6);
		return (1);
	}
	i = -1;
	while (++i < all.size)
		input[i] = all.size - input[i] - 1;
	main_ini(input, all.size);
	show_stack('a');
	push_swap_main(&all);

	show_stack('a');
	//zprintf("argc: %d\n", argc);
	//printf("======  count: %d  ======\n", count(0));
}

/*
int main()
{
	int n = 21;
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
	// push('a', 11);	//n = 21
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

*/
