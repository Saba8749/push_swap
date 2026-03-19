/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saba <saba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:51:26 by segribas          #+#    #+#             */
/*   Updated: 2026/03/19 01:40:56 by saba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int tmp;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	write(1, "sa\n", 3);
}
void	sb(t_stack *b)
{
	int tmp;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	write(1,"sb\n", 3);
}
void	ss(t_stack *a, t_stack *b)
{
	int tmp;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	write(1, "ss\n", 3);
}
void	pb(t_stack *a, t_stack *b)
{
	push_node(b, pop_node(a));
	write(1, "pb\n", 3);
}
void	pa(t_stack *b, t_stack *a)
{
	push_node(a, pop_node(b));
	write(1, "pa\n", 3);
}
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
