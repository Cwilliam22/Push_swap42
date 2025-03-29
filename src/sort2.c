/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:55:11 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/28 15:40:47 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stacks *stacks)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stacks->stack_a[0];
	index = 0;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < min)
		{
			min = stacks->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && b < c && a < c)
		swap_a(stacks);
	else if (a > b && b > c)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stacks);
	else if (a < b && b > c && a < c)
	{
		swap_a(stacks);
		rotate_a(stacks);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stacks);
}

void	sort_four(t_stacks *stacks)
{
	int	min_index;

	min_index = find_min(stacks);
	if (min_index <= stacks->size_a / 2)
		while (min_index--)
			rotate_a(stacks);
	else
		while (min_index++ < stacks->size_a)
			reverse_rotate_a(stacks);
	push_b(stacks);
	sort_three(stacks);
	push_a(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int	min_index;

	min_index = find_min(stacks);
	if (min_index <= stacks->size_a / 2)
		while (min_index--)
			rotate_a(stacks);
	else
		while (min_index++ < stacks->size_a)
			reverse_rotate_a(stacks);
	push_b(stacks);
	sort_four(stacks);
	push_a(stacks);
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
