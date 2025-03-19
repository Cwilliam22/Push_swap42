/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:38 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/11 13:16:54 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

static	int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

char	*concat_args(int argc, char **argv)
{
	char	*dest;
	char	*temp;
	int		i;

	dest = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		temp = dest;
		dest = ft_strjoin(dest, " ");
		if (!dest)
		{
			free(temp);
			return (NULL);
		}
		temp = dest;
		dest = ft_strjoin(dest, argv[i]);
		if (!dest)
		{
			free(temp);
			return (NULL);
		}
		i++;
	}
	return (dest);
}

void	find_max(t_stacks *stacks)
{
	int i;
	
	i = 0;
	stacks->max_3 = stacks->stack_a[0];
	while (stacks->stack_a[i])
	{
		if (stacks->stack_a[i] > stacks->max_3)
		{
			stacks->max_1 = stacks->max_2;
			stacks->max_2 = stacks->max_3;
			stacks->max_3 = stacks->stack_a[i];
		}
		else if (stacks->stack_a[i] < stacks->max_3 
			&& stacks->stack_a[i] > stacks->max_2)
		{
			stacks->max_1 = stacks->max_2;
			stacks->max_2 = stacks->stack_a[i];
		}
		else if (stacks->stack_a[i] < stacks->max_3 
			&& stacks->stack_a[i] < stacks->max_2 
			&& stacks->stack_a[i] > stacks->max_1)
			stacks->max_1 = stacks->stack_a[i];		
		i++;
	}

}

void	push_back_to_stack_a(t_stacks *stacks)
{
	while (stacks->size_b > 0)
		push_a(stacks);
}
