/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:49:05 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/04 09:49:05 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_lib.h"

void	reverse_rotate(t_stack **stack, char *operation)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	(*stack)->prev = last_node;
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
	if (!ft_strncmp(operation, "rra", 3))
		ft_printf("rra\n");
	if (!ft_strncmp(operation, "rrb", 3))
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "rrs");
	reverse_rotate(b, "rrs");
	ft_printf("rrs\n");
}

void	reverse_rotate_operation(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		reverse_rotate_both(a, b);
	set_index(*a);
	set_index(*b);
}