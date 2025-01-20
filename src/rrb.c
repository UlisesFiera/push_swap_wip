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

	if (!stack_two || !(*stack_two) || !(*stack_two)->next)
		return ;
	ft_printf("rrb\n");
	second_last = *stack_two;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_two;
	*stack_two = last;
}
