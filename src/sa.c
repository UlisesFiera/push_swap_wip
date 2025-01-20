/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/19 17:44:29 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	swap_a(t_list **stack_one)
{
	t_list 	*cursor;
	int		*tmp;

	if (*stack_one == NULL || (*stack_one)->next == NULL)
		return ;
	ft_printf("sa\n");
	cursor = *stack_one;
	cursor = (*stack_one)->next;
	tmp = (*stack_one)->content;
	(*stack_one)->content = cursor->content;
	cursor->content = tmp;
}
