/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:47:06 by saba              #+#    #+#             */
/*   Updated: 2026/04/11 20:42:39 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicate_check(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (-1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int min_max_check(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (ft_atol(tokens[i]) > 2147483647)
			return (-1);
		if (ft_atol(tokens[i]) < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}

int create_stack(t_stack *a, char **tokens)
{
	t_node	*current;
	t_node	*node;
	int i;

	i = 0;
	current = a->top;
	while (tokens[i])
	{
		node = new_node(ft_atol(tokens[i]));
		if (!node)
			return (1);
		if (!a->top)
			a->top = node;
		else
			current->next = node;
		current = node;
		a->size++;
		i++;
	}
	return (0);
}

char **create_tokens(int argc, char **argv)
{
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	else
		return (&argv[1]);
}

int	parse(t_stack *a, int argc, char **argv)
{
	char	**tokens;

	tokens = create_tokens(argc, argv);
	if (min_max_check(tokens))
		return (-1);
	if (create_stack(a, tokens))
		return (free_tokens(tokens, argc), -1);
	free_tokens(tokens, argc);
	if (duplicate_check(a))
		return (free_stack(a), -1);
	return (0);
}
