/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:03:15 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/18 21:01:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	free_all(t_list **stack_one, t_list **stack_two, int **stack_array)
{
	if (*stack_one)
	{
		free_list(*stack_one);
		*stack_one = NULL;
	}
	if (*stack_two)
	{
		free_list(*stack_two);
		*stack_two = NULL;
	}
	if (*stack_array)
	{
		free(*stack_array);
		*stack_array = NULL;
	}
}

int	atoi_plus(char *argv, int *array)
{
	long long 	num;
	int			is_negative;
	int			i;

	is_negative = 0;
	num = 0;
	i = 0;
	if (argv[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		num = num * 10 + (argv[i] - '0');
		i++;
	}
	if (is_negative)
		num = -num;
	if (num > 2147483647 || num < -2147483648)
		return (1);
	*array = num;
	return (0);
}

int	stack_alloc(t_list **stack_one, t_list **stack_two)
{
	*stack_one = malloc(sizeof(t_list));
	if (!*stack_one)
	{
		ft_printf("Error\n");
		return (1);
	}
	(*stack_one)->content = NULL;
	(*stack_one)->next = NULL;
	*stack_two = malloc(sizeof(t_list));
	if (!*stack_two)
	{
		free(*stack_one);
		ft_printf("Error\n");
		return (1);
	}
	(*stack_two)->content = NULL;
	(*stack_two)->next = NULL;
	return (0);
}

int	char_to_int(char **argv, int **stack_array, int argc)
{
	// turn each command into an int and store it into the array
	int		i;
	int		*array;

	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		if (atoi_plus(argv[i + 1], &array[i]))
		{
			free(array);
			return (1);
		}
		i++;
	}
	if (dup_int(array, argc))
	{
		free(array);
		return (1);
	}
	*stack_array = array;
	return (0);
}

void	print_stack(t_list *stack_one)
{
	static int i = 1;
	int j;
	t_list	*current;

	j = 0;
	current = stack_one;
	while (current != NULL)
	{
		if ((current->content) != NULL)
			ft_printf("stack[%i] digit[%i]: %d\n", i, j, *(int *)(current->content));
		current = current->next;
		j++;
	}
	i++;
}

int	main(int argc, char **argv)
{
	// turn each digit of the argv string into integers
	// arg check: error if no random number of integers only (not bigger or smaller), error if duplicate, prompt back if no params
	// the program must print just the instructions followed by \n
	// free function needed to free each value
	t_list 	*stack_one;
	t_list 	*stack_two;
	int		*stack_array;

	if (argc < 3)
		return (1);
	if (stack_alloc(&stack_one, &stack_two))
		return (1);
	stack_array = NULL;
	if (char_to_int(argv, &stack_array, argc))
	{
		free_all(&stack_one, &stack_two, &stack_array);
		ft_printf("Error\n");
		return (1);
	}
	if (populate_stack_one(&stack_one, stack_array, argc, &stack_two))
	{
		free_all(&stack_one, &stack_two, &stack_array);
		ft_printf("Error\n");
		return (1);
	}
	talgo(&stack_one, &stack_two);
	print_stack(stack_one);
	print_stack(stack_two);
	free_all(&stack_one, &stack_two, &stack_array);
	return (0);
}

/*

	Pointer lesson:
	
		A *pointer is a memory adress that contains another memory adress. Accessing it will return the value of the memory pointed.
		The & operand is a pointer to the memory adress of a variable. 
		The * operand is used to access the value of the pointer once this is declared. You can use it to change the value stored.

		*stack is a memory address (0x1) that points to an (unintialized) memory address of a random size.

		If we want it to point to an initialized memory address (0x9) of t_list size using a function:
			- We want to pass the memory address of *stack to the function to modify what the memory address contains.
				- If we'd pass just stack to a function that expects a *pointer, we'd be passing the value of *stack and a 
				  copy of (0x9), hence not modifying whatever the original (0x9) stores.
			- To do that, we use &stack. That gives us 0x9. We need to pass that to a function. In our case, &stack is a pointer
			  to the memory address of stack, which is a pointer. So a pointer to a pointer.
			- So, we have to declare a function that takes **pointers.
			- Within that function, we wanna change what (0x9) points to, which is (uninitialized).
				- If we worked with stack, we'd be working with literally (0x9), which doesn't make sense.
				- We wanna change what stack (0x9) points to, thats (uninitialized). And that is *stack.
				- Now we are esentially saying "uninitialized = 0x1" (a valid memory address).

	push_b(&stack_one, &stack_two);
	push_b(&stack_one, &stack_two);
	push_b(&stack_one, &stack_two);
	push_b(&stack_one, &stack_two);
	push_a(&stack_one, &stack_two);
	rotate_a(&stack_one);
	rotate_b(&stack_two);
	rotate_both(&stack_one, &stack_two);
	swap_a(&stack_one);
	swap_b(&stack_two);
	swap_both(&stack_one, &stack_two);
	reverse_rotate_a(&stack_one);
	reverse_rotate_b(&stack_one);
	reverse_rotate_both(&stack_one, &stack_two);
	print_stack(stack_one);
	print_stack(stack_two);

	for (int i = 0; i < argc - 1; i++)
	{
        ft_printf("%d ", stack_array[i]);
	}

*/