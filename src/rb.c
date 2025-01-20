/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:28:54 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:28:54 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	rotate_b(t_list **stack_two)
{
	t_list	*head;
	t_list	*cursor;

	if (!stack_two || !(*stack_two) || !(*stack_two)->next)
		return ;
	ft_printf("rb\n");
	head = *stack_two;
	*stack_two = (*stack_two)->next;
	cursor = ft_lstlast(*stack_two);
	cursor->next = head;
	head->next = NULL;
}
