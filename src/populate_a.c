/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:56:25 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/10 21:16:35 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	print_error(t_stack **a)
{
	ft_printf("Error\n");
	free_stack(a);
	exit (1);
}

void	populate_a(t_stack **a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			print_error(a);
		number = ft_atol(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			print_error(a);
		if (check_duplicate(*a, (int)number))
			print_error(a);
		if (append_node(a, (int)number))
			print_error(a);
		i++;
	}
}


// We turn to long so we can check for overflows