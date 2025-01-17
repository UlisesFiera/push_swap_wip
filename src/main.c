/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:03:15 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/17 11:01:50 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	atoi_plus(char *argv)
{
	long long 	num;
	int			is_negative;
	int			i;

	negative = 0;
	i = 0;
	if (argv[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
}

int	stack_alloc(t_list **stack_one, t_list **stack_two)
{
	*stack_one = ft_calloc(1, sizeof(t_list));
	if (!*stack_one)
	{
		ft_printf("Error\n");
		return (1);
	}
	*stack_two = ft_calloc(sizeof(t_list));
	if (!*stack_two)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	error_check(int argc, char **argv)
{
	if (argc < 3)
		return (1);
}

int	char_to_int(char **argv, int **stack_array, int argc)
{
	// turn each command into an int and store it into the array
	int		i;
	int		j;
	int		*array;

	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (error_check(argc, argv))
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		array[i] = atoi_plus(argv[i + 1]); 
		i++;
	}
	*stack_array = array;
	return (0);
}

int	main(int argc, char **argv)
{
	t_list 	*stack_one;
	t_list 	*stack_two;
	int		*stack_array;

	if (stack_alloc(&stack_one, &stack_two))
		return (1);
	// turn each digit of the argv string into integers
	stack_array = malloc(sizeof(int) * (argc - 1));
	if (!stack_array)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (char_to_int(argv, &stack_array, argc))
		return (1);
	// arg check: error if no random number of integers only (not bigger or smaller), error if can't duplicate, prompt back if no params
	
	// free function needed to free each value (stack_array & array / )
	// the program must print just the instructions followed by \n
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

*/