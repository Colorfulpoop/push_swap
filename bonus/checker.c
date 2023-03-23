/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:11:22 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/22 14:11:24 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lib/push_swap.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ex_operations(t_stack *stack, char *operation)
{
	if (ft_strcmp(operation, "sa\n"))
		swap_a(stack, 0);
	else if (ft_strcmp(operation, "sb\n"))
		swap_b(stack, 0);
	else if (ft_strcmp(operation, "ss\n"))
		swap_ss(stack, 0);
	else if (ft_strcmp(operation, "pa\n"))
		push_a(stack, 0);
	else if (ft_strcmp(operation, "pb\n"))
		push_b(stack, 0);
	else if (ft_strcmp(operation, "ra\n"))
		rotate_a(stack, 0);
	else if (ft_strcmp(operation, "rb\n"))
		rotate_b(stack, 0);
	else if (ft_strcmp(operation, "rr\n"))
		rotate_rr(stack, 0);
	else if (ft_strcmp(operation, "rra\n"))
		rra(stack, 0);
	else if (ft_strcmp(operation, "rrb\n"))
		rrb(stack, 0);
	else if (ft_strcmp(operation, "rrr\n"))
		rrr(stack, 0);
	return ;
}

void	read_operations(t_stack *stack)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		ex_operations(stack, operation);
		free (operation);
		operation = get_next_line(0);
	}
}

void	start_check(char **av)
{
	t_stack	stack;
	int		i;
	int		size;

	size = av_len(av);
	stack.a = (int *)malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.len_a = size;
	stack.b = (int *)malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.len_b = 0;
	i = 0;
	while (i < size)
	{
		stack.a[i] = ft_atoi(av[i], stack.a);
		i++;
	}
	read_operations(&stack);
	order(&stack);
	ft_exitb(&stack);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (ac == 2)
			ft_split(av[1], ' ');
		else
			av++;
		start_check(av);
	}
	return (0);
}
