/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:32:01 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:32:01 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	reverse_rotate_b(t_list **stack_two)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*current;

	if (!stack_two || !(*stack_two) || !(*stack_two)->next)
		return ;

	ft_printf("rrb\n");

	// Find the last node with valid content
	current = *stack_two;
	last = NULL;
	second_last = NULL;
	while (current)
	{
		if (current->content)
		{
			second_last = last;
			last = current;
		}
		current = current->next;
	}

	// If no valid content node is found, or only one valid node exists, return
	if (!last || !second_last)
		return;

	// Perform the reverse rotation
	second_last->next = NULL;
	last->next = *stack_two;
	*stack_two = last;
}


