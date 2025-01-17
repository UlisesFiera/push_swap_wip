/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:13:51 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/17 17:57:23 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	populate_stack_one(t_list **stack_one, int *stack_array, int argc)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		new_node = ft_lstnew(&stack_array[i]);
		ft_lstadd_back(stack_one, new_node);
		i++;
	}
}

// probar a eliminar el uso de argc y simplemente avanzar el puntero