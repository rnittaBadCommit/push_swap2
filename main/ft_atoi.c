/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:40:48 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 04:37:10 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(int *input, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (input[i] >= input[i + 1])
			return ;
	exit(0);
}

int	ft_atoi_err(int *err_flag)
{
	*err_flag = 1;
	return (-1);
}

int	ft_atoi(char *s, int *err_flag)
{
	long long int	ret;
	int				i;
	int				posi;
	int				flag;

	ret = 0;
	i = -1;
	posi = 1;
	flag = 1;
	if (s[0] == '-' && i++)
		posi = -1;
	while (s[++i])
	{
		flag = 0;
		if (s[i] >= '0' && s[i] <= '9')
			ret = ret * 10 + s[i] - '0';
		else
			ft_atoi_err(err_flag);
		if ((posi == 1 && ret > 2147483647) || (posi == -1 && ret > 2147483648))
			ft_atoi_err(err_flag);
	}
	if (flag)
		*err_flag = 1;
	return (posi * ret);
}
