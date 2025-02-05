/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:28:02 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/02 17:28:02 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	append_node(t_stack **stack, int number)
{
	t_stack		*new_node;
	t_stack		*last_node;

	if (!stack)
		return (1);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (1);
	new_node->number = number;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
		return (0);
	}
	last_node = find_last_node(*stack);
	last_node->next = new_node;
	new_node->prev = last_node;
	return (0);
}

// We position the new number inside a node in our list

// We put it as the head is it's the first, or at the end otherwise, pointing to
// the previous one as such.