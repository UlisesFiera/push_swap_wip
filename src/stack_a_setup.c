/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:52:57 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/04 10:52:57 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*cursor_b;
	t_stack	*target_node;
	long	small_closer_value;

	while (a)
	{
		small_closer_value = -2147483648;
		cursor_b = b;
		while (cursor_b)
		{
			if (cursor_b->number < a->number
				&& cursor_b->number > small_closer_value)
			{
				small_closer_value = cursor_b->number;
				target_node = cursor_b;
			}
			cursor_b = cursor_b->next;
		}
		if (small_closer_value == -2147483648)
			a->target = find_biggest_node(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	push_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = size_a - (a->index);
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += size_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = 2147483647;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	stack_a_setup(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	push_cost(a, b);
	set_cheapest(a);
}
