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

int	populate_a(t_stack **a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			return (1);
		number = ft_atol(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			return (1);
		if (check_duplicate(*a, (int)number))
			return (1);
		if (append_node(a, (int)number))
			return (1);
		i++;
	}
	return (0);
}

// We turn to long so we can check for overflows