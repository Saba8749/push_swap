/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:43:44 by segribas          #+#    #+#             */
/*   Updated: 2026/04/14 16:09:23 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > third && third > second)
		ra(a);
	else if (second > first && second > third && first > third)
		rra(a);
	else if (first > second && first < third)
		sa(a);
	else if (first < third && second > third)
	{
		rra(a);
		sa(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (b->size < 2)
	{
		if (a->top->rank == 0 ||a->top->rank == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->top->rank < b->top->next->rank)
	{
		sb(b);
		pa(b, a);
		pa(b, a);
	}
}
