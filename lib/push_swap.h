/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:34:39 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/13 16:34:40 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_stack;

void	ft_exit(t_stack *stack);
void	fill_stack(int len, char **argv, int flag, t_stack *stack);
void	sort(t_stack *stack);
void	sort_3nb(t_stack *stack);
void	tmp_sort(int *tmp_stk, int dim);
void	print_error(int *stack);
void	checkdb_error(t_stack *stack);

int		check_sorted_desc(int *stack, int dim);
int		check_sorted_asc(int *stack, int dim);
int		when_push(t_stack *stack, int dim, int f);
int		is_sorted(t_stack *stack);
int		swap_a(t_stack *stack, int flag);
int		swap_b(t_stack *stack, int flag);
int		swap_ss(t_stack *stack, int flag);
int		rra(t_stack *stack, int flag);
int		rrb(t_stack *stack, int flag);
int		rrr(t_stack *stack, int flag);
int		rotate_a(t_stack *stack, int flag);
int		rotate_b(t_stack *stack, int flag);
int		rotate_rr(t_stack *stack, int flag);
int		push_a(t_stack *stack, int flag);
int		push_b(t_stack *stack, int flag);
int		check_doubles(t_stack *stack);
int		quick_sort_a(t_stack *stack, int dim, int count_r);
int		ft_isdigit(int c);
int		ft_atoi(char *str, int *stack);

t_stack	*start(int argc, char **argv);

#endif
