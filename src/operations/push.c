/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:26:43 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/04 10:26:43 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_lib.h"

void	push(t_stack **src, t_stack **dst, char *operation)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	if (!ft_strncmp(operation, "pa", 2))
		ft_printf("pa\n");
	if (!ft_strncmp(operation, "pb", 2))
		ft_printf("pb\n");
}
