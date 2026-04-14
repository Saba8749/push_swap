/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:57:55 by segribas          #+#    #+#             */
/*   Updated: 2026/04/14 14:58:36 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	square_root(int value)
{
	int	i;

	i = 0;
	while (i * i <= value)
		i++;
	return (i - 1);
}

int	find_max(t_stack *b)
{
	t_node	*current;
	int		max_rank;
	int		max_value;
	int		count;

	current = b->top;
	max_rank = 0;
	max_value = current->value;
	count = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_rank = count;
		}
		count++;
		current = current->next;
	}
	return (max_rank);
}

int	get_moves(t_stack *b)
{
	int	max_rank;
	int	forward;
	int	reverse;

	if (!b)
		return (0);
	max_rank = find_max(b);
	forward = max_rank;
	reverse = stack_size(b) - max_rank;
	if (forward <= reverse)
		return (forward);
	return (-reverse);
}