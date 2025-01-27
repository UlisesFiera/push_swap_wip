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

void	perform_operation_a(t_list **stack_one, t_list **stack_two, int winner, int targets, int size)
{
	int	median;
	int	i;

	//ft_printf("winner : %i\n", winner);
	median = size / 2;
	i = 0;
	//ft_printf("target : %i\n", targets);
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
	size = stack_size(stack_two);
	//ft_printf("test : %i\n", size);
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

int	find_target_a(t_list **stack_two, int stack_one_value)
{
	t_list	*cursor;
	int		target_node;
	int		node_value;
	int		i;
	int		j;

	cursor = *stack_two;
	target_node = -1;
	i = 0;
	while (cursor)
	{
		if (cursor->content)
		{
			if (*(int *)cursor->content < stack_one_value)
			{
				node_value = *(int *)cursor->content;
				target_node = i;
			}
			i++;
		}
		cursor = cursor->next;
	}
	if (target_node == -1)
	{
		cursor = *stack_two;
		target_node = 0;
		node_value = *(int *)cursor->content;
		i = 0;
		while (cursor)
		{
			if (cursor->content)
			{
				if (*(int *)cursor->content > node_value)
				{
					node_value = *(int *)cursor->content;
					target_node = i;
				}
				i++;
			}
			cursor = cursor->next;
		}
		return (target_node);
	}
	cursor = *stack_two;
	j = 0;
	while (cursor)
	{
		if (cursor->content)
		{
			//ft_printf("cursor content: %i\n", *(int *)cursor->content);
			//ft_printf("stack_one value: %i node_value: %i next node_value: %i\n", stack_one_value, node_value, *(int *)cursor->content);
			if ((*(int *)cursor->content < stack_one_value) && (*(int *)cursor->content > node_value))
			{
				node_value = *(int *)cursor->content;
				target_node = j;
			}
			j++;
		}
		cursor = cursor->next;
	}
	return (target_node);
}

int	node_movement_cost(t_list **stack_two, int node, int size, int targets)
{
	int	cost;
	int	median;

	median = size / 2;
	cost = 0;

	if (node <= median)
		cost += node;
	else
		cost += size - node;
	if (node == targets)
		return (cost);
	size = stack_size(stack_two);
	if (targets == 1 || targets == size - 1)
		return (cost + 1);
	else
	{
		//ft_printf("cost of node %i target %i is %i\n", node, targets, cost);
		median = size / 2;
		if (targets <= median)
			return (cost += targets);
		else
			return (cost += (size - targets));
	}
}

void	operation_a(t_list **stack_one, t_list **stack_two, int size, int *target)
{
	int	cheapest;
	int	next_cost;
	int	node;
	int	winner;

	if (target[0] == 0)
			return (push_b(stack_one, stack_two));
	node = 0;
	cheapest = node_movement_cost(stack_two, node, size, target[0]);
	//ft_printf("Node position %i cost %i\n", node, cheapest);
	winner = 0;
	node++;
	while (node < size)
	{
		next_cost = node_movement_cost(stack_two, node, size, target[node]);
		if (next_cost < cheapest)
		{
			cheapest = next_cost;
			winner = node;
			//ft_printf("new node position %i cost %i", node, cheapest);
		}
		node++;
	}
	//ft_printf("target : %i\n", target[winner]);
	perform_operation_a(stack_one, stack_two, winner, target[winner], size);
}

void	push_cheap(t_list **stack_one, t_list **stack_two, int size)
{
	t_list	*cursor;
	int		target_node;
	int		*positions;
	int		i;

	positions = malloc(sizeof(int) * size);
	cursor = *stack_one;
	i = 0;
	while (cursor && cursor->content)
	{
		target_node = find_target_a(stack_two, *(int *)cursor->content);
		//ft_printf("Node %i has target target %i\n", *(int *)cursor->content, target_node);
		cursor = cursor->next;
		positions[i] = target_node;
		i++;
	}
	operation_a(stack_one, stack_two, size, positions);
	free(positions);
	return ;
}

void	sort_three(t_list **stack_one)
{
	t_list	*cursor;
	int		max_value;
	int		position;
	int		i;

	cursor = *stack_one;
	max_value = *(int *)cursor->content;
	i = 1;
	position = 0;
	cursor = cursor->next;
	while (i < 3)
	{
		if (*(int *)cursor->content > max_value)
		{
			max_value = *(int *)cursor->content;
			position = i;
		}
		cursor = cursor->next;
		i++;
	}
	if (position == 0)
		rotate_a(stack_one);
	else if (position == 1)
		reverse_rotate_a(stack_one);
	cursor = *stack_one;
	if (*(int *)cursor->content > *(int *)cursor->next->content)
		swap_a(stack_one);
}

int	find_target_b(t_list **stack_one, int stack_two_value)
{
	t_list	*cursor;
	int		target_node;
	int		node_value;
	int		i;

	cursor = *stack_one;
	target_node = -1;
	i = 0;
	while (cursor)
	{
		if (cursor->content)
		{
			if (*(int *)cursor->content > stack_two_value)
			{
				node_value = *(int *)cursor->content;
				target_node = i;
			}
			i++;
		}
		cursor = cursor->next;
	}
	if (target_node == -1)
	{
		cursor = *stack_one;
		target_node = 0;
		node_value = *(int *)cursor->content;
		i = 0;
		while (cursor)
		{
			//ft_printf("target node %i\n", target_node);
			//ft_printf("node %i\n", *(int *)cursor->content);
			if (cursor->content)
			{
				if (*(int *)cursor->content < node_value)
				{
					node_value = *(int *)cursor->content;
					target_node = i;
				}
				i++;
			}
			cursor = cursor->next;
		}
		return (target_node);
	}
	cursor = *stack_one;
	i = 0;
	while (cursor)
	{
		if (cursor->content)
		{
			if (*(int *)cursor->content > stack_two_value && *(int *)cursor->content < node_value)
			{
				node_value = *(int *)cursor->content;
				target_node = i;
			}
			i++;
		}
		cursor = cursor->next;
	}
	return (target_node);
}

void	operation_b(t_list **stack_one, t_list **stack_two, int target_node)
{
	int	median;
	int	i;

	if (target_node == 0)
	{
		push_a(stack_one, stack_two);
		return ;
	}
	median = stack_size(stack_one) / 2;
	i = 0;
	if (target_node <= median)
	{
		while (i < target_node)
		{
			rotate_a(stack_one);
			i++;
		}
		push_a(stack_one, stack_two);
		return ;
	}
	else
	{
		while (i < stack_size(stack_one) - target_node)
		{
			reverse_rotate_a(stack_one);
			i++;
		}
		push_a(stack_one, stack_two);
		return ;
	}
}

void    clean_null_nodes(t_list **head)
{
	t_list	*current;
	t_list	*prev;
	t_list	*to_free;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (!current->content)
		{
			to_free = current;
            if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			current = current->next;
			free(to_free);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

void	push_back(t_list **stack_one, t_list **stack_two)
{
	t_list	*cursor;
	int		target_node;

	cursor = *stack_two;
	while (cursor && cursor->content)
	{
		target_node = find_target_b(stack_one, *(int *)cursor->content);
		//ft_printf("Node %i has target target %i\n", *(int *)cursor->content, target_node);
		operation_b(stack_one, stack_two, target_node);
		cursor = *stack_two;
	}
}

void	check_tail(t_list **stack_one)
{
	t_list	*cursor;
	t_list	*last;

	cursor = *stack_one;
	while (cursor)
	{
		if (cursor->content)
			last = cursor;
		cursor = cursor->next;
	}
	//ft_printf("hey %i\n", *(int *)cursor->content);
	while (*(int *)(*stack_one)->content > *(int *)last->content)
	{
		reverse_rotate_a(stack_one);
		cursor = *stack_one;
		while (cursor)
		{
			if (cursor->content)
				last = cursor;
			cursor = cursor->next;
		}
	}
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
		size--;
	}
	sort_three(stack_one);
	push_back(stack_one, stack_two);
	check_tail(stack_one);
}