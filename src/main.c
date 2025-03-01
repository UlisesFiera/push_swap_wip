/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:03:15 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/26 16:44:04 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	print_error(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit (1);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	load_num(int argc, char **argv, t_stack **a)
{
	if (argc == 1 || !argv[1])
		exit (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (populate_a(a, argv))
		{
			free_split(argv);
			print_error(a);
		}
		free_split(argv);
	}
	else
		if (populate_a(a, argv + 1))
			print_error(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	load_num(argc, argv, &a);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			swap(&a, "sa");
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}

/*

void	prints(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("node %i value %i\n", i, a->number);
		i++;
		a = a->next;
	}
}

prints(a);

*/