/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:10:20 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/18 16:02:03 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_LIB_H
# define PUSH_LIB_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"

int		dup_int(int	*array, int argc);
int		populate_stack_one(t_list **stack_one, int *stack_array, int argc);

#endif