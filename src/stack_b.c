/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:03:21 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/26 15:40:44 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	ft_putendl_fd(("sb"), 1);
}

void	push_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->stack_a[0];
	if (stacks->size_a == 0)
		return ;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_a--;
	stacks->size_b++;
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	ft_putendl_fd(("pb"), 1);
}

void	rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	while (i < (stacks->size_b - 1))
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->size_b - 1] = temp;
	ft_putendl_fd(("rb"), 1);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->size_b - 1;
	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[stacks->size_b - 1];
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = temp;
	ft_putendl_fd(("rrb"), 1);
}
