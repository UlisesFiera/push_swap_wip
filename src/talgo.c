/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:08:17 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/04 10:08:17 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	top_min(t_stack **a)
{
	t_stack	*smallest_node;

	smallest_node = find_smallest_node(*a);
	while ((*a)->number != smallest_node->number)
	{
		if (smallest_node->above_median)
			rotate(a, "ra");
		else
			reverse_rotate(a, "rra");
	}
}

void	move_node_top(t_stack **stack, t_stack *node_to_top, char stack_name)
{
	while (*stack != node_to_top)
	{
		if (stack_name == 'a')
		{
			if (node_to_top->above_median)
				rotate(stack, "ra");
			else 
				reverse_rotate(stack, "rra");
		}
		else if (stack_name == 'b')
		{
			if (node_to_top->above_median)
				rotate(stack, "rb");
			else 
				reverse_rotate(stack, "rrb");
		}
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	move_node_top(a, (*b)->target, 'a');
	push(b, a, "pa");
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_operation(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		reverse_rotate_operation(a, b, cheapest_node);
	move_node_top(a, cheapest_node, 'a');
	move_node_top(b, cheapest_node->target, 'b');
	push(a, b, "pb");
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size-- > 3 && !is_sorted(*a))
		push(a, b, "pb");
	if (size-- > 3 && !is_sorted(*a))
		push(a, b, "pb");
	while (size-- > 3 && !is_sorted(*a))
	{
		stack_a_setup(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		stack_b_setup(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	top_min(a);
}

// We need at least 2 nodes in b to perform the turkish algo, hence the initial ifs
// But if after pushing 1 or 2 nodes we end up with 3 nodes in a, we just sort
// them with sort_three cause the sorting of b is unnecesary.