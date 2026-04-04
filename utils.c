/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 02:14:16 by saba              #+#    #+#             */
/*   Updated: 2026/04/04 20:22:28 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	int			digit;
	long long	result;

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
	return ((int)(sign * result));
}
int	square_root(int value)
{
	int i;
	i = 0;

	while(i * i <= value)
		i++;
	return (i - 1);
}