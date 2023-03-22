/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:46:45 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:14:48 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	rra(t_stack *stack, int flag)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->len_a - 1];
	len = stack->len_a;
	while (len > 0)
	{
		stack->a[len] = stack->a[len - 1];
		len--;
	}
	stack->a[0] = tmp;
	if (flag == 1)
		ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack *stack, int flag)
{
	int	len;
	int	tmp;

	tmp = stack->b[stack->len_b - 1];
	len = stack->len_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	if (flag == 1)
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack *stack, int flag)
{
	int	len;
	int	tmp;

	tmp = stack->a[stack->len_a - 1];
	len = stack->len_a;
	while (len-- > 0)
		stack->a[len] = stack->a[len - 1];
	stack->a[0] = tmp;
	tmp = stack->b[stack->len_b - 1];
	len = stack->len_b;
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
	if (flag == 1)
		ft_printf("rrr\n");
	return (1);
}
