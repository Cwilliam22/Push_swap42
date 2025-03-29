/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:00:00 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/27 12:53:40 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(char **tab_arg)
{
	while (*tab_arg)
	{
		if (**tab_arg != '\0')
			return (0);
		tab_arg++;
	}
	return (1);
}

int	not_number(char **tab_arg)
{
	int	i;
	int	j;

	i = 0;
	while (tab_arg[i])
	{
		j = 0;
		if (tab_arg[i][j] == '-' || tab_arg[i][j] == '+')
			j++;
		if (tab_arg[i][j] == '\0')
			return (0);
		while (tab_arg[i][j])
		{
			if (tab_arg[i][j] < 48 || tab_arg[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	int_max(char **tab_arg)
{
	long int	num;
	int			i;

	i = 0;
	while (tab_arg[i])
	{
		num = ft_atol(tab_arg[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(char **tab_arg)
{
	int	i;
	int	j;

	i = 0;
	while (tab_arg[i])
	{
		j = i + 1;
		while (tab_arg[j])
		{
			if (ft_atol(tab_arg[i]) == ft_atol(tab_arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **tab_arg)
{
	int	i;

	i = 0;
	while (tab_arg[i + 1])
	{
		if (ft_atol(tab_arg[i]) > ft_atol(tab_arg[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
