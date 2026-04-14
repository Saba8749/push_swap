/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 01:47:06 by saba              #+#    #+#             */
/*   Updated: 2026/04/14 14:50:26 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack(t_stack *a, char **tokens)
{
	t_node	*current;
	t_node	*node;
	int		i;

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

char	**create_tokens(int argc, char **argv)
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
		return (free_tokens(tokens, argc), -1);
	if (create_stack(a, tokens))
		return (free_tokens(tokens, argc), -1);
	free_tokens(tokens, argc);
	if (duplicate_check(a))
		return (free_stack(a), -1);
	return (0);
}
