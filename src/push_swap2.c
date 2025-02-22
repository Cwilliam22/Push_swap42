/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:19:04 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/22 21:15:23 by wcapt            ###   ########.fr       */
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
	if (num > stacks->stack_b[max] || num < stacks->stack_b[min])
		return (max + 1);
	i = stacks->size_b - 1;
	while (i > 0)
	{
		if (num < stacks->stack_b[i] && num > stacks->stack_b[i - 1])
			return (i);
		i--;
	}
	return (i);
}

void up_num_ab2(t_stacks *stacks, int place_a, int place_b)
{
    if (place_a <= stacks->size_a / 2)
        rotate_a(stacks);
    else
        reverse_rotate_a(stacks);
    if (place_b <= stacks->size_b / 2)
        rotate_b(stacks);
	else
		reverse_rotate_b(stacks);
}

void up_num_ab1(t_stacks *stacks, int place_a, int place_b)
{
    if (place_a <= stacks->size_a / 2 && place_b <= stacks->size_b / 2)
        rotate_ab(stacks);
    else if (place_a > stacks->size_a / 2 && place_b > stacks->size_b / 2)
        reverse_rotate_ab(stacks);
    if (place_a == 1 && place_b == 1)
        swap_ab(stacks);
    else if (place_a == 1)
        swap_a(stacks);
    else if (place_b == 1)
        swap_b(stacks);

    cost_up_ab2(stacks, place_a, place_b);
}


void	push_back_to_stack_a(t_stacks *stacks)
{
	while (stacks->size_b > 0)
		push_a(stacks);
}
