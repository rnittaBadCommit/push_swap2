#include <stdio.h>

#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define POP 9


typedef struct	s_databox
{
	int *data;
	int min;
	int size;
	int mid;
	s_databox *left;
	s_databox *right;
}				t_databox;

typedef struct	s_all
{
	t_databox *databox_a;
	t_databox *databox_b;
	int index_a;
	int index_b;
}				t_all;

typedef struct s_tree
{
	int aorb;
	int min;
	int mid;
	int size;
	int isbottom;
	struct s_tree *left;
	struct s_tree *right;
}				t_tree;

void split_by_mid4first(int n, int mid)
{
	int i;

	i = -1;
	while (++i < n)
	{
		if (check_top('a') < mid)
		{
			rotate_stack('a');
			record_ans('a', ROTATE);
		}
		else
		{
			push('a' + !aorb, pop('a' + aorb));
			record_ans('a' + aorb, PUSH);
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
		//last4
}


int push_swap_ini(t_all *all)
{
	//make_tree
	//set first node

}

void push_swap_main(t_all *all)
{
	push_swap_ini(all);
	push_swap_first_process(all, all->tree);
}