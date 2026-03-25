/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saba <saba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 19:05:51 by saba              #+#    #+#             */
/*   Updated: 2026/03/25 03:14:29 by saba             ###   ########.fr       */
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