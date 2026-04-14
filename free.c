/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:51:09 by segribas          #+#    #+#             */
/*   Updated: 2026/04/14 15:40:56 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **tokens, int argc)
{
	if (argc != 2)
		return ;
	int i;

	i = 0;
	while(tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_stack(t_stack *stack)
{
	t_node *current;
    t_node	*next;

	current = stack->top;
	while(current)
	{
        next = current->next;
        free(current);
        current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}