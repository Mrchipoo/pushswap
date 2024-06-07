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

void	ft_fill_lis(int **str, int **prev, int n)
{
	int	j;

	j = 0;
	*str = malloc(sizeof(int) * n);
	*prev = malloc(sizeof(int) * n);
	if (*prev == NULL || *str == NULL)
		return ;
	while (j < n)
	{
		(*str)[j] = 1;
		(*prev)[j] = -1;
		j++;
	}
}

void	ft_fill_lis2(int arr[], int *str, int *prev, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && str[j] + 1 > str[i])
			{
				str[i] = str[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_lis3(t_lis **liss, int *str, int n)
{
	int		i;
	int		max;
	int		index;

	i = 0;
	max = 0;
	while (i < n)
	{
		if (max < str[i])
		{
			max = str[i];
			index = i;
		}
		i++;
	}
	(*liss)->len = max;
	(*liss)->index = index;
}

void	ft_fill_lis4(t_lis *liss,int **squence, int arr[], int prev[])
{
	int pos;

	pos = liss->len - 1;
	*squence = malloc(sizeof(int) * (pos));
	if (*squence == NULL)
		return ;
	while (liss->index != -1)
	{
		(*squence)[pos] = arr[liss->index];
		pos--;
		liss->index = prev[liss->index];
	}
}

t_lis	*ft_fill_lis5(t_lis **liss, int *squence)
{	
	(*liss)->arr = squence;
	return (*liss);
}

t_lis	*ft_main_lis(int arr[], int n)
{
	int	*str;
	int	*prev;
	int	*squence;
	t_lis	*liss;

	liss = malloc(sizeof(t_lis));
	if (liss == NULL)
		return (NULL);
	ft_fill_lis(&str, &prev, n);
	if (str == NULL || prev == NULL)
		return (NULL);
	ft_fill_lis2(arr, str, prev, n);
	ft_fill_lis3(&liss, str, n);
	ft_fill_lis4(liss, &squence, arr, prev);
	if (squence == NULL)
		return (NULL);
	free(str);
	free(prev);
	return (ft_fill_lis5(&liss, squence));
}
