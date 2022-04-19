#include "push_swap.h"

void	reverse_rotate_stack(int i)
{
	stack(i, REVERSE_ROTATE, 0);
}

void	show_stack(int i)
{
	stack(i, SHOW, 0);
}

int	delete_stack(int i)
{
	exit(0);
	return (stack(i, DELETE, 0));
}

void	swap_top(int i)
{
	stack(i, SWAP, 0);
}

int	check_top(int i)
{
	int	ret;

	ret = pop(i);
	push(i, ret);
	return (ret);
}
