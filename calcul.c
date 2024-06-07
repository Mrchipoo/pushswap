/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:39 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/06 17:34:44 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

int	ft_min_ra(int i, int j, int target, int current)
{
	if (i > j)
	{
		if (current > target)
			return (-(j - 1));
		return (-j);
	}
	else
	{
		if (current > target)
			return ((i + 1));
		return (i);
	}
}

int	ft_min_rb(int i, int j)
{
	if (i == j)
		return (i);
	else if (i > j)
		return (-j);
	return (i);
}

long	ft_abs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_calculate_total(int arr[3])
{
	return (ft_abs(arr[0]) + ft_abs(arr[1]) + ft_abs(arr[2]));
}

int	median(t_walo *head)
{
	int	*arr;
	int	count;
	int	result;

	count = ft_lenght(head, 1, NULL);
	arr = ft_empty_array(head);
	if (arr == NULL)
		return (-1);
	ft_quicksort(arr, 0, count - 1);
	result = arr[count / 2];
	free(arr);
	return (result);
}
