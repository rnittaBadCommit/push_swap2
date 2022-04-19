#include "push_swap.h"
#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define POP 9

void	push_swap_ini(t_all *all)
{
	t_tree	*tree;

	all->tree = (t_tree *)ft_malloc(sizeof(t_tree), 4);
	tree = all->tree;
	tree->tree_num = 0;
	tree->aorb = 0;
	tree->size = all->size;
	tree->min = 0;
	tree->mid = (all->size - 1) / 2;
	tree->rotate_left_size = 0;
	tree->is_largest = 1;
	all->tree_stack = (t_tree **)ft_malloc2 \
		(sizeof(t_tree *) * all->size * 2 + 1, 5);
	ini_stack(0, all->size + 1, NULL);
	ini_stack(1, all->size + 1, NULL);
}

int	check_args(int argc, char **argv)
{
	if (!argv)
		return (1);
	if (argc == 1)
		return (1);
	return (0);
}

void	main_ini(int *input, int size)
{
	int	i;

	ini_stack('a', size, NULL);
	ini_stack('b', size, NULL);
	i = -1;
	while (++i < size)
		push('b', input[i]);
	i = -1;
	while (++i < size)
		push('a', pop('b'));
}

void	main2(int *input, t_all *all)
{
	int	err_flag;
	int	i;

	err_flag = 0;
	data2order(input, all->size, &err_flag);
	if (err_flag)
	{
		ft_free_all();
		write(2, "Error\n", 6);
		return ;
	}
	i = -1;
	while (++i < all->size)
		input[i] = all->size - input[i] - 1;
	main_ini(input, all->size);
	push_swap_ini(all);
	push_swap_first_process(all, all->tree);
	ft_free_all();
}

int	main(int argc, char **argv)
{
	t_all	all;
	int		i;
	int		*input;
	int		err_flag;

	all_save(&all);
	err_flag = 0;
	ft_bzero(&all, sizeof(all));
	if (check_args(argc, argv))
		return (1);
	all.size = argc - 1;
	input = ft_malloc(sizeof(int) * all.size, 1);
	i = -1;
	while (++i < all.size)
		input[i] = ft_atoi(argv[i + 1], &err_flag);
	if (err_flag)
	{
		ft_free_all();
		write(2, "Error\n", 6);
		return (2);
	}
	main2(input, &all);
}
