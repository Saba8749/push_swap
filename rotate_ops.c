/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saba <saba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:16:18 by saba              #+#    #+#             */
/*   Updated: 2026/03/21 18:16:59 by saba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node *tmp = a->top;
	t_node *current = a->top;
	a->top = a->top->next;
	while(current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
void	rb(t_stack *b)
{
	t_node *tmp = b->top;
	t_node *current = b->top;
	b->top = b->top->next;
	while(current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}
void	rr(t_stack *a, t_stack *b)
{
	t_node *tmp = a->top;
	t_node *current = a->top;
	a->top = a->top->next;
	while(current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	t_node *tmp_b = b->top;
	t_node *current_b = b->top;
	b->top = b->top->next;
	while(current_b->next != NULL)
		current_b = current_b->next;
	current_b->next = tmp_b;
	tmp_b->next = NULL;
	write(1, "rr\n", 3);
}