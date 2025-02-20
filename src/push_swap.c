/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:21:53 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/20 16:57:31 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int calculate_cost(int num, int position, t_stacks stacks)
{
	int cost;

	return (cost);
}

int find_number(t_stacks stacks)
{
	int i;
	int price;
	int temp;
	int place;

	i = 0;
	price = calculate_cost(stacks->stack_a[i], i, stacks);
	place = 0;
	while (i < size_a)
	{
		temp = calculate_cost(stacks->stack_a[i], i, stacks);
		if (temp < cost)
		{
			cost = temp;
			place = i;
		}
		i++;
	}
	return (place);
}


// Push 2 premiers nombres de a vers b
void	push_swap(t_stacks stacks)
{
	int	i;

	i = 0;
	push_b(stacks);
	push_b(stacks);
	if (stacks->size_a <= 3)
	{
		sort3(stacks);
		while (i < stacks->size_b)
			push_a(stacks);
	}
}
