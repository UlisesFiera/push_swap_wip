/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:42:00 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/03 16:42:00 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	sort_three(t_stack **stack)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest_node(*stack);
	if (*stack == biggest_node)
		rotate(stack, "ra");
	else if ((*stack)->next == biggest_node)
		reverse_rotate(stack, "rra");
	if ((*stack)->number > (*stack)->next->number)
		swap(stack, "sa");
}