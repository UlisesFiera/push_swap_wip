/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:59:45 by ulfernan          #+#    #+#             */
/*   Updated: 2025/02/10 16:44:20 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

long	ft_atol(const char *string)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (*string == ' ' || *string == '\t' || *string == '\n'
		|| *string == '\r' || *string == '\f' || *string == 'v')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (ft_isdigit(*string))
		number = number * 10 + (*string++ - '0');
	return (number * sign);
}
