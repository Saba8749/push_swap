/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:23:21 by segribas          #+#    #+#             */
/*   Updated: 2026/04/15 14:39:46 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate_check(t_stack *a)
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

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	min_max_check(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!is_digit(tokens[i]))
			return (-1);
		if (ft_atol(tokens[i]) > 2147483647 || ft_atol(tokens[i]) < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}
