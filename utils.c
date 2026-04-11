/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:14:16 by saba              #+#    #+#             */
/*   Updated: 2026/04/11 19:55:59 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	if (size == 0)
		return (len_src);
	while (*s != '\0' && i < size - 1)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	*d = '\0';
	return (len_src);
}

long	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	int			digit;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (sign * result);
}

int	square_root(int value)
{
	int	i;

	i = 0;
	while (i * i <= value)
		i++;
	return (i - 1);
}

int	find_max(t_stack *b)
{
	t_node	*current;
	int		max_rank;
	int		max_value;
	int		count;

	current = b->top;
	max_rank = 0;
	max_value = current->value;
	count = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_rank = count;
		}
		count++;
		current = current->next;
	}
	return (max_rank);
}

int	get_moves(t_stack *b)
{
	int	max_rank;
	int	forward;
	int	reverse;

	if (!b)
		return (0);
	max_rank = find_max(b);
	forward = max_rank;
	reverse = stack_size(b) - max_rank;
	if (forward <= reverse)
		return (forward);
	return (-reverse);
}
