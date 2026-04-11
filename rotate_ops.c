/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:16:18 by saba              #+#    #+#             */
/*   Updated: 2026/04/11 19:07:59 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*current;

	tmp = a->top;
	current = a->top;
	if (a->top == NULL || a->top->next == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	a->top = a->top->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*head;
	t_node	*tail;

	head = b->top;
	tail = b->top;
	if (b->top == NULL || b->top->next == NULL)
		return ;
	while (tail->next != NULL)
		tail = tail->next;
	b->top = b->top->next;
	tail->next = head;
	head->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	t_node	*current;
	t_node	*tmp_b;
	t_node	*current_b;

	tmp = a->top;
	current = a->top;
	tmp_b = b->top;
	current_b = b->top;
	if (a->top != NULL && a->top->next != NULL)
	{
		a->top = a->top->next;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		tmp->next = NULL;
	}
	if (b->top == NULL || b->top->next == NULL)
		return ;
	b->top = b->top->next;
	while (current_b->next != NULL)
		current_b = current_b->next;
	current_b->next = tmp_b;
	tmp_b->next = NULL;
	write(1, "rr\n", 3);
}
