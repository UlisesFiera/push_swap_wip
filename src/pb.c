/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:53:02 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/19 20:53:02 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	push_b(t_list **stack_one, t_list **stack_two)
{
	t_list	*pushed_node;

	if (*stack_one == NULL)
		return ;
	ft_printf("pb\n");
	pushed_node = *stack_one;
	*stack_one = (*stack_one)->next;
	ft_lstadd_front(stack_two, pushed_node);
}