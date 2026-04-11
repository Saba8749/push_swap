/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:51:26 by segribas          #+#    #+#             */
/*   Updated: 2026/04/11 19:08:14 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*current;
	t_node	*tmp;

	current = a->top;
	if (a->top == NULL || a->top->next == NULL)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*current;
	t_node	*tmp;

	current = b->top;
	if (b->top == NULL || b->top->next == NULL)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*tmp;
	t_node	*current_b;
	t_node	*tmp_b;

	current = a->top;
	if (a->top != NULL && a->top->next != NULL)
	{
		while (current->next->next != NULL)
			current = current->next;
		tmp = current->next;
		current->next = NULL;
		tmp->next = a->top;
		a->top = tmp;
	}
	current_b = b->top;
	if (b->top == NULL || b->top->next == NULL)
		return ;
	while (current_b->next->next != NULL)
		current_b = current_b->next;
	tmp_b = current_b->next;
	current_b->next = NULL;
	tmp_b->next = b->top;
	b->top = tmp_b;
	write(1, "rrr\n", 4);
}
