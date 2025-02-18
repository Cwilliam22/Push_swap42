/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:18:35 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/18 15:28:37 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_stacks(char **tab_arg)
{
    if (!tab_arg)
        return;
    while (*tab_arg)
    {
        free (*tab_arg);
        tab_arg++;
    }
    free(tab_arg);
}

void    free_tab(t_stacks stacks)
{
    if (stacks->stack_a)
        free(stacks->stack_a);
    if (stacks->stack_b)
        free(stacks->stack_b);
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
}