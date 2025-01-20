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

	if (!stack_one || !(*stack_one) || !(*stack_one)->next)
		return ;
	ft_printf("rra\n");
	second_last = *stack_one;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack_one;
	*stack_one = last;
}
