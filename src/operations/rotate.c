/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:31:10 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/03 17:31:10 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_lib.h"

void	rotate(t_stack **stack, char *operation)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	*stack = (*stack)->next;
	last_node->next = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev->prev = last_node;
	(*stack)->prev = NULL;
	if (!ft_strncmp(operation, "ra", 2))
		ft_printf("ra\n");
	if (!ft_strncmp(operation, "rb", 2))
		ft_printf("rb\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, "rr");
	rotate(b, "rr");
	ft_printf("rr\n");
}

void	rotate_operation(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rotate_both(a, b);
	set_index(*a);
	set_index(*b);
}
