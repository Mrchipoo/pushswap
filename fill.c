/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:17:40 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/08 13:18:04 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

void	ft_before_cal(int *arr, int n, int len)
{
	arr[1] = ft_min_rb(n, len - n);
	arr[2] = 0;
	if (arr[0] >= 0 && arr[1] >= 0)
		ft_positive(arr);
	else if (arr[0] < 0 && arr[1] < 0)
		ft_negative(arr);
	else
		arr[2] = 0;
}

int	ft_after_cal(int *arr, int *temp)
{
	int	total;

	temp[0] = arr[0];
	temp[1] = arr[1];
	temp[2] = arr[2];
	total = ft_calculate_total(arr);
	return (total);
}
