#include "push_swap.h"

int	pop_process(t_stack *stack)
{
	if (stack->len <= 0)
		return ((stack->err = LEN_NOT_POSITIVE));
	stack->len--;
	if (stack->tail == 0)
		stack->tail = stack->size - 1;
	else
		stack->tail--;
	return (stack->data[stack->tail]);
}

int	push_process(t_stack *stack, int data)
{
	if (stack->len >= stack->size - 1)
		return ((stack->err = LEN_OVER_SIZE));
	stack->data[stack->tail] = data;
	if (stack->tail == stack->size - 1)
		stack->tail = 0;
	else
		stack->tail++;
	stack->len++;
	return (0);
}

int	rotate_process(t_stack *stack)
{
	stack->data[stack->tail++] = stack->data[stack->head++];
	if (stack->tail == stack->size)
		stack->tail = 0;
	if (stack->head == stack->size)
		stack->head = 0;
	return (0);
}

int	reverse_rotate_process(t_stack *stack)
{
	if (stack->head-- == 0)
		stack->head = stack->size - 1;
	if (stack->tail-- == 0)
		stack->tail = stack->size - 1;
	stack->data[stack->head] = stack->data[stack->tail];
	return (0);
}

int	show_process(t_stack *stack)
{
	if (stack)
		return (0);
	return (5);
}
