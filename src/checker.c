/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:19:00 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/27 13:26:53 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checks_conditions(char **tab_arg)
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

int	checks(int argc, char **argv)
{
	char	**tab_arg;
	char	*string_arg;
	int		get_value;

	if (argc == 2)
		tab_arg = ft_split(argv[1], ' ');
	else
	{
		string_arg = concat_args(argc, argv);
		if (!string_arg)
			return (0);
		tab_arg = ft_split(string_arg, ' ');
		free(string_arg);
	}
	if (!tab_arg)
		return (0);
	get_value = checks_conditions(tab_arg);
	free_tab(tab_arg);
	if (get_value == 1)
		return (ft_putendl_fd(("Error"), 2), 0);
	else if (get_value == 2)
		return (0);
	return (1);
}
