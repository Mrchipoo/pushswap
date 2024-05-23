/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/23 11:02:34 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

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
void	ft_array(walo *head)
{
	int	*arr;
	int	i;
	int count;
	walo *current;

	current = head;
	count = 0;
	i = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
		return ;
	while (head != NULL)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
	ft_quicksort(arr, 0, count - 1);
}
