/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:29:22 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/15 12:29:24 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./lib/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;
	int	len;

	len = stack->len_a;
	i = 0;
	while (i < len)
	{
		if (stack->a[i] > stack->a[i + 1] && i + 1 < len)
			return (0);
		i++;
	}
	ft_exit(stack);
	return (1);
}

void	sort_3nb(t_stack *stack)
{
	if ((stack->a[0] > stack->a[1]) && (stack->a[0] < stack->a[2])
		&& (stack->a[1] < stack->a[2]))
		swap_a(stack, 1);
	else if ((stack->a[1] < stack->a[0]) && (stack->a[1] < stack->a[2])
		&& (stack->a[0] > stack->a[2]))
		rotate_a(stack, 1);
	else if ((stack->a[1] > stack->a[0]) && (stack->a[1] > stack->a[2])
		&& (stack->a[2] < stack->a[0]))
		rra(stack, 1);
	else if ((stack->a[0] > stack->a[1]) && (stack->a[0] > stack->a[2])
		&& (stack->a[1] > stack->a[2]))
	{
		swap_a(stack, 1);
		rra(stack, 1);
	}
	else if ((stack->a[1] > stack->a[0]) && (stack->a[1] > stack->a[2])
		&& (stack->a[0] < stack->a[2]))
	{
		swap_a(stack, 1);
		rotate_a(stack, 1);
	}
}

void	sort(t_stack *stack)
{
	if (!check_sorted_asc(stack->a, stack->len_a))
	{
		if (stack->len_a == 2)
			swap_a(stack, 1);
		else if (stack->len_a == 3)
			sort_3nb(stack);
		else
			quick_sort_a(stack, stack->len_a, 0);
	}
}
