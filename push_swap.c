/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saba <saba@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:54:43 by segribas          #+#    #+#             */
/*   Updated: 2026/03/25 03:31:58 by saba             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	t_stack a = {NULL, 0};
	t_stack b = {NULL, 0};
	(void)b;
	parse(&a, argc, argv);
	assign_ranks(&a);
	return (0);
}