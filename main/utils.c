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

int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	count(int n)
{
	static int	c;

	c += n;
	return (c);
}

t_all	*all_save(t_all *all)
{
	static t_all	*save;

	if (!save)
		save = all;
	return (save);
}

int	ft_atoi(char *s, int *err_flag)
{
	long long int	ret;
	int				i;
	int				posi;

	ret = 0;
	i = -1;
	posi = 1;
	if (s[0] == '-' && i++)
		posi = -1;
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret = ret * 10 + s[i] - '0';
		else
		{
			*err_flag = 1;
			return (-1);
		}
		if ((posi == 1 && ret > 2147483647) || (posi == -1 && ret > 2147483648))
		{
			*err_flag = 1;
			return (-1);
		}
	}
	return (posi * ret);
}
