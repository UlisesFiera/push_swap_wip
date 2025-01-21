/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:40 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 18:02:40 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	perform_operation(t_list **stack_one, t_list **stack_two, int winner, int targets, int size)
{
	int	median;
	int	i;

	median = size / 2;
	i = 0;
	if (winner <= median)
	{
		while (i < winner)
		{
			if (winner == targets)
				rotate_both(stack_one, stack_two);
			else
				rotate_a(stack_one);
			i++;
		}
	}
	else
	{
		while (i < size - winner)
		{
			if (winner == targets)
				reverse_rotate_both(stack_one, stack_two);
			else
				reverse_rotate_a(stack_one);
			i++;
		}
	}
	if (winner == targets)
	{
		push_b(stack_one, stack_two);
		return ;
	}
	size = ft_lstsize(*stack_two);
	if (targets == 1) 
	{
		rotate_b(stack_two);
		push_b(stack_one, stack_two);
		return ;
	}
	else if (targets == size - 1)
	{
		reverse_rotate_b(stack_two);
		push_b(stack_one, stack_two);
		return ;
	}
	median = size / 2;
	i = 0;
	if (targets <= median)
	{
		while (i < targets)
		{
			rotate_b(stack_two);
			i++;
		}
	}
	else
	{
		while (i < size - targets)
		{
			reverse_rotate_b(stack_two);
			i++;
		}
	}
	push_b(stack_one, stack_two);
}

int		target_node_calculation(t_list **stack_two, t_list *cursor_one)
{
	int		stack_one_node_value;
	int		stack_two_node_value;
	int		value;
	int		position;
	int		i;
	t_list	*cursor_two;

	// we save the int of the node given from stack a
	stack_one_node_value = *(int *)cursor_one->content;
	// we initialise the value variable with that int
	value = stack_one_node_value;
	cursor_two = *stack_two;
	position = 0;
	i = 0;
	while (cursor_two->content != NULL)
	{
		// we get the int of each node of the stack b
		stack_two_node_value = *(int *)cursor_two->content;
		// if it's smaller, we save that int into value to compare later, and the position of such node within the list
		if (stack_two_node_value < stack_one_node_value)
		{
			value = stack_two_node_value;
			position = i;
		}
		cursor_two = cursor_two->next;
		i++;
	}
	// if the loop found anything smaller than the int of the stack a node...
	cursor_two = *stack_two;
	if (value < stack_one_node_value)
	{
		//ft_printf("Content %i\n", *(int *)cursor_two->content);
		//ft_printf("Value %i\n", value);
		//ft_printf("Value %i\n", stack_one_node_value);
		i = 0;
		while (cursor_two->content != NULL)
		{
			stack_two_node_value = *(int *)cursor_two->content;
			// we look again for a value smaller, but at the same time bigger than the last smaller found
			if (stack_two_node_value < stack_one_node_value && stack_two_node_value > value)
			{
				value = stack_two_node_value;
				position = i;
			}
			cursor_two = cursor_two->next;
			i++;
			// all this is because we need to initialize value to something and it has to be something 
			// smaller than the stack a int, and we dont know what that int is
		}
		//ft_printf("Position %i\n", position);
		return (position);
	}
	
	// if there is nothing smaller, we just look for the bigest;
	else
	{
		cursor_two = *stack_two;
		position = 0;
		i = 0;
		while (cursor_two->content != NULL)
		{
			stack_two_node_value = *(int *)cursor_two->content;
			if (stack_two_node_value > value)
			{
				value = stack_two_node_value;
				position = i;
			}
			cursor_two = cursor_two->next;
			i++;
		}
	}
	return (position);
}

int	stack_two_size(t_list **stack_two)
{
	t_list	*cursor;
	int		size;
	
	if (!stack_two)
		return (-1);
	size = 0;
	cursor = *stack_two;
	while (cursor->content != NULL)
	{
		size++;
		cursor = cursor->next;
	}
	return (size);
}

int	node_movement_cost(t_list **stack_two, int node, int size, int targets)
{
	int	cost;
	int	median;

	median = size / 2;
	cost = 0;
	// we calculate the number of ra or rra based on the position to the median
	if (node <= median)
		cost += node;
	else
		cost += size - node;
	// if node and target are the same, the cost is the same as moving just one cause we can rrs and rs
	if (node == targets)
		return (cost);
	size = stack_two_size(stack_two);
	ft_printf("CALCULATING: size %i\n", size);
	// if the target is at the top-1 or bottom, cost will be the same + 1
	if (targets == 1 || targets == size - 1)
		return (cost + 1);
	else
	{
		median = size / 2;
		if (targets <= median)
			return (cost += targets);
		else
			return (cost += (size - targets));
	}
}

void	operation(t_list **stack_one, t_list **stack_two, int size, int *targets)
{
	int	cheapest;
	int	next_cost;
	int	node;
	int	winner;

	if (targets[0] == 0)
			return (push_b(stack_one, stack_two));
	node = 0;
	cheapest = node_movement_cost(stack_two, node, size, targets[node]);
	ft_printf("Node %i has cost %i\n", node, cheapest);
	winner = node;
	node++;
	while (node < size)
	{
		next_cost = node_movement_cost(stack_two, node, size, targets[node]);
		ft_printf("Node %i has cost %i\n", node, next_cost);
		if (next_cost < cheapest)
		{
			cheapest = next_cost;
			winner = node;
		}
		node++;
	}
	ft_printf("Winner is %i\n", winner);
	perform_operation(stack_one, stack_two, winner, targets[winner], size);
}

void	push_cheap(t_list **stack_one, t_list **stack_two, int size)
{
	t_list	*cursor_one;
	int		*targets;
	int		i;

	cursor_one = *stack_one;
	targets = malloc(sizeof(int) * size);
	i = 0;
	while (cursor_one != NULL)
	{
		// i will be the node and the value the target node's position in the b list
		targets[i] = target_node_calculation(stack_two, cursor_one);
		ft_printf("Node %i has target %i\n", i, targets[i]);
		i++;
		cursor_one = cursor_one->next;
	}
	operation(stack_one, stack_two, size, targets);
	free(targets);
	return ;
}

void	talgo(t_list **stack_one, t_list **stack_two)
{
	int	size;
	
	size = ft_lstsize(*stack_one);
	if (size > 3)
	{
		if (size == 4)
			push_b(stack_one, stack_two);
		else
		{
			push_b(stack_one, stack_two);
			push_b(stack_one, stack_two);
			size--;
		}
		size--;
	}
	while (size > 3)
	{
		push_cheap(stack_one, stack_two, size);
		ft_printf("\nNEW OPERATION\n");
		size--;
	}
}