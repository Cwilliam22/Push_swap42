/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:03:15 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/26 16:12:38 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ab(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	ft_putendl_fd(("ss"), 1);
}

void	rotate_ab(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[0];
	while (i < (stacks->size_a - 1))
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
	i = 0;
	temp = stacks->stack_b[0];
	while (i < (stacks->size_b - 1))
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
	ft_putendl_fd(("rr"), 1);
}

void	reverse_rotate_ab(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->size_a - 1;
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	i = stacks->size_b - 1;
	temp = stacks->stack_b[i];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	ft_putendl_fd(("rrr"), 1);
}
