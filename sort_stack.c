/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:27:44 by segribas          #+#    #+#             */
/*   Updated: 2026/04/15 15:55:17 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	assign_ranks(a);
	if (a->size <= 5)
	{
		if (a->size == 2)
			sort_two(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size == 4)
			sort_four(a, b);
		else if (a->size == 5)
			sort_five(a, b);
	}
	else
	{
		k_sort1(a, b);
		k_sort2(a, b);
	}
}
