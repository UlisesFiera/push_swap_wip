/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:53:23 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/10 16:43:18 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	free_stack(t_stack **stack)
{
	t_stack		*tmp;
	t_stack		*cursor;

	if (!stack)
		return ;
	cursor = *stack;
	while (cursor)
	{
		tmp = cursor->next;
		free(cursor);
		cursor = tmp;
	}
	*stack = NULL;
}
