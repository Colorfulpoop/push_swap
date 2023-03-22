/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <robegarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:49:10 by robegarc          #+#    #+#             */
/*   Updated: 2023/03/11 15:28:48 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

int	rotate_a(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->len_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	if (flag == 1)
		ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->b[0];
	while (++i < stack->len_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	if (flag == 1)
		ft_printf("rb\n");
	return (1);
}

/*ra and rb at the same time.*/
int	rotate_rr(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->a[0];
	while (++i < stack->len_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = tmp;
	i = -1;
	tmp = stack->b[0];
	while (++i < stack->len_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = tmp;
	if (flag == 1)
		ft_printf("rr\n");
	return (1);
}
