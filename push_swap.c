/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:54:43 by segribas          #+#    #+#             */
/*   Updated: 2026/04/15 16:22:01 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = (t_stack){NULL, 0};
	b = (t_stack){NULL, 0};
	if (parse(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (-1);
	}
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
