/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:03:37 by williamcapt       #+#    #+#             */
/*   Updated: 2025/03/19 17:07:46 by wcapt            ###   ########.fr       */
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

/*
int	is_array_b_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_b - 1)
	{
		if (stacks->stack_b[i] < stacks->stack_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
*/

/*
static void	radix_sort_stack_b(t_stacks *stacks, int size_b, int bit_size, int j)
{
	while (size_b-- && j <= bit_size && !is_array_b_sorted(stacks))
	{
		if (((stacks->stack_b[0] >> j) & 1) == 0)
			rotate_b(stacks);
		else
			push_a(stacks);
	}
	if (is_array_b_sorted(stacks))
		while (stacks->size_b != 0)
			push_a(stacks);
}
*/

int shift_to_positive(t_stacks *stacks)
{
	int min;
	int i;

	min = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] < min)
			min = stacks->stack_a[i];
		i++;
	}
	if (min < 0)
	{
		i = 0;
		while (i < stacks->size_a)
		{
			stacks->stack_a[i] -= min;
			i++;
		}
	}
	return (min);
}

int get_max_bits(t_stacks *stacks)
{
	int max;
	int bits;

	max = stacks->stack_a[0];
	for (int i = 1; i < stacks->size_a; i++)
	{
		if (stacks->stack_a[i] > max)
			max = stacks->stack_a[i];
	}
	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void restore_original_values(t_stacks *stacks, int min)
{
	int i;
	
	i = 0;
	if (min < 0)
	{
		while (i < stacks->size_a)
		{
			stacks->stack_a[i] += min;
			i++;
		}
	}
}

void	radix_sort(t_stacks *stacks)
{
	int	j;
	int	bit_size;
	int	size;
	int	min;

	min = shift_to_positive(stacks);
	bit_size = get_max_bits(stacks);
	size = stacks->size_a - 1;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stacks->size_a;
		while (size-- && !is_array_a_sorted(stacks))
		{
			if (((stacks->stack_a[0] >> j) & 1) == 0)
				push_b(stacks);
			else
				rotate_a(stacks);
		}
		push_back_to_stack_a(stacks);
	}
	while (stacks->size_b != 0)
		push_a(stacks);
	restore_original_values(stacks, min);
	if (is_array_a_sorted(stacks))
		return ;
}
