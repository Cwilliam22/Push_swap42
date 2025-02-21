/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:05:35 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/21 15:01:01 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int cost_up_ab2(t_stacks *stacks, int place_a, int place_b)
{
    int cost;

    cost = 0;
    if (place_a <= stacks->size_a / 2)
    {
        while (stacks->stack_a[0] != stacks->stack_a[place_a])
            cost++;
    }
    else
    {
        while (stacks->stack_a[0] != stacks->stack_a[place_a])
            cost++;
    }

    if (place_b <= stacks->size_b / 2)
    {
        while (stacks->stack_b[0] != stacks->stack_b[place_b])
            cost++;
    }
    else
    {
        while (stacks->stack_b[0] != stacks->stack_b[place_b])
            cost++;
    }
    return (cost);
}

int	cost_up_ab1(t_stacks *stacks, int place_a, int place_b)
{
    int cost;

    cost = 0;   
	if (place_a <= stacks->size_a / 2 && place_b <= stacks->size_b / 2)
	{
		while (stacks->stack_a[0] != stacks->stack_a[place_a] && 
			stacks->stack_b[0] != stacks->stack_b[place_b])
            cost++;
	}
	else if (place_a > stacks->size_a / 2 && place_b > stacks->size_b /2)
	{
		while (stacks->stack_a[0] != stacks->stack_a[place_a] && 
			stacks->stack_b[0] != stacks->stack_b[place_b])
			cost++;
	}
    cost = cost + cost_up_ab2(stacks, place_a, place_b);
    return (cost);
}
