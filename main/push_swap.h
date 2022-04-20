/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:30 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 04:36:36 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_malloc.h"

# define LEN_NOT_POSITIVE -1
# define LEN_OVER_SIZE -2
# define DELETED_STACK -3
# define STACK_ALREADY_EXIST -4
# define BAD_SIZE -5
# define MALLOC_FAIL -100
# define INI 0
# define SWAP 1
# define PUSH 2
# define ROTATE 3
# define REVERSE_ROTATE 4
# define POP 9
# define DUAL_ROTATE 5
# define SHOW 10
# define DELETE 6
# define LEN 7
# define CHECK 8

typedef struct s_tmparray
{
	int	data;
	int	i;
}				t_tmparray;

typedef struct s_stack
{
	int	*data;
	int	size;
	int	len;
	int	head;
	int	tail;
	int	err;
}				t_stack;

typedef struct s_array
{
	int	*data;
	int	size;
	int	len;
	int	head;
	int	tail;
	int	err;
}				t_array;

typedef struct s_tree
{
	int				tree_num;
	int				aorb;
	int				size;
	int				min;
	int				mid;
	int				rotate_left_size;
	int				is_largest;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct s_all
{
	int		index_a;
	int		index_b;
	int		num_a;
	int		num_b;
	t_tree	*tree;
	int		size;
	t_tree	**tree_stack;
	int		flag;
}				t_all;

void		is_sorted(int *input, int size);
void		ft_write(int a, char *s, int size);
void		try_rr(int *aorb, int flag);
int			count(int n);
int			ft_min(int x, int y);
void		data2order(int *array, int size, int *err_flag);
void		record_ans(int aorb, int ans);
int			ini_array(char c, int size);
void		split_by_mid4first(int n, int mid);
void		make_child4first(t_tree *tree, t_all *all);
void		push_swap_first_process(t_all *all, t_tree *tree);
void		ft_bzero(void *s, int size);
int			pop_process(t_stack *stack);
int			push_process(t_stack *stack, int data);
int			rotate_process(t_stack *stack);
int			reverse_rotate_process(t_stack *stack);
int			show_process(t_stack *stack);
int			stack_ini_process(t_stack *stack, int size);
int			delete_process(t_stack *stack);
int			swap_top_process(t_stack *stack);
int			stack(int i, int mode, int data);
int			pop(int i);
void		push(int i, int data);
void		stack_len(int i);
int			ini_stack(int i, int size, int *array);
void		rotate_stack(int i);
void		reverse_rotate_stack(int i);
void		show_stack(int i);
int			delete_stack(int i);
void		swap_top(int i);
int			check_top(int i);
t_all		*all_save(t_all *all);
void		multi_record_stack2(int aorb, int tmp, int flag);
void		multi_record_stack(int aorb, long long int reversed_processes);
void		multi_rotate_record_stack(int aorb, int n);
void		multi_rr_record_stack(int n);
void		split_by_mid(int aorb, int n, int mid);
void		update_databox(int aorb, t_all *all);
void		push_swap_first(t_all *all);
void		push_swap_last4_a(void);
void		push_swap_last4_b(void);
void		push_swap_last3(int aorb);
void		push_swap_ini(t_all *all);
void		push_swap_last_process(t_tree *tree);
void		make_child(t_tree *tree, t_all *all);
void		push_swap_process(t_tree *tree, t_all *all, t_tree **tree_stack);
void		push_swap_main(t_all *all);
int			ft_atoi(char *s, int *err_flag);

#endif