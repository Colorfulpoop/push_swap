/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:29:25 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/23 10:29:26 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./lib/push_swap.h"

int	av_len(char **av)
{
	int	size;

	size = 0;
	while (av[size])
		size++;
	return (size);
}

void	ft_exitb(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	exit(0);
}

void	order(t_stack *stack)
{
	if (check_sorted_asc(stack->a, stack->len_a) == 1)
		ft_printf("OK \n");
	else
		ft_printf("KO \n");
}
