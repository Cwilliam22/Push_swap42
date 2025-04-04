/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:02:40 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/26 15:38:46 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	ft_putendl_fd(("sa"), 1);
}

void	push_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->stack_b[0];
	if (stacks->size_b == 0)
		return ;
	while (i < stacks->size_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_b--;
	stacks->size_a++;
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	ft_putendl_fd(("pa"), 1);
}

void	rotate_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	while (i < (stacks->size_a - 1))
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->size_a - 1] = temp;
	ft_putendl_fd(("ra"), 1);
}

void	reverse_rotate_a(t_stacks *stacks)
{
	int	temp;
	int	i;

	i = stacks->size_a - 1;
	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[stacks->size_a - 1];
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = temp;
	ft_putendl_fd(("rra"), 1);
}
