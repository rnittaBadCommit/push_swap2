#include "push_swap.h"

void	try_rr(int *aorb, int flag)
{
	int		tmp;
	t_tree	**tree_stack;
	t_all	*all;

	all = all_save(NULL);
	tree_stack = all->tree_stack;
	tmp = check_top(!*aorb);
	if ((tmp != LEN_NOT_POSITIVE) && flag)
	{
		*aorb = 2;
		rotate_stack('a');
		rotate_stack('b');
		tree_stack[tmp]->rotate_left_size--;
		if (tree_stack[tmp]->rotate_left_size == 0)
			pop(!*aorb);
	}
	else
		rotate_stack('a' + *aorb);
}
