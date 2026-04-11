/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:15:41 by saba              #+#    #+#             */
/*   Updated: 2026/04/11 19:09:09 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
