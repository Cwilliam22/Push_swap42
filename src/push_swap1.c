/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:21:53 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/03 13:05:30 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort3(t_stacks *stacks)
{
	if (stacks->stack_a[0] == stacks->max_3 
		&& stacks->stack_a[1] == stacks->max_2)
	{
		rotate_a(stacks);
		swap_a(stacks);
	}
	else if (stacks->stack_a[0] == stacks->max_3 
		&& stacks->stack_a[1] == stacks->max_1)
		rotate_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_2 
		&& stacks->stack_a[1] == stacks->max_1)
		swap_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_2 
		&& stacks->stack_a[1] == stacks->max_3)
		reverse_rotate_a(stacks);
	else if (stacks->stack_a[0] == stacks->max_1 
		&& stacks->stack_a[1] == stacks->max_3)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
}

int	calculate_cost(int place_a, int place_b, t_stacks *stacks)
{
	int	cost;

	cost = cost_up_ab1(stacks, place_a, place_b);
	cost++;
	return (cost);
}

int	find_number(t_stacks *stacks)
{
	int	i;
	int	cost;
	int	temp;
	int	place;
	int	place_b;

	i = 0;
	place_b = find_place_b(stacks, stacks->stack_a[i]);
	cost = calculate_cost(i, place_b, stacks);
	place = i;
	while (++i < stacks->size_a - 3)
	{
		if (stacks->stack_a[i] == stacks->max_1 
			|| stacks->stack_a[i] == stacks->max_2 
			|| stacks->stack_a[i] == stacks->max_3)
			continue;
		place_b = find_place_b(stacks, stacks->stack_a[i]);
		temp = calculate_cost(i, place_b, stacks);
		if (temp < cost)
		{
			cost = temp;
			place = i;
		}
	}
	return (place);
}

void	sort(t_stacks *stacks)
{
	int	place_a;
	int	place_b;
	int	num;

	place_a = find_number(stacks);
	num = stacks->stack_a[place_a];
	place_b = find_place_b(stacks, num);
	up_num_ab1(stacks, place_a, place_b);
	if (stacks->size_a > 1)
		push_b(stacks);
}

void	push_swap(t_stacks *stacks)
{
	find_max(stacks);
	if (stacks->size_a == 2)
		swap_a(stacks);
	else if (stacks->size_a == 3)
		sort3(stacks);
	else
	{
		if (stacks->size_a > 3)
			push_b(stacks);
		if (stacks->size_a > 3)
			push_b(stacks);
		while (stacks->size_a > 3)
			sort(stacks);
		//ft_printf("size_a : %d\n", stacks->size_a);
		sort3(stacks);
		sort_b(stacks);
		if	(stacks->size_b > 0)
		push_back_to_stack_a(stacks);
	}
}

/*
-> Push 2 premiers nombres de A vers B (2x pb)
-> Fonction qui trouve le bon nombre a bouger de A a B
	-> Fonction qui trouve le bon emplacement (optimale) dans la stack B pour le nombre pointe a l'instant t
	-> Fonction qui evalue le nombre d'action du deplacement optimale
		-> Fonction qui evalue le nombre d'action pour metter le nombre en haut de la stack A
		-> Fonction qui evalue le nombre d'action pour preparer la stack B au push de A dans B
		-> Le nombre d'action + 1 (car pb a la fin)
-> Fonction qui fait le deplacement en appelant des fonctions identiques a celle d'avant sauf que cette fois-ci elle feront le mouvements necessaires
*/	

