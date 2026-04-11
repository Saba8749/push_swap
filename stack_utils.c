/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:55:52 by segribas          #+#    #+#             */
/*   Updated: 2026/04/11 19:06:22 by segribas         ###   ########.fr       */
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

// put given (popped) node into given stack
void	push_node(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

// pop top node from stack (removes node from stack)
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

// check if given stack is already sorted in ascending order
bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}
