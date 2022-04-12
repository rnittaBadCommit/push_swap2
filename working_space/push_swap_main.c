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
	printf("31\n");
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
		printf("56\n");
	}
}

void multi_rr_record_stack(int n)
{
	while (n--)
	{
		rotate_stack('a');
		rotate_stack('b');
		record_ans(0, REVERSE_ROTATE);
		printf("67\n");
	}
}

void split_by_mid(int aorb, int n, int mid)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a' + aorb) < mid)
		{
			push('a' + !aorb, pop('a' + aorb));
			record_ans(aorb, PUSH);
			printf("82\n");
		}
		else
		{
			rotate_stack('a' + aorb);
			record_ans(aorb, ROTATE);
			printf("88\n");
		}
	}
}

void push_swap_last4_a()
{
	int tmp[4];

	tmp[3] = pop('a');
	tmp[2] = pop('a');
	tmp[1] = pop('a');
	tmp[0] = pop('a');
	if (tmp[0] - tmp[2] == -3 && tmp[1] - tmp[2] == -2)
		multi_record_stack(0, SWAP);
	else if (tmp[0] - tmp[2] == -3)
		multi_record_stack(0, 1912);		//SWAP POP SWAP PUSH
	else if (tmp[0] - tmp[3] == -3 && tmp[1] - tmp[2] == 1)
		multi_record_stack(0, 912);		//POP SWAP PUSH
	else if (tmp[0] - tmp[1] == -3 && tmp[1] - tmp[2] == 2)
		multi_record_stack(0, 9121);		//POP SWAP PUSH SWAP
	else if (tmp[0] - tmp[1] == -3)
		multi_record_stack(0, 19121);		//SWAP POP SWAP PUSH SWAP
	else if (tmp[1] - tmp[3] == -3 && tmp[1] - tmp[2] == -2)
		multi_record_stack(0,99122);		//POP POP SWAP PUSH PUSH
	else if (tmp[1] - tmp[2] == -3 && tmp[1] - tmp[3] == -2)
		multi_record_stack(0, 94123);		//POP REVERSE SWAP PUSH ROTATE
	else if (tmp[2] - tmp[3] == -3 && tmp[1] - tmp[2] == 2)
		multi_record_stack(0, 919122);		//POP SWAP POP SWAP PUSH PUSH
	else if (tmp[2] - tmp[3] == 3 && tmp[1] - tmp[2] == -1)
		multi_record_stack(0, 1919122);		//SWAP POP SWAP POP SWAP PUSH PUSH
	else if (tmp[1] - tmp[3] == 3 && tmp[1] - tmp[2] == 1)
		multi_record_stack(0, 1419132);		//SWAP REVERSE SWAP POP SWAP ROTATE PUSH
	else if (tmp[1] - tmp[3] == -3 && tmp[1] - tmp[2] == -1)
		multi_record_stack(0, 441313);		//REVERSE REVERSE SWAP ROTATE SWAP ROTATE
	else if (tmp[1] - tmp[2] == -3)
		multi_record_stack(0, 391412);		//ROTATE POP SWAP REVERSE SWAP PUSH
	else if (tmp[2] - tmp[3] == -3)
		multi_record_stack(0, 41);		//REVERSE SWAP REVERSE SWAP ROTATE SWAP ROTATE
	else if (tmp[2] - tmp[3] == 3)
		multi_record_stack(0, 1);		//SWAP REVERSE SWAP REVERSE SWAP ROTATE SWAP ROTATE
	else if (tmp[1] - tmp[2] == 3)
		multi_record_stack(0, 1);		//REVERSE SWAP POP SWAP ROTATE SWAP PUSH
	else if (tmp[1] - tmp[3] == 3)
		multi_record_stack(0, 1);		//SWAP REVERSE SWAP POP SWAP ROTATE SWAP PUSH
	else if (tmp[0] - tmp[1] == 3 && tmp[1] - tmp[2] == -1)
		multi_record_stack(0, 1);		//REVERSE REVERSE SWAP ROTATE SWAP ROTATE SWAP
	else if (tmp[0] - tmp[1] == 3)
		multi_record_stack(0, 1);		//REVERSE POP SWAP ROTATE SWAP PUSH SWAP
	else if (tmp[0] - tmp[2] == 3 && tmp[1] - tmp[2] == 1)
		multi_record_stack(0, 1);		//REVERSE SWAP REVERSE SWAP ROTATE SWAP ROTATE SWAP
	else if (tmp[0] - tmp[3] == 3 && tmp[1] - tmp[2] == -1)
		multi_record_stack(0,1);		//SWAP REVERSE SWAP REVERSE SWAP ROTATE SWAP ROTATE SWAP
	else if (tmp[0] - tmp[2] == 3)
		multi_record_stack(0, 1);		//REVERSE SWAP POP SWAP ROTATE SWAP PUSH SWAP
	else if (tmp[0] - tmp[3] == 3)
		multi_record_stack(0, 1);		//SWAP REVERSE SWAP POP SWAP ROTATE SWAP PUSH SWAP
}

void push_swap_last4_b()
{
	int tmp[4];

	tmp[3] = pop('a');
	tmp[2] = pop('a');
	tmp[1] = pop('a');
	tmp[0] = pop('a');
	printf("%d %d %d %d\n", tmp[0], tmp[1], tmp[2], tmp[3]);
}

