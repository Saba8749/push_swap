/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:54:43 by segribas          #+#    #+#             */
/*   Updated: 2026/04/11 20:37:49 by segribas         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (parse(&a, argc, argv))
	{
		printf("Error\n");
		free_stack(&a);
		return (-1);
	}
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	assign_ranks(&a);
	if (a.size <= 3)
	{
		if (a.size == 2)
			sort_two(&a);
		if (a.size == 3)
			sort_three(&a);
	}
	else
	{
		k_sort1(&a, &b);
		k_sort2(&a, &b);
	}
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	printf("Is not sorted 3\n");
	free_stack(&a);
	return (-1);
}
