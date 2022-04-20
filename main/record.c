/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:36 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 01:23:55 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_ans(int aorb, int ans)
{
	if (ans == POP && aorb != 2)
		aorb = !aorb;
	if (ans == POP)
		ans = PUSH;
	if (ans == ROTATE)
		ans = REVERSE_ROTATE;
	else if (ans == REVERSE_ROTATE)
		ans = ROTATE;
	if (ans == REVERSE_ROTATE)
		write(1, "rr", 2);
	else
		write(1, "zspr" + ans, 1);
	if (aorb == 2)
		write(1, "zsprr" + ans, 1);
	else
		write(1, "ab" + aorb, 1);
	write(1, "\n", 1);
	count(1);
	if (aorb == 0 && ans == PUSH)
		write(1, "\n", 0);
}

void	multi_record_stack2(int aorb, int tmp, int flag)
{
	if (tmp == PUSH)
		push('a' + aorb, pop('a' + !aorb));
	else if (tmp == SWAP)
		swap_top('a' + aorb);
	else if (tmp == ROTATE)
		try_rr(&aorb, flag);
	else if (tmp == REVERSE_ROTATE)
		reverse_rotate_stack('a' + aorb);
	else if (tmp == POP)
		push('a' + !aorb, pop('a' + aorb));
	record_ans(aorb, tmp);
}

void	multi_record_stack(int aorb, long long int reversed_processes)
{
	long long int	processes;
	int				flag;

	processes = 0;
	flag = 1;
	while (reversed_processes)
	{
		processes = processes * 10 + reversed_processes % 10;
		reversed_processes /= 10;
	}
	while (processes)
	{
		if (processes % 10 == POP || processes % 10 == PUSH)
			flag = 0;
		multi_record_stack2(aorb, processes % 10, flag);
		processes /= 10;
	}
}

void	multi_rotate_record_stack(int aorb, int n)
{
	while (n--)
	{
		rotate_stack('a' + aorb);
		record_ans(aorb, ROTATE);
	}
}

void	multi_rr_record_stack(int n)
{
	while (n--)
	{
		rotate_stack('a');
		rotate_stack('b');
		record_ans(2, ROTATE);
	}
}
