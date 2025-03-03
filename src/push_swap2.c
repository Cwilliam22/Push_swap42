/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:19:04 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/03 13:06:04 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_place_b(t_stacks *stacks, int num)
{
	int	i;
	int	max;
	int	min;

	max = 0;
	min = 0;
	i = 0;
	while (i < stacks->size_b)
	{
		if (stacks->stack_b[i] > stacks->stack_b[max])
			max = i;
		if (stacks->stack_b[i] < stacks->stack_b[min])
			min = i;
		i++;
	}
	//if (num > stacks->stack_b[max] || num < stacks->stack_b[min])
	//	return (max);
	
	if (num > stacks->stack_b[max])
	{
		if (max == stacks->size_b - 1)
			return (0);
		else
		return (max + 1);
	}
	else if (num < stacks->stack_b[min])
	{
		if (min == stacks->size_b - 1)
			return (0);
		else
		return (min + 1);
	}
	i = stacks->size_b - 1;
	while (i > 0)
	{
		if (num < stacks->stack_b[i] && num > stacks->stack_b[i - 1])
			return (i);
		i--;
	}
	return (i);
}

void up_num_ab4(t_stacks *stacks, int place_b)
{
	while (place_b > 0)
    {
        if (place_b <= stacks->size_b / 2)
        {
            rotate_b(stacks);
            place_b--;
        }
        else
        {
            reverse_rotate_b(stacks);
            place_b++;
        }
    }
}

void up_num_ab3(t_stacks *stacks, int place_a)
{
	while (place_a > 0)
    {
        if (place_a <= stacks->size_a / 2)
        {
            rotate_a(stacks);
            place_a--;
        }
        else
        {
            reverse_rotate_a(stacks);
            place_a++;
        }
    }
}

void up_num_ab2(t_stacks *stacks, int place_a, int place_b)
{
	while (place_a > 0 && place_b > 0 && place_a <= stacks->size_a / 2 && place_b <= stacks->size_b / 2)
    {
        rotate_ab(stacks);
        place_a--;
        place_b--;
    }
    while (place_a > 0 && place_b > 0 && place_a > stacks->size_a / 2 && place_b > stacks->size_b / 2)
    {
        reverse_rotate_ab(stacks);
        place_a++;
        place_b++;
    }
}

void up_num_ab1(t_stacks *stacks, int place_a, int place_b)
{
    if (place_a == 1 && place_b == 1)
    {
        swap_ab(stacks);
        place_a = 0;
        place_b = 0;
    }
    else if (place_a == 1)
    {
        swap_a(stacks);
        place_a = 0;
    }
    else if (place_b == 1)
    {
        swap_b(stacks);
        place_b = 0;
    }
	up_num_ab2(stacks, place_a, place_b);
	up_num_ab3(stacks, place_a);
	up_num_ab4(stacks, place_b);
}
