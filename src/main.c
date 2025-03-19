/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:54 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/11 16:12:03 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	print_stacks(t_stacks *stacks)
{
	int	i;
	int	max_size;

	max_size = (stacks->size_a > stacks->size_b) ?
		stacks->size_a : stacks->size_b;
	printf("\n=======================\n");
	printf("      STACK_A  STACK_B\n");
	printf("=======================\n");
	i = 0;
	while (i < max_size)
	{
		if (i < stacks->size_a)
			printf("  %10d", stacks->stack_a[i]);
		else
			printf("           ");
		if (i < stacks->size_b)
			printf("  %10d\n", stacks->stack_b[i]);
		else
			printf("\n");
		i++;
	}
	printf("=======================\n\n");
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (1);
	stacks.size_a = 0;
	stacks.size_b = 0;
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.max_size = 0;
	stacks.max_1 = 0;
	stacks.max_2 = 0;
	stacks.max_3 = 0;
	if (!checks(argc, argv))
		return (1);
	if (!init_stacks(argc, argv, &stacks))
		return (free_stacks(&stacks), 1);
	if (stacks.size_a == 2 && stacks.stack_a[0] > stacks.stack_a[1])
		swap_a(&stacks);
	else if (stacks.size_a == 3)
		sort_three_elements(&stacks);
	else if (stacks.size_a >= 4 && stacks.size_a <= 5)
		sort_more_than_3_elements(&stacks);
	else
		radix_sort(&stacks);
	return (free_stacks(&stacks), 0);
}
