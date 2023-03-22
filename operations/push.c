/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:46:09 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:37:50 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	push_a(t_stack *stack, int flag)
{
	int	len;

	len = stack->len_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->len_a++;
	stack->a[0] = stack->b[0];
	len = 1;
	while (len < stack->len_b)
	{
		stack->b[len - 1] = stack->b[len];
		len++;
	}
	stack->len_b--;
	if (flag == 1)
		ft_printf("pa\n");
	return (1);
}

int	push_b(t_stack *stack, int flag)
{
	int	len;

	len = stack->len_b;
	while (len > 0)
	{
		stack->b[len] = stack->b[len - 1];
		len--;
	}
	stack->len_b++;
	stack->b[0] = stack->a[0];
	len = 1;
	while (len < stack->len_a)
	{
		stack->a[len - 1] = stack->a[len];
		len++;
	}
	stack->len_a--;
	if (flag == 1)
		ft_printf("pb\n");
	return (1);
}
