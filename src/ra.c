/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:12:10 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:12:10 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	rotate_a(t_list **stack_one)
{
	t_list	*head;
	t_list	*cursor;

	if (!stack_one || !(*stack_one) || !(*stack_one)->next)
		return ;
	ft_printf("ra\n");
	head = *stack_one;
	*stack_one = (*stack_one)->next;
	cursor = ft_lstlast(*stack_one);
	cursor->next = head;
	head->next = NULL;
}
