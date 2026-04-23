/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:43:44 by segribas          #+#    #+#             */
/*   Updated: 2026/04/23 18:10:48 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	sa(a);
}

void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value
		&& a->top->value > a->top->next->next->value)
		ra(a);
	else if (a->top->next->value > a->top->value
		&& a->top->next->value > a->top->next->next->value)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	while (b->size < 1)
	{
		if (a->top->rank == 0)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(b, a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (b->size < 2)
	{
		if (a->top->rank == 0 || a->top->rank == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->top->rank < b->top->next->rank)
		sb(b);
	pa(b, a);
	pa(b, a);
}
