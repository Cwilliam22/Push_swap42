/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:55:39 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/20 13:57:30 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	max_size;
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

// push_swap.c

#endif
