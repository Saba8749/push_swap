/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:55:52 by segribas          #+#    #+#             */
/*   Updated: 2026/03/06 22:51:00 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_node(t_stack *stack, t_node *node)

{
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*pop_node(t_stack *stack)

{
	t_node	*node;

	node = stack->top;
	stack->top = node->next;
	stack->size--;
	return (node);
}

int	stack_size(t_stack *stack)

{
	return (stack->size);
}

int	is_sorted(t_stack *stack)

{
	t_node	*current;

	current = stack->top;
	while (current != NULL && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
