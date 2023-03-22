/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:33:21 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/15 13:57:37 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/push_swap.h"

void	quick_sort_3ab(t_stack *stack, int dim)
{
	if (dim == 3 && stack->len_a == 3)
		sort_3nb(stack);
	else if (dim == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, 1);
	}
	else if (dim == 3)
	{
		while (dim != 3
			|| !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack, 1);
			else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				dim = when_push(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack, 1);
			else if (dim++)
				push_a(stack, 1);
		}
	}
}

int	partition(int *pivot, int *stack, int dim)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < dim)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}

int	sort_3_b(t_stack *stack, int dim)
{
	if (dim == 1)
		push_a(stack, 1);
	else if (dim == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack, 1);
		while (dim--)
			push_a(stack, 1);
	}
	else if (dim == 3)
	{
		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 1 && stack->a[0] > stack->a[1])
				swap_a(stack, 1);
			else if (dim == 1
				|| (dim >= 2 && stack->b[0] > stack->b[1])
				|| (dim == 3 && stack->b[0] > stack->b[2]))
				dim = when_push(stack, dim, 0);
			else
				swap_b(stack, 1);
		}
	}
	return (0);
}

int	quick_sort_b(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && check_sorted_desc(stack->b, dim) == 1)
		while (dim--)
			push_a(stack, 1);
	if (dim <= 3)
	{
		sort_3_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!partition(&pivot, stack->b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if (stack->b[0] >= pivot && dim--)
			push_a(stack, 1);
		else if (++count_r)
			rotate_b(stack, 1);
	}
	while (numbers / 2 != stack->len_b && count_r--)
		rrb(stack, 1);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
}

int	quick_sort_a(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted_asc(stack->a, dim) == 1)
		return (1);
	numbers = dim;
	if (dim <= 3)
	{
		quick_sort_3ab(stack, dim);
		return (1);
	}
	if (!count_r && !partition(&pivot, stack->a, dim))
		return (0);
	while (dim != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (dim--))
			push_b(stack, 1);
		else if (++count_r)
			rotate_a(stack, 1);
	}
	while (numbers / 2 + numbers % 2 != stack->len_a && count_r--)
		rra(stack, 1);
	return (quick_sort_a(stack, numbers / 2 + numbers % 2, 0)
		&& quick_sort_b(stack, numbers / 2, 0));
	return (1);
}
