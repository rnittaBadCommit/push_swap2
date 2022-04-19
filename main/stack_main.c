#include "push_swap.h"

int	stack_ini_process(t_stack *stack, int size)
{
	if (stack->data)
		stack->err = STACK_ALREADY_EXIST;
	else if (size <= 0)
		stack->err = BAD_SIZE;
	else
	{
		stack->data = (int *)ft_malloc(sizeof(int) * (size + 1), 7);
		if (!stack->data)
			stack->err = MALLOC_FAIL;
		else
			return ((stack->size = size + 1));
	}
	return (stack->err);
}

int	delete_process(t_stack *stack)
{
	if (stack->data)
	{
		exit(1);
		free(stack->data);
		ft_bzero(stack, sizeof(stack));
		return (0);
	}
	else
	{
		stack->err = DELETED_STACK;
		return (-1);
	}
}

int	swap_top_process(t_stack *stack)
{
	int	tmp;
	int	a;
	int	b;

	if (stack->tail > 1)
	{
		a = stack->tail - 2;
		b = stack->tail - 1;
	}
	else if (stack->tail == 0)
	{
		a = stack->size - 2;
		b = stack->size - 1;
	}
	else
	{
		a = stack->size - 1;
		b = 0;
	}
	tmp = stack->data[a];
	stack->data[a] = stack->data[b];
	stack->data[b] = tmp;
	return (0);
}

int	stack(int i, int mode, int data)
{
	static t_stack	stack[800] = {};

	if (mode == INI)
		return (stack_ini_process(stack + i, data));
	else if (mode == POP)
		return (pop_process(stack + i));
	else if (mode == PUSH)
		return (push_process(stack + i, data));
	else if (mode == ROTATE)
		return (rotate_process(stack + i));
	else if (mode == REVERSE_ROTATE)
		return (reverse_rotate_process(stack + i));
	else if (mode == SHOW)
		return (show_process(stack + i));
	else if (mode == DELETE)
		return (delete_process(stack + i));
	else if (mode == SWAP)
		return (swap_top_process(stack + i));
	else if (mode == LEN)
		return (stack[i].len);
	else if (mode == CHECK)
		return (stack[i].data[stack[i].tail - 1]);
	return (-2);
}
