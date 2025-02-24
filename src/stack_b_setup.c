/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:36:24 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/24 12:48:42 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*cursor_a;
	t_stack	*target_node;
	long	big_closer_value;

	while (b)
	{
		big_closer_value = 2147483648;
		cursor_a = a;
		while (cursor_a)
		{
			if (cursor_a->number > b->number
				&& cursor_a->number < big_closer_value)
			{
				big_closer_value = cursor_a->number;
				target_node = cursor_a;
			}
			cursor_a = cursor_a->next;
		}
		if (big_closer_value == 2147483648)
			b->target = find_smallest_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	stack_b_setup(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
