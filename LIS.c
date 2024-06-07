/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:55 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 15:49:44 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

void	ft_fill_lis(int **lis, int **prev, int n)
{
	int	j;

	j = 0;
	*lis = malloc(sizeof(int) * n);
	*prev = malloc(sizeof(int) * n);
	if (*prev == NULL || *lis == NULL)
		return ;
	while (j < n)
	{
		(*lis)[j] = 1;
		(*prev)[j] = -1;
		j++;
	}
}

void	ft_fill_lis2(int arr[], int *lis, int *prev, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_lis3(int **squence, int pos, int index, int arr[], int prev[])
{
	*squence = malloc(sizeof(int) * (pos + 1));
	if (*squence == NULL)
		return ;
	while (index != -1)
	{
		(*squence)[pos] = arr[index];
		pos--;
		index = prev[index];
	}
}

t_lis	*ft_fill_lis4(int *squence, int max)
{
	t_lis	*lis;

	lis = NULL;
	lis = malloc(sizeof(t_lis));
	if (lis == NULL)
		return (NULL);
	lis->arr = squence;
	lis->len = max;
	return (lis);
}

t_lis	*ft_main_lis(int arr[], int n)
{
	int	i;
	int	*lis;
	int	index;
	int	*prev;
	int	*squence;
	int	max;

	max = 0;
	ft_fill_lis(&lis, &prev, n);
	if (lis == NULL || prev == NULL)
		return (NULL);
	ft_fill_lis2(arr, lis, prev, n);
	i = 0;
	while (i < n)
	{
		if (max < lis[i])
		{
			max = lis[i];
			index = i;
		}
		i++;
	}
	ft_fill_lis3(&squence, max - 1, index, arr, prev);
	if (squence == NULL)
		return (NULL);
	free(lis);
	free(prev);
	return (ft_fill_lis4(squence, max));
}
