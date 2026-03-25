/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saba <saba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:51:26 by segribas          #+#    #+#             */
/*   Updated: 2026/03/21 18:17:22 by saba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node *current = a->top;
	t_node *tmp;
	while(current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "rra\n", 4);
}
void	rrb(t_stack *b)
{
	t_node *current = b->top;
	t_node *tmp;
	while(current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = b->top;
	b->top = tmp;
	write(1,"rrb\n", 4);
}
void	rrr(t_stack *a, t_stack *b)
{
	t_node *current = a->top;
	t_node *tmp;
	while(current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
	t_node *current_b = b->top;
	t_node *tmp_b;
	while(current_b->next->next != NULL)
		current_b = current_b->next;
	tmp_b = current_b->next;
	current_b->next = NULL;
	tmp_b->next = b->top;
	b->top = tmp_b;
	write(1,"rrr\n", 4);
}
