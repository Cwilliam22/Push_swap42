/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:19:00 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/18 15:14:32 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int checks_conditions(char **tab_arg)
{
	if (is_empty(tab_arg))
		return (2);
	if (!not_number(tab_arg))
		return (1);
	if (!int_max(tab_arg))
		return (1);
	if (check_duplicate(tab_arg))
		return (1);
	if (is_sorted(tab_arg))
		return (2);
	return (0);
}

int checks(int argc, char **argv)
{
	char	**tab_arg;
	char	*string_arg;
	int		get_value;

	if (argc == 2)
		tab_arg = ft_split(argv[1], ' ');
	else
	{
		string_arg = concat_args(argc, argv);
		tab_arg = ft_split(string_arg, ' ');
		free(string_arg);
	}
	get_value = checks_conditions(tab_arg);
	free_tab(tab_arg);
	if (get_value == 1)
	{
		ft_printf("Error !/n");
		return (0);
	}
	else if (get_value == 2)
		return (0);
	return (1);
}