/*{
	0 1 2 3	@
	0 1 3 2 @
	0 2 1 3 @
	0 2 3 1 @
	0 3 1 2 @
	0 3 2 1 @
	1 0 2 3 @
	1 0 3 2 @
	1 2 0 3 @ //POP REVERSE PUSH
	1 2 3 0 @ //REVERSE
	1 3 0 2 @
	1 3 2 0 @ //REVERSE SWAP
	2 0 1 3 @ //ROTATE SWAP
	2 0 3 1 @
	2 1 0 3 @ //POP REVERSE SWAP PUSH
	2 1 3 0 @ //REVERSE REVERSE SWAP ROTATE
	2 3 0 1 @ //REVERSE REVERSE
	2 3 1 0 @ //SWAP REVERSE REVERSE
	3 0 1 2 @ //ROTATE
	3 0 2 1 @ //SWAP ROTATE
	3 1 0 2 @ //REVERSE SWAP REVERSE REVERSE
	3 1 2 0 @ //ROTATE SWAP REVERSE
	3 2 0 1 @ //ROTATE ROTATE SWAP  OR REVERSE REVERSE SWAP
	3 2 1 0 @ //SWAP REVERSE REVERSE SWAP
}
*/

void push_swap_last3(int aorb)
{
	int tmp[3];

	tmp[2] = pop('a' + aorb);
	tmp[1] = pop('a' + aorb);
	tmp[0] = pop('a' + aorb);
	if (!aorb)
	{
		if (tmp[0] - tmp[1] == -2)
		{	//SWAP:1
			multi_record_stack(aorb, 1);
		}
		else if (tmp[1] - tmp[2] == -2)
		{	//POP:9 SWAP:1 PUSH:2
			multi_record_stack(aorb, 912);
		}
		else if (tmp[1] - tmp[2] == 2)
		{	//SWAP:1 POP:9 SWAP:1 PUSH:2
			multi_record_stack(aorb, 1912);
		}
		else if (tmp[0] - tmp[1] == 2)
		{	//POP:9 SWAP:1 PUSH:2 SWAP:1
			multi_record_stack(aorb, 9121);
		}
		else if (tmp[0] - tmp[2] == 2)
		{	//SWAP:1 POP:9 SWAP:1 PUSH:2 SWAP:1
			multi_record_stack(aorb, 19121);
		}
	}
}

void push_swap_last2_a()
{

}

void push_swap_last2_b()
{
	
}


void push_swap_last_process(t_tree *tree)
{
	if (tree->size == 2)
	{
		if (tree->aorb == 0)
			push_swap_last2_a();
		else
			push_swap_last2_b();
	}
	else if (tree->size == 3)
		push_swap_last3(tree->aorb);
	else if (tree->size == 4)
	{
		if (tree->aorb == 0)
			push_swap_last4_a();
		else
			push_swap_last4_b();
	}
	else
		printf("Error: push_swap_last_process\n  tree->size:%d\n", tree->size);
}

void make_child(t_tree *tree)
{
	t_tree *left_child;
	t_tree *right_child;

	tree->left = (t_tree *)malloc(sizeof(t_tree));
	tree->right = (t_tree *)malloc(sizeof(t_tree));
	left_child = tree->left;
	right_child = tree->right;
	left_child->aorb = !tree->aorb;
	left_child->min = tree->min;
	left_child->size = tree->size / 2;
	left_child->mid = left_child->min + left_child->size / 2;
	right_child = tree->right;
	right_child->aorb = tree->aorb;
	right_child->min = left_child->min + left_child->size;
	right_child->size = tree->size - left_child->size;
	right_child->mid = right_child->min + right_child->size / 2;
}

void push_swap_process(t_tree *tree, int b_size)
{
	if (tree->size <= 4)
		push_swap_last_process(tree);
	else
	{
		split_by_mid(tree->aorb, tree->size, tree->mid);
		make_child(tree);
		if (tree->aorb == 0)
			push_swap_process(tree->left, tree->right->size);
		else
			push_swap_process(tree->left, 0);
		if (b_size)
		{
			multi_rr_record_stack(tree->right->size);
			multi_rotate_record_stack(1, b_size - tree->right->size);
		}
		else
			multi_rotate_record_stack(1, tree->right->size);
		push_swap_process(tree->right, 0);
	}
}

void push_swap_ini(t_all *all)
{
	all->tree = (t_tree *)malloc(sizeof(t_tree));
	all->tree->size = all->size;
	all->tree->min = 0;
	all->tree->aorb = 0;
	all->tree->min = all->size / 2;
}

void push_swap_main(t_all *all)
{
	push_swap_ini(all);
	push_swap_first_process(all, all->tree);
}

int main()
{
	t_all all;
	all.size = 9;
	ini_stack('a', 10, NULL);
	ini_stack('b', 10, NULL);
	push('a', 1);
	push('a', 4);
	push('a', 7);
	push('a', 2);
	push('a', 3);
	push('a', 0);
	push('a', 8);
	push('a', 5);
	push('a', 6);
	push_swap_main(&all);
}

/*
やること
	push_swap_ini
		treeの作成と最初のノードの設定

*/