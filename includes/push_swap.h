/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:55:39 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/27 13:23:02 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
	int	max_1;
	int	max_2;
	int	max_3;
}	t_stacks;

// checker.c
int		checks_conditions(char **tab_arg);
int		checks(int argc, char **argv);

// conditions.c
int		is_empty(char **tab_arg);
int		not_number(char **tab_arg);
int		int_max(char **tab_arg);
int		check_duplicate(char **tab_arg);
int		is_sorted(char **tab_arg);

// free.c
void	free_tab(char **tab_arg);
void	free_stacks(t_stacks *stacks);

// init.c
int		count_numbers(char *str);
char	*merge_str(int argc, char **argv);
int		init_stacks(int argc, char **argv, t_stacks *stacks);

// utils.c
long	ft_atol(const char *str);
char	*concat_args(int argc, char **argv);
void	find_max(t_stacks *stacks);
void	push_back_to_stack_a(t_stacks *stacks);

// stack_a.c
void	swap_a(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);

// stack_b.c
void	swap_b(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);

// stack_ab.c
void	swap_ab(t_stacks *stacks);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_ab(t_stacks *stacks);

// sort1.c
int		*copy_stack_a(t_stacks *stacks);
int		*bubble_sort(t_stacks *stacks);
int		number_to_index(t_stacks *stacks);
int		get_max_bits(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);

// sort2.c
int		find_min(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
int		is_array_a_sorted(t_stacks *stacks);

// main.c
void	two_to_five(t_stacks *stacks);
//void print_stacks(t_stacks *stacks);

#endif
