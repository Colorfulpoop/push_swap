/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:51:58 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:29:01 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	swap_a(t_stack *stack, int flag)
{
	int		tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	return (1);
}

int	swap_b(t_stack *stack, int flag)
{
	int		tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (flag == 1)
		ft_printf("sb\n");
	return (1);
}

int	swap_ss(t_stack *stack, int flag)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (flag == 1)
		ft_printf("ss\n");
	return (1);
}
