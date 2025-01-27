/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:21:45 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/24 10:21:45 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	stack_size(t_list **stack)
{
	t_list	*cursor;
	int		size;
	
	if (!stack)
		return (-1);
	size = 0;
	cursor = *stack;
	while (cursor)
	{
		if (cursor->content)
			size++;
		cursor = cursor->next;
	}
	return (size);
}