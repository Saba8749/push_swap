/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:05:51 by saba              #+#    #+#             */
/*   Updated: 2026/04/04 20:56:34 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_ranks(t_stack *a)
{
	int counter = 0;
	t_node *current = a->top;
	t_node *inner;

	while (current != NULL)
	{
		counter = 0;
		inner = a->top;
		while (inner != NULL)
		{
			if (inner->value < current->value)
			counter++;
			inner = inner->next;
		}
		current->rank = counter;
		current = current->next;
	}
	
}

void k_sort1(t_stack *a, t_stack *b)
{
	int chunk_size;
	int pushed_elements;

	chunk_size = square_root(a->size) * 14 / 10;
	pushed_elements = 0;

	while(a->size > 0)
	{
		if(a->top->rank < pushed_elements + chunk_size)
		{
			pb(a, b);
			pushed_elements++;
		}
		else
			ra(a);
	}
}