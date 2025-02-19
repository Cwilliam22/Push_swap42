/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:03:15 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/19 20:31:36 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap_ab(t_stacks *stacks)
{
    swap_a(stacks);
    swap_b(stacks);
    ft_printf("ss \n");
}
void    rotate_ab(t_stacks *stacks)
{
    rotate_a(stacks);
    rotate_b(stacks);
    ft_printf("rr \n");
}

void    reverse_rotate_ab(t_stacks *stacks)
{
    reverse_rotate_a(stacks);
    reverse_rotate_b(stacks);
    ft_printf("rrr \n");
}