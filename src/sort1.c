/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:03:37 by williamcapt       #+#    #+#             */
/*   Updated: 2025/03/20 15:15:14 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*copy_stack_a(t_stacks *stacks)
{
	int	*sorted;
	int	i;

	i = 0;
	sorted = malloc(sizeof(int) * stacks->size_a);
	if (!sorted)
		return (NULL);
	while (i < stacks->size_a)
	{
		sorted[i] = stacks->stack_a[i];
		i++;
	}
	return (sorted);
}

int	*bubble_sort(t_stacks *stacks)
{
	int	*sorted;
	int	temp;
	int	i;
	int	j;

	i = 0;
	sorted = copy_stack_a(stacks);
	if (!sorted)
		return (NULL);
	while (i < (stacks->size_a - 1))
	{
		j = 0;
		while (j < (stacks->size_a - 1))
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

void	number_to_index(t_stacks *stacks)
{
	int	i;
	int	j;
	int	*sorted;

	i = 0;
	sorted = bubble_sort(stacks);
	if (!sorted)
		return ;
	while (i < stacks->size_a)
	{
		j = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[i] == sorted[j])
			{
				stacks->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

int	get_max_bits(t_stacks *stacks)
{
	int	max;
	int	bits;
	int	i;

	i = 1;
	max = stacks->stack_a[0];
	while (i < stacks->size_a)
	{
		if (stacks->stack_a[i] > max)
			max = stacks->stack_a[i];
		i++;
	}
	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stacks *stacks)
{
	int	j;
	int	bit_size;
	int	size;
	int	pushed;

	number_to_index(stacks);
	bit_size = get_max_bits(stacks);
	j = 0;
	while (j < bit_size)
	{
		size = stacks->size_a;
		pushed = 0;
		while (size--)
		{
			if (((stacks->stack_a[0] >> j) & 1) == 0)
			{
				push_b(stacks);
				pushed++;
			}
			else
				rotate_a(stacks);
		}
		while (pushed--)
			push_a(stacks);
		j++;
	}
}
