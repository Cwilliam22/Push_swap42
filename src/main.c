/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:54 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/28 15:43:39 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	{
		free_stacks(&stacks);
		return (1);
	}
	push_swap(&stacks);
	free_stacks(&stacks);
	return (0);
}

/*
if (!push_swap(&stacks))
{
    free_stacks(&stacks);
    return (1);
}
Condition qui pourrait etre utile pour checker si la fonction echoue
*/