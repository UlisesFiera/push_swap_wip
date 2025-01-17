/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:01:47 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/17 17:02:24 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

int	dup_int(int	*array, int argc)
{
	int	num;
	int	dup;
	int	i;
	int	j;

	i = 0;
	dup = 0;
	while (i < argc - 1)
	{
		num = array[i];
		j = 0;
		while (j < argc - 1)
		{
			if (array[j] == num)
				dup++;
			j++;
		}
		if (dup >= 2)
			return (1);	
		dup = 0;
		i++;
	}
	return (0);
}