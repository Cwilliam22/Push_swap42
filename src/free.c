/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:18:35 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/22 18:06:38 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(char **tab_arg)
{
	int	i;

	i = 0;
	if (!tab_arg)
		return ;
	while (tab_arg[i])
	{
		free (tab_arg[i]);
		i++;
	}
	free(tab_arg);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}
