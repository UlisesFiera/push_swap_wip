/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:31:53 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:31:53 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	reverse_rotate_a(t_list **stack_one)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*current;

	if (!stack_one || !(*stack_one) || !(*stack_one)->next)
		return ;

	ft_printf("rra\n");

	// Find the last node with valid content
	current = *stack_one;
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
	last->next = *stack_one;
	*stack_one = last;
}