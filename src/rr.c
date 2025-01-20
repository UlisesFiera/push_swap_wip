/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:30:19 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:30:19 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	rotate_both(t_list **stack_one, t_list **stack_two)
{
	rotate_a(stack_one);
	rotate_b(stack_two);
}
