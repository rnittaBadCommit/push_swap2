#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# define LEN_NOT_POSITIVE -1
# define LEN_OVER_SIZE -2;

#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define REVERSE_ROTATE 4
#define POP 9

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
	int min;
	int mid;
	int size;
	int isbottom;
	struct s_tree *left;
	struct s_tree *right;
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



	void    push_process(t_array *array, int data);
	int     pop_process(t_array *array);
	int     array(char c, int mode, int data);
	void    push(char c, int data);
	int     pop(char c);
int     ini_array(char c, int size);

#endif