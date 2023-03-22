/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:33:21 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/15 13:57:37 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./lib/push_swap.h"

// void	print_stack(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->len_a)
// 	{
// 		ft_printf("posizione %d -> %d \n", i, stack->a[i]);
// 		i++;
// 	}
// }

void	ft_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = start(argc, argv);
	if (!check_doubles(stack))
		ft_exit(stack);
	if (is_sorted(stack))
		ft_exit(stack);
	sort(stack);
	// print_stack(stack);
	ft_exit(stack);
	return (0);
}
