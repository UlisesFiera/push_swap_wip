/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:32:07 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/20 00:32:07 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_lib.h"

void	reverse_rotate_both(t_list **stack_one, t_list **stack_two)
{
	reverse_rotate_a(stack_one);
	reverse_rotate_b(stack_two);
}
