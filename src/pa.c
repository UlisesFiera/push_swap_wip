/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:35:48 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/19 21:35:48 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	push_a(t_list **stack_one, t_list **stack_two)
{
	t_list	*pushed_node;

	if (*stack_two == NULL)
		return ;
	ft_printf("pa\n");
	pushed_node = *stack_two;
	*stack_two = (*stack_two)->next;
	ft_lstadd_front(stack_one, pushed_node);
}
