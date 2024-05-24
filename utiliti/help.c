/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/23 22:38:21 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

int	ft_lenght(walo *head, int mode)
{
	int i;
	walo	*current;

	i = 0;
	current = head;
	if (mode == 1)
	{
		while (current != NULL)
		{
			current = current->next;
			i++;
		}
	}
	return (i);
}

int *ft_empty_array(walo *head)
{
	int	*arr;
	int i;
	int count;

	i = 0;
	count = ft_lenght(head,1);
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
		return NULL;
	while (head != NULL)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
	return (arr);
}

walo	*ft_find_biggest(walo *head)
{
	walo	*current;
	walo	*node;
	int	max;

	current = head->next;
	node = head;
	max = head->data;
	while (current != NULL)
	{
		if (max > current->data)
			current = current->next;
		else
		{
			max = current->data;
			node = current;
			current = current->next;
		}
	}
	return (node);
}

walo *ft_find_min(walo *head)
{
	int min;
	walo *node_min;

	min = head->data;
	while (head != NULL)
	{
		if (min > head->data)
		{
			min = head->data;
			node_min = head;
			head = head->next;
		}
		else
			head = head->next;
	}
	return (node_min);
}

int	ft_array(walo *head, int mode)
{
	int	*arr;
	int count;
	int	max;

	count = ft_lenght(head,1);
	arr = ft_empty_array(head);
	if (arr == NULL)
		return (-1);
	if (mode == 0)
	{
		ft_quicksort(arr, 0, count - 1);
		return (arr[count / 2]);
	}
	else if (mode  == 1)
	{
		max = ft_LIS(arr,count);
		if (max == -1)
			return (-1);
		return (max);
	}
	return (-1);
}

int ft_LIS(int arr[], int n)
{
	int	max;
	int	i;
	int	j;
	int	*LIS;

	max = 0;
	i = 0;
	LIS = malloc(sizeof(int) * n);
	if (LIS == NULL)
		return -1;
	while (i < n)
		LIS[i++] = 1;
	i = 1;
	while(i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && LIS[j] + 1 > LIS[i])
				LIS[i] = LIS[j] + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (max < LIS[i])
			max = LIS[i];
		i++;
	}
	return (max);
}
