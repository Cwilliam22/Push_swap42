/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:05:35 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/03 13:04:38 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
int cost_up_ab4(t_stacks *stacks, int place_b)
{
    int cost;
    
    cost = 0;
	while (place_b > 0)
    {
        if (place_b <= stacks->size_b / 2)
        {
            cost++;
            place_b--;
        }
        else
        {
            cost++;
            place_b++;
        }
    }
    return (cost);
}

int cost_up_ab3(t_stacks *stacks, int place_a)
{
    int cost;

    cost = 0;
	while (place_a > 0)
    {
        if (place_a <= stacks->size_a / 2)
        {
            cost++;
            place_a--;
        }
        else
        {
            cost++;
            place_a++;
        }
    }
    return (cost);
}

int cost_up_ab2(t_stacks *stacks, int place_a, int place_b)
{
    int cost;

    cost = 0;
	while (place_a > 0 && place_b > 0 && place_a <= stacks->size_a / 2 && place_b <= stacks->size_b / 2)
    {
        cost++;
        place_a--;
        place_b--;
    }
    while (place_a > 0 && place_b > 0 && place_a > stacks->size_a / 2 && place_b > stacks->size_b / 2)
    {
        cost++;
        place_a++;
        place_b++;
    }
    return (cost);
}

int cost_up_ab1(t_stacks *stacks, int place_a, int place_b)
{
    int cost;
    
    cost = 0;
    if (place_a == 1 && place_b == 1)
    {
        cost++;
        place_a = 0;
        place_b = 0;
    }
    else if (place_a == 1)
    {
        cost++;
        place_a = 0;
    }
    else if (place_b == 1)
    {
        cost++;
        place_b = 0;
    }
	cost += cost_up_ab2(stacks, place_a, place_b);
	cost += cost_up_ab3(stacks, place_a);
	cost += cost_up_ab4(stacks, place_b);
    return (cost);
}


void sort_b(t_stacks *stacks)
{
    int max;
    int place_max;
    int i;

    i = 0;
    max = stacks->stack_b[0];

    while (i < stacks->size_b)
    {
        if (stacks->stack_b[i] > max)
        {
            max = stacks->stack_b[i];
            place_max = i;
        }
        i++;
    }
    if (place_max <= stacks->size_b / 2)
    {
        while (stacks->stack_b[0] != max)
            rotate_b(stacks);
    }
    else
    {
        while (stacks->stack_b[0] != max)
            reverse_rotate_b(stacks);
    }
}

