#include "push_swap.h"

int	pop(int i)
{
	return (stack(i, POP, 0));
}

void	push(int i, int data)
{
	stack(i, PUSH, data);
}

void	stack_len(int i)
{
	stack(i, LEN, 0);
}

int	ini_stack(int i, int size, int *array)
{
	i = stack(i, INI, size);
	if (i < 0)
		return (i);
	else if (array)
	{
		i = -1;
		while (++i < size)
			push(i, array[i]);
	}
	return (size);
}

void	rotate_stack(int i)
{
	stack(i, ROTATE, 0);
}
