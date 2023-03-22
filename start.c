/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:04:22 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/15 12:04:29 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./lib/push_swap.h"

int	check_doubles(t_stack *stack)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = stack->len_a;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack->a[i] == stack->a[j])
			{
				checkdb_error(stack);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	fill_stack(int len, char **argv, int flag, t_stack *stack)
{
	int	count;

	count = 0;
	stack->a = (int *)malloc((len) * sizeof(int));
	stack->b = (int *)malloc((len) * sizeof(int));
	while (flag < len)
	{
			stack->a[count] = ft_atoi(argv[flag], stack->a);
			count++;
			flag++;
	}
	stack->len_a = count;
	stack->len_b = 0;
}

t_stack	*start(int argc, char **argv)
{
	char	**tmp;
	int		len;
	t_stack	*stack;

	len = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[len] != NULL)
				len++;
		stack = malloc(len * sizeof(t_stack));
		fill_stack(len, tmp, 0, stack);
		len = 0;
		while (tmp[len])
			free(tmp[len++]);
		free(tmp);
	}
	else if (argc >= 3)
	{
		stack = malloc((argc - 1) * sizeof(t_stack));
		fill_stack(argc, argv, 1, stack);
	}
	else
		return (0);
	return (stack);
}
