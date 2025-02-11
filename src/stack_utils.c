/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:59:19 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/02 18:59:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

t_stack *find_cheapest(t_stack *stack)
{
	if (!stack)
		return NULL;
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;	
	}
	return (NULL);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*find_biggest_node(t_stack *stack)
{
	long		biggest_number;
	t_stack		*biggest_node;
	
	biggest_number = -2147483648;
	while (stack)
	{
		if (stack->number > biggest_number)
		{
			biggest_number = stack->number;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

t_stack	*find_smallest_node(t_stack *stack)
{
	long		smallest_number;
	t_stack		*smallest_node;
	
	smallest_number = 2147483647;
	while (stack)
	{
		if (stack->number < smallest_number)
		{
			smallest_number = stack->number;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}