/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:52:39 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/21 11:52:40 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./lib/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	print_error(int *stack)
{
	free(stack);
	ft_printf("Error \n");
	exit(0);
}

void	checkdb_error(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	ft_printf("Error \n");
	exit(0);
}

int	ft_atoi(char *str, int *stack)
{
	long int	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(stack);
		r = r * 10 + str[i++] - '0';
	}
	if (r > 2147483647 || r < -2147483647)
		print_error(stack);
	return (r * s);
}
