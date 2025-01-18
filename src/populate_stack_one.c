/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:13:51 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/18 16:21:25 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	populate_stack_one(t_list **stack_one, int *stack_array, int argc)
{
	t_list	*list;
	t_list	*new_node;
	int		*number;
	int		i;

	i = 0;
	while (i < argc)
	{
		number = malloc(sizeof(int));
		if (!number)
			return (1);
		*number = stack_array[i];
		new_node = calloc(1, sizeof(t_list));
		if (!new_node)
		{
			free(number);
			return (1);
		}
		new_node->content = number;
		ft_lstadd_back(&list, new_node);
		free(number);
		i++;
	}
	*stack_one = list;
	return (0);
}

// The parenthesis forces the order of operations. Without it, the operation would be *(stack_one->content), because -> is 
// "stronger" than *, so it's operation is done first, just like in math with * and - or +.
// (*stack_one)->content == access the value stack_one points to, which is a pointer to a struct (several pointers). 
// access then the memory address that "content" holds and change it to the memory addres that "number" holds
// *(stack_one->content) == access the value that the memory address of "content" points to.