/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:11 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/20 14:55:31 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_elements(t_stacks *stacks)
{
	find_max(stacks);
	if (stacks->stack_a[0] == stacks->max_3
		&& stacks->stack_a[1] == stacks->max_2)
	{
		rotate_a(stacks);
		swap_a(stacks);
	}
	else if (stacks->stack_a[0] == stacks->max_3
		&& stacks->stack_a[1] == stacks->max_1)
		rotate_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_2
		&& stacks->stack_a[1] == stacks->max_1)
		swap_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_2
		&& stacks->stack_a[1] == stacks->max_3)
		reverse_rotate_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_1
		&& stacks->stack_a[1] == stacks->max_3)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
}

void	sort_more_than_3_elements(t_stacks *stacks)
{
	int size;
	
	size = stacks->size_a;
	find_max(stacks);
	while (size > 3)
	{
		if (stacks->stack_a[0] == stacks->max_1 ||
			stacks->stack_a[0] == stacks->max_2 ||
			stacks->stack_a[0] == stacks->max_3)
			rotate_a(stacks);
		else
		{
			push_b(stacks);
			size--;
		}
	}
	sort_three_elements(stacks);
	if (stacks->size_b == 2 && stacks->stack_b[0] < stacks->stack_b[1])
		swap_b(stacks);
	push_back_to_stack_a(stacks);
}

int	is_array_a_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
