/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulfernan <ulfernan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:10:20 by ulfernan          #+#    #+#             */
/*   Updated: 2025/01/14 10:19:55 by ulfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_LIB_H
# define PUSH_LIB_H

# include <unistd.h>
# include <stdlib.h>

# include "libft/libft.h"

typedef struct s_list
{
	char			*string;
	struct s_list	*next;
}					t_list;

#endif