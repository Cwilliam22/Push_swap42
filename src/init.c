/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:18:17 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/20 13:59:53 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_numbers(char *str)
{
	int	num_arg;
	int	i;

	num_arg = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			num_arg++;
		i++;
	}
	num_arg++;
	return (num_arg);
}

char	*merge_str(int argc, char **argv)
{
	char	*str;

	if (argc > 2)
		str = concat_args(argc, argv);
	else
		str = argv[1];
	return (str);
}

int	init_stacks(int argc, char **argv, t_stacks *stacks)
{
	char	*str;
	char	**tab_number;
	int		num_count;
	int		i;

	str = merge_str(argc, argv);
	tab_number = ft_split(str, ' ');
	num_count = count_numbers(str);
	if (argc > 2)
		free(str);
	stacks->stack_a = malloc(sizeof(int) * num_count);
	stacks->stack_b = malloc(sizeof(int) * num_count);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks);
		return (0);
	}
	i = -1;
	while (++i < num_count)
		stacks->stack_a[i] = ft_atol(tab_number[i]);
	free_tab(tab_number);
	stacks->size_a = num_count;
	stacks->size_b = 0;
	stacks->max_size = num_count;
	return (1);
}
