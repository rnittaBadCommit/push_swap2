#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>

#define LEN_NOT_POSITIVE -1
#define LEN_OVER_SIZE -2
#define DELETED_STACK -3
#define STACK_ALREADY_EXIST -4
#define BAD_SIZE -5
#define MALLOC_FAIL -100

#define INI 0
#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define SHOW 5
#define DELETE 6
#define LEN 7
#define CHECK 8
#define POP 9

typedef struct  s_stack
{
	int *data;
	int size;
	int len;
	int head;
	int tail;
	int err;
}               t_stack;

typedef struct  s_array
{
	int *data;
	int size;
	int len;
	int head;
	int tail;
	int err;
}               t_array;

typedef struct	s_databox
{
	int *data;
	int min;
	int size;
	int mid;
	struct s_databox *left;
	struct s_databox *right;
}				t_databox;

typedef struct s_tree
{
	int aorb;
	int lorr;
	int min;
	int mid;
	int size;
	int isbottom;
	int is_rotate_left;
	int is_largest;
	int tree_num;
	struct s_tree *left;
	struct s_tree *right;
	struct s_tree *parent;
}				t_tree;

typedef struct	s_all
{
	t_databox *databox_a;
	t_databox *databox_b;
	int index_a;
	int index_b;
	int num_a;
	int num_b;
	t_tree *tree;
	int size;
}				t_all;
void *ft_malloc(int size);
void record_ans(int aorb, int ans);
int     ini_array(char c, int size);
void split_by_mid4first(int n, int mid);
void make_child4first(t_tree *tree, int largest);
void push_swap_first_process(t_all *all, t_tree *tree);
void	ft_bzero(void *s, int size);
int     pop_process(t_stack *stack);
int    push_process(t_stack *stack, int data);
int		rotate_process(t_stack *stack);
int		reverse_rotate_process(t_stack *stack);
int		show_process(t_stack *stack);
int		stack_ini_process(t_stack *stack, int size);
int		delete_process(t_stack *stack);
int swap_top_process(t_stack *stack);
int     stack(int i, int mode, int data);
int     pop(int i);
void    push(int i, int data);
void	stack_len(int i);
int     ini_stack(int i, int size, int *array);
void	rotate_stack(int i);
void	reverse_rotate_stack(int i);
void	show_stack(int i);
int	delete_stack(int i);
void swap_top(int i);
int check_top(int i);
void multi_record_stack2(int aorb, int tmp);
void multi_record_stack(int aorb, long long int reversed_processes);
void multi_rotate_record_stack(int aorb, int n);
void multi_rr_record_stack(int n);
void split_by_mid(int aorb, int n, int mid, int tree_num);
void update_databox(int aorb, t_all *all);
void push_swap_first(t_all *all);
void push_swap_last4_a();
void push_swap_last4_b();
void push_swap_last3(int aorb);
void push_swap_ini(t_all *all);
void push_swap_last_process(t_tree *tree);
void make_child(t_tree *tree);
int push_swap_process(t_tree *tree, t_tree *tmp);
void push_swap_main(t_all *all);

#endif
