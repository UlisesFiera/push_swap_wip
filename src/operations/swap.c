/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:16:39 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/03 16:16:39 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_lib.h"

void	swap(t_stack **stack, char *operation)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	if (!ft_strncmp(operation, "sa", 2))
		ft_printf("sa\n");
	if (!ft_strncmp(operation, "sb", 2))
		ft_printf("sb\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, "ss");
	swap(b, "ss");
	ft_printf("ss\n");
}
