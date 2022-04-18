#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void	ft_bzero(void *s, int size)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (++i < size)
		str[i] = 0;
}

int     pop_process(t_stack *stack)
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

int    push_process(t_stack *stack, int data)
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

int		rotate_process(t_stack *stack)
{
	stack->data[stack->tail++] = stack->data[stack->head++];
	if (stack->tail == stack->size)
		stack->tail = 0;
	if (stack->head == stack->size)
		stack->head = 0;
	return (0);
}

int		reverse_rotate_process(t_stack *stack)
{
	if (stack->head-- == 0)
		stack->head = stack->size - 1;
	if (stack->tail-- == 0)
		stack->tail = stack->size - 1;
	stack->data[stack->head] = stack->data[stack->tail];
	return (0);
}

int		show_process(t_stack *stack)
{
	int	i;

	return (5);
	setvbuf(stdout, (char *)NULL, _IONBF, 0);
	i = stack->head;
	while (i < stack->size && (stack->tail < stack->head || i < stack->tail))
		write(1, "      ", 4 - printf("%d ", stack->data[i++]));
	if (stack->tail < stack->head)
	{
		i = 0;
		while (i < stack->tail)
			write(1, "      ", 4 - printf("%d ", stack->data[i++]));
	}
	printf("\n");
	return (0);
}

int		stack_ini_process(t_stack *stack, int size)
{
	if (stack->data)
		stack->err = STACK_ALREADY_EXIST;
	else if (size <= 0)
		stack->err = BAD_SIZE;
	else if (!(stack->data = (int *)malloc(sizeof(int) * (size + 1))))
		stack->err = MALLOC_FAIL;
	else
		return ((stack->size = size + 1));
	return (stack->err);
}

int		delete_process(t_stack *stack)
{
	if (stack->data)
	{
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

int swap_top_process(t_stack *stack)
{
	int tmp;
	int a;
	int b;

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

int     stack(int i, int mode, int data)
{
	static  t_stack stack[800] = {};

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


int     pop(int i)
{
	return (stack(i, POP, 0));
}

void    push(int i, int data)
{
	stack(i, PUSH, data);
}

void	stack_len(int i)
{
	stack(i, LEN, 0);
}

int     ini_stack(int i, int size, int *array)
{
	if ((i = stack(i, INI, size)) < 0)
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

void	reverse_rotate_stack(int i)
{
	stack(i, REVERSE_ROTATE, 0);
}

void	show_stack(int i)
{
	//printf("%c: ", (char)i);
	stack(i, SHOW, 0);
}

int	delete_stack(int i)
{
	return (stack(i, DELETE, 0));
}

void swap_top(int i)
{
	stack(i, SWAP, 0);
}

int check_top(int i)
{
	int ret;

	ret = pop(i);
	push(i, ret);
	return (ret);
}
/*
int main()
{

	printf("ini:%d\n\n", ini_stack('a', 5, NULL));
	push('a', 1);
	push('a', 2);
	push('a', 3);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	push('a', 4);
	push('a', 5);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));
	push('a', 6);
	printf("%d\n", pop('a'));
	printf("%d\n", pop('a'));

	printf("\n");
	printf("delete:%d\n\n", delete_stack('a'));

	int array[] = {1, 2, 3, 4, 5, 6};
	printf("ini:%d\n\n", ini_stack('a', 6, array));
	show_stack('a');
	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		rotate_stack('a');
		show_stack('a');
	}
	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		reverse_rotate_stack('a');
		show_stack('a');
	}
	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		reverse_rotate_stack('a');
		show_stack('a');
		swap_top('a');
		show_stack('a');
	}
}
*/
