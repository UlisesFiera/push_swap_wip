/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:10:20 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/18 17:19:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_LIB_H
# define PUSH_LIB_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

long	ft_atol(const char *string);
int		populate_a(t_stack **a, char **argv);
int		is_sorted(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
int		stack_size(t_stack *stack);
t_stack	*find_biggest_node(t_stack *stack);
t_stack	*find_smallest_node(t_stack *stack);
void	push(t_stack **src, t_stack **dst, char *operation);
void	reverse_rotate(t_stack **stack, char *operation);
void	reverse_rotate_both(t_stack **a, t_stack **b);
void	reverse_rotate_operation(t_stack **a, t_stack **b,
			t_stack *cheapest_node);
void	rotate(t_stack **stack, char *operation);
void	rotate_both(t_stack **a, t_stack **b);
void	rotate_operation(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	swap(t_stack **stack, char *operation);
void	swap_both(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);
int		append_node(t_stack **stack, int number);
int		check_duplicate(t_stack *stack, int number);
int		check_syntax(char *argv);
void	set_index(t_stack *stack);
void	stack_a_setup(t_stack *a, t_stack *b);
void	stack_b_setup(t_stack *a, t_stack *b);
void	sort_stacks(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);

#endif