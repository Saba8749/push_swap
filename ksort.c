/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:05:51 by saba              #+#    #+#             */
/*   Updated: 2026/04/15 14:26:29 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	int		counter;
	t_node	*current;
	t_node	*inner;

	counter = 0;
	current = a->top;
	while (current != NULL)
	{
		inner = a->top;
		while (inner != NULL)
		{
			if (inner->value < current->value)
				counter++;
			inner = inner->next;
		}
		current->rank = counter;
		counter = 0;
		current = current->next;
	}
}

void	k_sort1(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	count;

	chunk_size = get_chunk_size(a->size);
	count = 0;
	while (a->size > 0)
	{
		if (a->top->rank <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if (a->top->rank < count + chunk_size)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
}

void	k_sort2(t_stack *a, t_stack *b)
{
	int	moves;

	while (b->size > 0)
	{
		moves = get_moves(b);
		if (moves > 0)
		{
			while (moves-- > 0)
				rb(b);
		}
		else
		{
			moves = -moves;
			while (moves-- > 0)
				rrb(b);
		}
		pa(b, a);
	}
}
