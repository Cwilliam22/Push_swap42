/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:21:53 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/21 14:57:41 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	num;

	i = 1;
	cost = calculate_cost(i, find_place_b(stacks, stacks->stack_a[0]), stacks);
	place = 0;
	while (i < stacks->size_a)
	{
		num = stacks->stack_a[i];
		temp = calculate_cost(i, find_place_b(stacks, num), stacks);
		if (temp < cost)
		{
			cost = temp;
			place = i;
		}
		i++;
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
	push_b(stacks);
}

void	push_swap(t_stacks *stacks)
{
	push_b(stacks);
	push_b(stacks);
	while (stacks->size_a > 3)
	{
		sort(stacks);
	}
	/*if (stacks->size_a == 1)
		sort1(stacks);
	else if (stacks->size_a == 2)
		sort2(stacks);
	else
		sort3(stacks);*/
	push_back_to_stack_a(stacks);
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

