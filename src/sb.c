/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:54:06 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/19 19:54:06 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	swap_b(t_list **stack_two)
{
	t_list 	*cursor;
	int		*tmp;

	if (*stack_two == NULL || (*stack_two)->next == NULL)
		return ;
	ft_printf("sb\n");
	cursor = *stack_two;
	cursor = (*stack_two)->next;
	tmp = (*stack_two)->content;
	(*stack_two)->content = cursor->content;
	cursor->content = tmp;
}
