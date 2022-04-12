#include <stdio.h>

//	a->b  1, b->a  1<<1,
//  a_rotate  1<<6, a_rev_rotate  1<<7,
//    b_rotate  5, b_rev_rotate  6


7 typedef struct s_databox
{
	int *data;
	int min;
	int size;
	s_databox *left;
	s_databox *right;
}				t_databox;

typedef struct s_ans
{
	int *data;
	int size;
}

#define STACK_A 0
#define STACK_B 1


void first_step(t_databox *me)
{
	if (me->data[0])
}

int free_tree(t_databox *me)
{
	int tmp;

	tmp = 1;
	if (me->left)
	{
		if (me->left->data)
		{
			if (me->right)
			{
				if (me->right->data)
				{
					free_tree(me->left);
					
					free(me->right->data);
				}
				free(me->right);
			}
			free(me->left->data);
		}
		free(me->left);
	}
}

int make_tree(t_databox *me)
{
	if (me->size > 1)
	{
		me->left->min = me->min;
		me->right->min = me->min + me->size / 2;
		me->left->size = me->size/ 2;
		me->right->size = me->size - me->left->size;
		if (!(me->left = (t_databox *)malloc(sizeof(t_databox))))
			me->left = NULL;
		else if (!(me->left->data = (int *)malloc(me->left->size * sizeof(int *))))
			me->left->data = NULL;
		else if (!(me->right = (t_databox *)malloc(sizeof(t_databox))))
			me->right = NULL;
		else if (!(me->right->data = (int *)malloc(me->right->size * sizeof (int *))))
			me->right->data = NULL;
		else if (!make_tree(me->left))
			return (make_tree(me->right));
		return (-1);
	}
	me->left = NULL;
	return (0);
}

void free_tree(t_databox me)
{
	
}


void push_swap_process(t_databox me, int aorb)
{
	int i;

	i = -1;
	if (me.size > 1)
	{
		while (++i < me.size)
		{
			if (check_top('a') < me.right.min)
				record_ans(aorb, ROTATE);
			else
				record_ans(aorb, PUSH);
				record_ans(aorb, PUSH);
		}
		push_swap_process(me.left, aorb);
		push_swap_process(me.right, !aorb);
	}
}

void push_swap_main()
{

}



int aorb(int data)
{
	if (data == a)
		return (STACK_A);
	else
		return (STACK_B);
}

int cnt_a_size(ans original_ans)
{
	int i;
	int cnt;

	i = -1;
	cnt = 0;
	while (++i < original_ans)
		if (aorb(original_ans.data[i]) == STACK_A)
			cnt++;
	return (cnt);
}

void input_each_ans(ans original_ans, ans *new_ans)
{
	int i_data[2];
	int i_order[2];
	int j;
	int tmp[2];

	ft_bzero(i_data, sizeof(int) * 2);
	ft_bzero(i_order, sizeof(int) * 2);
	j = 0;
	if ((tmp[0] = aorb(original_ans.data[0])) == STACK_A)
		new_ans[0].order[i_order[0]++] = 0;
	else
		new_ans[1].order[i_order[1]++] = 0;
	while (++j < original_ans.size)
		if ((tmp[1] = aorb(original_ans.data[j])) == STACK_A)
		{
			new_ans[0].data[i_data[0]] = original_ans.data[j];
			if (tmp[0] != tmp[1])
				new_ans
		else
			new_ans[1].data[i_data[1]] = original_ans.data[j];
}

ans *make_each_ans(ans original_ans)
{
	ans *new_ans;
	int i;

	if (!(new_ans = (ans *)malloc(sizeof(ans) * 2)))
		return (NULL);
	new_ans[0].size = cnt_a_size(original_ans);
	new_ans[1].size = original_ans.size - new_ans[1].size;
	if (!(new_ans[0].data = (int *)malloc(sizeof(int) * new_ans[0].size)))
	{
		free(new_ans);
		return (NULL);
	}
	if (!(new_ans[1].data = (int *)malloc(sizeof(int) * new_ans[0].size)))
	{
		free(new_ans[0].data);
		free(new_ans);
		return (NULL);
	}
	input_each_ans(original_ans, new_ans);
	return (new_ans);
}



void make_shoter(ans ans)
{
	int i;
	int j;
	int tmp;
	int save_;

	i = -1;
	while (++i < ans.size)
	{
		j = -1;
		while ((tmp = ans.data[i + ++j]) != PUSH_A && tmp != PUSH_B)
		{
			
		}
	}
}