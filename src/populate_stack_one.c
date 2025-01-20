/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:13:51 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/18 21:04:52 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	allocate_stack_two(t_list *stack_one, t_list **stack_two)
{
	t_list	*new_node;
	int		size;
	int		i;

	size = ft_lstsize(stack_one);
	i = 0;
	while (i < size - 1)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			free_list(stack_one);
			free_list(*stack_two);
			return (1);
		}
		new_node->content = NULL;
		new_node->next = NULL;
		ft_lstadd_back(stack_two, new_node);
		i++;
	}
	//ft_printf("one: %i\ntwo: %i\n", ft_lstsize(stack_one), ft_lstsize(*stack_two));
	return (0);
}

int	populate_stack_one(t_list **stack_one, int *stack_array, int argc, t_list **stack_two)
{
	t_list	*new_node;
	int		*number;
	int		i;

	number = malloc(sizeof(int));
	if (!number)
		return (1);
	*number = stack_array[0];
	(*stack_one)->content = number;
	i = 1;
	while (i < argc - 1)
	{
		number = malloc(sizeof(int));
		if (!number)
			return (1);
		*number = stack_array[i];
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			free(number);
			return (1);
		}
		new_node->next = NULL;
		new_node->content = number;
		ft_lstadd_back(stack_one, new_node);
		i++;
	}
	if (allocate_stack_two(*stack_one, stack_two))
		return (1);
	return (0);
}

// The parenthesis forces the order of operations. Without it, the operation would be *(stack_one->content), because -> is 
// "stronger" than *, so it's operation is done first, just like in math with * and - or +.
// (*stack_one)->content == access the value stack_one points to, which is a pointer to a struct (several pointers). 
// access then the memory address that "content" holds and change it to the memory addres that "number" holds
// *(stack_one->content) == access the value that the memory address of "content" points to.